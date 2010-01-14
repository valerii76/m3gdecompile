/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  m3gfile.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2010 09:12:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>
#include <malloc.h>
#include "m3gfile.h"
#include "memory.h"

typedef unsigned char	Byte;
typedef char		SByte;
typedef short		Int16;
typedef unsigned short	UInt16;
typedef long		Int32;
typedef unsigned long	UInt32;
typedef float		Float32;
typedef short		Float16;	//FIXME: NEED TO HALF-PERCISION FLOAT
typedef unsigned char	Boolean;
typedef unsigned char*	String;

struct Vector3D
{
	Float32	x;
	Float32	y;
	Float32	z;
};

struct Matrix
{
	Float32 v[16];
};

struct ColorRGB
{
	Byte red;
	Byte green;
	Byte blue;
};

struct ColorRGBA
{
	Byte red;
	Byte green;
	Byte blue;
	Byte alpha;
};

typedef UInt32		ObjectIndex;
typedef UInt32		ForwardIndex;

#define M3G_TRUE	1
#define M3G_FALSE	0

typedef int (*read_data)(void*, void*);

static int m3g_error_code;

static Byte m3g_file_identificator[12] = {
	0xAB, 0x4A, 0x53, 0x52, 0x31, 0x38, 0x34, 0xBB, 0x0D, 0x0A, 0x1A, 0x0A
};

/******************************************************************************/
/******************************************************************************/
static inline void set_error_code(int ecode)
{
	m3g_error_code = ecode;
}

static inline int read_byte(void* src, void* v)
{
	memcpy(v, src, 1);
	return 1;
}

static inline int read_sbyte(void* src, void* v)
{
	memcpy(v, src, 1);
	return 1;
}

static inline int read_int16(void* src, void* v)
{
	memcpy(v, src, 2);
	return 2;
}

static inline int read_uint16(void* src, void* v)
{
	memcpy(v, src, 2);
	return 2;
}

static inline int read_int32(void* src, void* v)
{
	memcpy(v, src, 4);
	return 4;
}

static inline int read_uint32(void* src, void* v)
{
	memcpy(v, src, 4);
	return 4;
}

static inline int read_float32(void* src, void* v)
{
	memcpy(v, src, 4);
	return 4;
}

static inline int read_float16(void* src, void* v)
{
	memcpy(v, src, 2);
	return 2;
}

static inline int read_string(void* src, void* v)
{
	int size = 0;
	Byte* curr = (Byte*)src;
	Byte* value = (Byte*)v;

	while (curr[size]) 
	{
		value[size] = curr[size];
		++size;
	}
	value[size] = 0;

	return size;
}

static inline int read_boolean(void* src, void* v)
{
	memcpy(v, src, 1);
	return 1;
}

static inline int read_vector3d(void* src, void* v)
{
	memcpy(v, src, 12);
	return 12;
}

static inline int read_matrix(void* src, void* v)
{
	memcpy(v, src, 64);
	return 64;
}

static inline int read_color_rgb(void* src, void* v)
{
	memcpy(v, src, 12);
	return 12;
}

static inline int read_color_rgba(void* src, void* v)
{
	memcpy(v, src, 16);
	return 16;
}

static inline int read_object_index(void* src, void* v)
{
	memcpy(v, src, 4);
	return 4;
}

static inline int read_forward_index(void* src, void* v)
{
	memcpy(v, src, 4);
	return 4;
}

static inline int read_varray(void* src, void* data, read_data rfunc)
{
	UInt32 count;
	int size = 0;
	int i = 0;
	Byte* curr = (Byte*)src;
	Byte* dst = (Byte*)data;
	size += read_uint32(src, &count);
	for(; i < count; ++i) 
	{
		int readed = rfunc(curr, dst);
		curr += readed;
		dst += readed;
		size += readed;
	}
	return size;
}

