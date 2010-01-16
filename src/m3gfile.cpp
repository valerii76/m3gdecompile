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

	if (strm.error_code() != STREAM_SUCCESS)
		return;
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

	if (strm.error_code() != STREAM_SUCCESS)
		return;
	printf("object type: %d\n", data->object_type);
	printf("length: %d\n", data->length);
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
int check_m3g_file_identifier(Stream& strm)
{
	std::vector<Byte> id;
	strm.read_array(&id, 12);
	if (strm.error_code() != STREAM_SUCCESS ||
		memcmp(&id.front(), m3g_file_identifier, 12))
	{
		m3g_error = M3G_INVALID_FILE_IDENTIFIER;
		return M3G_FALSE;
	}
	return M3G_TRUE;
}

int load_section(Stream& strm)
{
	section_head sh;
	section_tail st;
	object_head oh;

	read(strm, &sh);
	if (strm.error_code() != STREAM_SUCCESS)
		return M3G_FALSE;

	std::vector<Byte> objects;
	strm.read_array(&objects, sh.total_section_length - 13);
	if (strm.error_code() != STREAM_SUCCESS)
		return M3G_FALSE;

	/* read objects */
	{
		Stream obj_strm((char*)&objects.front(), objects.size(),
			sh.compression_scheme == M3G_COMPRESSION_SCHEME_ZLIB ?
				STREAM_COMPRESSED : STREAM_UNCOMPRESSED);
		while (obj_strm.error_code() == STREAM_SUCCESS)
		{
			read(obj_strm, &oh);

			if (obj_strm.error_code() != STREAM_SUCCESS)
				break;

			make_t obj_make = create_object[oh.object_type];
			if (obj_make)
			{
				base_object* obj = obj_make();
				obj->load(obj_strm);
				obj->print(stdout);
			}
			else
			{
				std::vector<Byte> skip;
				obj_strm.read_array(&skip, oh.length);
			}
		}
	}

	read(strm, &st);
	if (strm.error_code() != STREAM_SUCCESS)
		return M3G_FALSE;

	return M3G_TRUE;
}


int m3g_check_file(char const* file_name)
{
	Stream strm(file_name);
	/* check m3g file identifier */
	if (!check_m3g_file_identifier(strm))
		return M3G_FALSE;
	/* read head section */
	while(strm.error_code() == STREAM_SUCCESS)
	{
		load_section(strm);
	}

	return M3G_TRUE;
}

int m3g_check_data(char const* data, int size)
{
    return 0;
}


