/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  stream.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/25/2010 09:58:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#include "stream.h"

template<>
inline int Stream::read(String* value)
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

