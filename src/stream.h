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
#include <memory.h>

enum
{
	STREAM_SUCCESS = 0,
	STREAM_FILE_NOT_OPEN,
	STREAM_FILE_READ_ERROR,
	STREAM_MEMORY_READ_OUT_OF_BOUND,
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
			error_code = STREAM_FILE_NOT_OPEN;
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
		ret = fread(data, size, 1, file);
		if (ret != 1)
			error_code = STREAM_FILE_READ_ERROR;
		return ret;
	}

private:
	FILE* file;
};

class MemoryStreamReader
	: public StreamReader
{
public:
	MemoryStreamReader(char* _data, int _size)
		:data(_data)
		,total_size(_size)
		,curr(0)
	{}

	virtual int read(char* _data, int _size)
	{
		int readed = _size;
		if (data == 0 || _size == 0 || error_code != STREAM_SUCCESS)
			return 0;
		if (_size > (total_size - curr))
		{
			readed = total_size - curr;
			error_code = STREAM_MEMORY_READ_OUT_OF_BOUND;
		}
		memcpy(_data, data + curr, readed);
		curr += readed;
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

	Stream(char* data, int size)
	{
		impl = new MemoryStreamReader(data, size);
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
	int read_array(T* value, int count)
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
int Stream::read(StringUTF8* value)
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
