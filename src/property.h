/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  property.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22.01.2010 17:02:14
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (MSN:valerii76@hotmail.com)
 *                  valery.volgutov@lge.com
 *        Company:  LGERP St.Petersburg Lab
 *
 * =============================================================================
 */
#if !(defined) __PROPERTY_H__
#define __PROPERTY_H__

#include "type_props.h"
#include "stream.h"
#include <vector>

struct m3g_type_base;
typedef std::vector<m3g_base_type*> lst_fields_t;

struct m3g_type_base
{
	lst_fields_t fields;
	void print(FILE *out) = 0;
	void read(Stream &strm) = 0;
	void write(Stream &strm) = 0;
};

template<class T>
struct m3g_type
{
	void print(FILE *out);
	void read(Stream &strm);
	void write(Stream &strm);

	T value;
};

void DEFINE_M3G_TYPE(type, name)





#endif//__PROPERTY_H__

