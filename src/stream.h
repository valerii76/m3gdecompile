/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  Stream.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/15/2010 06:40:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined(__STREAM_H__)
#define __STREAM_H__

#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <vector>
#include <string>
#include <zlib.h>

#include "exceptions.h"

enum
{
	STREAM_SUCCESS = 0,
	STREAM_FILE_NOT_OPEN,
	STREAM_FILE_READ_ERROR,
	STREAM_MEMORY_READ_OUT_OF_BOUND,
	STREAM_MEMORY_NO_DATA,
	STREAM_END,
};

enum
{
	STREAM_COMPRESSED = 0,
	STREAM_UNCOMPRESSED,
};

class StreamReader
{
public:
	StreamReader()
		: error_code(STREAM_SUCCESS)
	{}

	int error()
	{
		return error_code;
	}

	virtual int read(char* data, int size) = 0;

protected:
	int error_code;
};

class FileStreamReader
	:public StreamReader
{
public:
	FileStreamReader(char const* file_name)
	{
		file = fopen(file_name, "rb");
		if (file == NULL)
		{
			error_code = STREAM_FILE_NOT_OPEN;
			throw file_not_open(file_name);
		}
	}
	~FileStreamReader()
	{
		if (file != NULL)
			fclose(file);
	}

	virtual int read(char* data, int size)
	{
		int ret = 0;
		if (error_code != STREAM_SUCCESS || size == 0)
			return 0;
		ret = fread(data, 1, size, file);
		if (ret != size && !feof(file))
		{
			error_code = STREAM_FILE_READ_ERROR;
			throw file_read_error();
		}
		if (feof(file))
			error_code = STREAM_END;
		return ret;
	}

private:
	FILE* file;
};

class MemoryStreamReader
	: public StreamReader
{
public:
	MemoryStreamReader(char* _data, int _size, int mode)
		:curr(0)
		,data(0)
		,total_size(0)
	{
		if (mode == STREAM_UNCOMPRESSED)
		{
			data = _data;
			total_size = _size;
		}
		else if (mode == STREAM_COMPRESSED)
		{
			int const CHUNK = 8192;
			z_stream strm;
			unsigned char out[CHUNK];
			int ret;
			unsigned have;

			strm.zalloc = Z_NULL;
			strm.zfree = Z_NULL;
			strm.opaque = Z_NULL;
			strm.avail_in = 0;
			strm.next_in = Z_NULL;
			ret = inflateInit(&strm);
			if (ret != Z_OK)
			{
				error_code = STREAM_MEMORY_NO_DATA;
				throw memory_no_data();
				return;
			}

			strm.avail_in = _size;
			strm.next_in = (unsigned char*)_data;

			do
			{
				strm.avail_out = CHUNK;
				strm.next_out = out;

				ret = inflate(&strm, Z_NO_FLUSH);
				if (ret == Z_NEED_DICT
					|| ret == Z_DATA_ERROR
					|| ret == Z_MEM_ERROR)
				{
					inflateEnd(&strm);
					error_code = STREAM_MEMORY_NO_DATA;
					throw memory_data_corrupt();
					return;
				}
				have = CHUNK - strm.avail_out;

				if (have)
				{
					char* tmp = data;
					int tmp_size = total_size;
					total_size += have;
					data = (char*)malloc(total_size);
					if (tmp)
						memcpy(data, tmp, tmp_size);
					memcpy(data + tmp_size, out, have);
					if (tmp)
						free(tmp);
				}

			} while (strm.avail_out == 0);
			inflateEnd(&strm);
		}
	}

	virtual int read(char* _data, int _size)
	{
		int readed = _size;
		if (_size > (total_size - curr))
		{
			readed = total_size - curr;
			error_code = STREAM_MEMORY_READ_OUT_OF_BOUND;
			throw memory_read_out_of_bound();
			return 0;
		}
		memcpy(_data, data + curr, readed);
		curr += readed;
		if (curr >= total_size)
			error_code = STREAM_END;
		return readed;
	}

private:
	char* data;
	int total_size;
	int curr;
};

class Stream
{
public:
	Stream(char const* file_name)
	{
		impl = new FileStreamReader(file_name);
	}

	Stream(char* data, int size, int mode)
	{
		impl = new MemoryStreamReader(data, size, mode);
	}

	int error_code()
	{
		return impl->error();
	}

	template<class T>
	int read(T* value)
	{
		return impl->read((char*)value, sizeof(T));
	}

	template<class T>
	int read_array(std::vector<T>* value, int count)
	{
		int size = 0;
		for (int i = 0; i < count; ++i)
		{
			T v;
			int readed = impl->read((char*)&v, sizeof(T));
			size += readed;
			value->push_back(v);
		}
		return size;
	}

	template<class T>
	int read_fix_array(T* value, int count)
	{
		int size = 0;
		for (int i = 0; i < count; ++i)
		{
			int readed = impl->read((char*)&value[i], sizeof(T));
			size += readed;
		}
		return size;
	}

	template<class T>
	int read_varray(std::vector<T>* value)
	{
		int size = 0;
		UInt32 count = 0;
		size += impl->read((char*)&count, sizeof(UInt32));
		size += read_array(value, count);
		return size;
	}


private:
	StreamReader* impl;
};

template<>
inline int Stream::read(StringUTF8* value)
{
	Byte v;
	int size = 0;
	size += impl->read((char*)&v, sizeof(Byte));
	while (v)
	{
		value->push_back(v);
		size += impl->read((char*)&v, sizeof(Byte));
	}
	return size;
}

#endif//__STREAM_H__