static inline int read_array(void* src, void* data, int n, read_data rfunc)
{
	Byte* curr = (Byte*)src;
	Byte* dst = (Byte*)data;
	int size = 0;
	while(n--)
	{
		int readed = rfunc(curr, dst);
		curr += readed;
		dst += readed;
		size += readed;
	}
	return size;
}

/******************************************************************************/
/******************************************************************************/
int m3g_check_file(char* file_name)
{
	int result = M3G_FALSE;
	FILE* file = fopen(file_name, "rb");
	if (file)
	{
		char* data;
		int fsize = 0;
		fseek(file, 0, SEEK_END);
		fsize = ftell(file);
		fseek(file, 0, SEEK_SET);

		data = (char*)malloc(fsize);
		fread(data, fsize, 1, file);

		result = m3g_check_data(data);

		free(data);
	}
	return result;
}

/******************************************************************************/
/******************************************************************************/
static int read_section_head(
		  void* data
		, Byte* compression_scheme
		, UInt32* total_section_length
		, UInt32* uncompressed_length)
{
	int size = 0;
	size += read_byte(data, compression_scheme);
	size += read_uint32(data + size, total_section_length);
	size += read_uint32(data + size, uncompressed_length);

	printf("CompressionScheme: %d\n", *compression_scheme);
	printf("TotalSectionLength: %d\n", *total_section_length);
	printf("UncompressedLength: %d\n", *uncompressed_length);

	return size;
}

static int read_object_head(void* data, Byte* object_type, UInt32* length)
{
	int size = 0;

	size += read_byte(data, object_type);
	size += read_uint32(data+size, length);

	printf("ObjectType: %d\n", object_type);
	printf("Length: %d\n", length);

	return size;
}

static int read_section_tail(char* data, Int32* checksum)
{
	read_int32(data, checksum);
	printf("Checksum: 0x%x\n", *checksum);
	return 4;
}

static int read_file_header(char* data)
{
	Byte version_number[2];
	Boolean has_exernal_refereces;
	UInt32 total_file_size;
	UInt32 approximate_content_size;
	String authoring_field;

	int size = 0;

	size += read_array(data, version_number, 2, read_byte);
	size += read_boolean(data + size, &has_exernal_refereces);
	size += read_uint32(data + size, &total_file_size);
	size += read_uint32(data + size, &approximate_content_size);
	size += read_string(data + size, &authoring_field);

	printf("Version: %d.%d\n", version_number[0], version_number[1]);
	printf("HasExternalReferences: %d\n", has_exernal_refereces);
	printf("TotalFileSize: %d\n", total_file_size);
	printf("ApproximateContentSize: %d\n", approximate_content_size);
	printf("AuthoringField: %s\n", authoring_field);

	return size;
}

int m3g_check_data(char* data)
{
	int offset = 0;
	/* reset m3g error code */
	m3g_error_code = M3G_SUCCESS;
	/* check file identificator */
	{
		Byte id[12];
		offset += read_array(data, id, 12, read_byte);
		if(memcmp(id, m3g_file_identificator, 12))
		{
			set_error_code(M3G_INVALID_FILE_IDENTIFIER);
			return M3G_FALSE;
		}
	}
	printf("***Offset: %d\n", offset);
	/* read file header section*/
	{
		printf("Header section\n");
		Byte compression_scheme;
		UInt32 total_section_length;
		UInt32 uncompressed_length;
		Int32 checksum;
		Byte object_type;
		UInt32 length;

		offset += read_section_head(data + offset,
			&compression_scheme,
			&total_section_length,
			&uncompressed_length);
		printf("***Offset: %d\n", offset);
		offset += read_object_head(data + offset,
			&object_type, &length);
		printf("***Offset: %d\n", offset);
		offset += read_file_header(data + offset);
		printf("***Offset: %d\n", offset);
		offset += read_section_tail(data + offset, &checksum);
		printf("Header section done\n");
	}

	return M3G_TRUE;
}
