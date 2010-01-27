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

struct m3g_file_objects
{
	int file_version;
	header_object* header;
	lst_objects_t objects;
	lst_ext_refs_t ext_refs;
	lst_ext_img_refs_t img_refs;
	lst_ext_obj_refs_t obj_refs;
	lst_all_objects_t all_objs;

	m3g_file_objects()
		:file_version(M3G_FILE_FORMAT_10)
		,header(NULL)
	{
	}

	~m3g_file_objects()
	{
		for (lst_all_objects_t::iterator i(all_objs.begin()),
			end(all_objs.end()); i != end; ++i)
			delete *i;
	}

	void print_all(FILE* out)
	{
		for (lst_all_objects_t::iterator i(all_objs.begin()),
			end(all_objs.end()); i != end; ++i)
			(*i)->print(out, "", file_version);
	}

	void push_back(base_object* obj)
	{
		all_objs.push_back(obj);
		if (obj->class_type() == OBJ_CLASS_HEADER)
		{
			header = dynamic_cast<header_object*>(obj);
			if (header->version_number[0] == 2)
				file_version = M3G_FILE_FORMAT_20;
		}
		else if (obj->class_type() == OBJ_CLASS_OBJECT3D)
			objects.push_back(dynamic_cast<object3d_object*>(obj));
		else if (obj->class_type() == OBJ_CLASS_EXT_REF)
			ext_refs.push_back(
				dynamic_cast<external_ref_object*>(obj));
		else if (obj->class_type() == OBJ_CLASS_EXT_IMG)
			img_refs.push_back(
				dynamic_cast<external_image_ref_object*>(obj));
		else if (obj->class_type() == OBJ_CLASS_EXT_OBJ)
			obj_refs.push_back(
				dynamic_cast<external_object_ref_object*>(obj));
	}
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
	std::vector<Byte> file_id;
	strm.read_array(&file_id, 12);
	if (strm.error_code() != STREAM_SUCCESS ||
		memcmp(&file_id.front(), m3g_file_identifier, 12))
	{
		m3g_error = M3G_INVALID_FILE_IDENTIFIER;
		return M3G_FALSE;
	}
	return M3G_TRUE;
}

int load_section(Stream& strm, m3g_file_objects& objs)
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

	// skip section
	if (sh.uncompression_length == 0)
	{
		read(strm, &st);
		return M3G_TRUE;
	}

	/* read objects */
	Stream obj_strm((char*)&objects.front(), objects.size(),
		sh.compression_scheme == M3G_COMPRESSION_SCHEME_ZLIB ?
			STREAM_COMPRESSED : STREAM_UNCOMPRESSED);
	while (obj_strm.error_code() == STREAM_SUCCESS)
	{
		read(obj_strm, &oh);

		if (obj_strm.error_code() != STREAM_SUCCESS)
			break;

		base_object* obj = base_object::make(oh.object_type);
		if (obj)
		{
			obj->load(obj_strm, objs.file_version);
			objs.push_back(obj);
		}
		else
		{
			std::vector<Byte> skip;
			obj_strm.read_array(&skip, oh.length);
		}
	}

	read(strm, &st);
	if (strm.error_code() != STREAM_SUCCESS)
		return M3G_FALSE;

	return M3G_TRUE;
}


int m3g_check_file(char const* file_name)
{
	m3g_file_objects objs;
	Stream strm(file_name);
	/* check m3g file identifier */
	if (!check_m3g_file_identifier(strm))
		return M3G_FALSE;
	/* read head section */
	while(strm.error_code() == STREAM_SUCCESS)
	{
		load_section(strm, objs);
	}

	objs.print_all(stdout);

	return M3G_TRUE;
}

int m3g_check_data(char const* data, int size)
{
    return 0;
}


