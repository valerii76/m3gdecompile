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
#include <stdio.h>

#include "m3gformat.h"

class FileStream
{
public:
	FileStream(std::string file_name)
		:file(fopen(file_name.c_str(), "rb"))
	{}

	~FileStream()
	{
		fclose(file);
	}

	template<class T>
	int read(T* value)
	{
		return fread(value, sizeof(T), 1, file);
	}

	template<class T>
	int read_array(std::vector<T>* value, int count)
	{
		int size = 0;
		for (int i = 0; i < count; ++i)
		{
			T v;
			int readed = fread(&v, sizeof(T), 1, file);
			size += readed;
			value->push_back(v);
		}
		return size;
	}

	template<class T>
	int read_varray(std::vector<T>* value)
	{
		int size = 0;
		UInt32 count = 0;
		size += fread(&count, sizeof(UInt32), 1, file);
		size += read_array(value, count);
		return size;
	}

private:
	FILE* file;
};

template<>
int FileStream::read(StringUTF8* value)
{
	Byte v;
	int size = 0;
	size += fread(&v, 1, 1, file);
	if(v)
	{
		while (v)
		{
			value->push_back(v);
			size += fread(&v, 1, 1, file);
		}
	}
	return size;
}

int m3g_check_file(char const* file_name)
{
	int result = M3G_FALSE;

	FileStream strm(file_name);

	return result;
}

int m3g_check_data(char const* data)
{
    return 0;
}


