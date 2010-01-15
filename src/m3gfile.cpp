/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  m3gfile.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/14/2010 08:28:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */

#include "m3gfile.h"
#include <vector>

#include "m3gformat.h"
#include "stream.h"

//==============================================================================
//==============================================================================
Byte m3g_file_identifier[12] =
{
	0xab, 0x4a, 0x53, 0x52, 0x31, 0x38, 0x34, 0xbb, 0x0d, 0x0a, 0x1a, 0x0a
};

static int m3g_error = M3G_SUCCESS;

enum
{
	M3G_COMPRESSION_SCHEME_UNCOMPRESSED = 0,
	M3G_COMPRESSION_SCHEME_ZLIB = 1,
};

struct section_head
{
	Byte compression_scheme;
	UInt32 total_section_length;
	UInt32 uncompression_length;
};

struct section_tail
{
	Int32 checksum;
};

struct object_head
{
	Byte object_type;
	UInt32 length;
};

//==============================================================================
//==============================================================================
template<class T>
void read(Stream& strm, T* data);

template<>
void read(Stream& strm, section_head* data)
{
	strm.read(&data->compression_scheme);
	strm.read(&data->total_section_length);
	strm.read(&data->uncompression_length);

	printf("compression scheme: %d\n", data->compression_scheme);
	printf("total section length: %d\n", data->total_section_length);
	printf("uncompression length: %d\n", data->uncompression_length);
}

template<>
void read(Stream& strm, section_tail* data)
{
	strm.read(&data->checksum);
}

template<>
void read(Stream& strm, object_head* data)
{
	strm.read(&data->object_type);
	strm.read(&data->length);

	printf("object type: %d\n", data->object_type);
	printf("length: %d\n", data->length);
}

template<>
void read(Stream& strm, header_section* data)
{
	strm.read(&data->version_number);
	strm.read(&data->has_external_references);
	strm.read(&data->total_file_size);
	strm.read(&data->approximate_content_size);
	strm.read(&data->authoring_field);

	printf("version: %d.%d\n", data->version_number[0],
		data->version_number[1]);
	printf("external refs: %d\n", data->has_external_references);
	printf("total file size: %d\n", data->total_file_size);
	printf("approximate context size: %d\n",
		data->approximate_content_size);
	printf("authoring field: %s\n", data->authoring_field.c_str());
}

//==============================================================================
//==============================================================================
int m3g_last_error()
{
	return m3g_error;
}

char* m3g_error_string(int error)
{
	return NULL;
}

//==============================================================================
//==============================================================================
int m3g_check_file(char const* file_name)
{
	Stream strm(file_name);
	/* check m3g file identifier */
	{
		std::vector<Byte> id;
		strm.read_array(&id, 12);
		if (strm.error_code() != STREAM_SUCCESS ||
			memcmp(&id.front(), m3g_file_identifier, 12))
		{
			m3g_error = M3G_INVALID_FILE_IDENTIFIER;
			return M3G_FALSE;
		}
	}
	/* read head section */
	{
		section_head sh;
		section_tail st;
		object_head oh;
		header_section hs;
		read(strm, &sh);
		read(strm, &oh);
		read(strm, &hs);
		read(strm, &st);
	}

	return M3G_TRUE;
}

int m3g_check_data(char const* data, int size)
{
    return 0;
}


