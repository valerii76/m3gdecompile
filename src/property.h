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
#if !defined (__PROPERTY_H__)
#define __PROPERTY_H__

#include "m3gtypes.h"
#include "type_props.h"
#include "stream.h"
#include <map>

struct m3g_base_type;
typedef std::map<std::string, m3g_base_type*> lst_fields_t;

template<class T>
struct get_type
{
	typedef T type;
};
template<class T>
struct get_type<T*>
{
	typedef T type;
};

template<class T, int l>
struct gen_type
{
	typedef T type[l];
};
template<class T>
struct gen_type<T, 0>
{
	typedef T type;
};

template<class T, int len = 0>
struct m3g_type
	: m3g_base_type
{

	m3g_type(std::string const &_name, int _version)
		: m3g_base_type(_name, _version)
	{
	}

	m3g_type(std::string const &_name, int _version, T default_value)
		: m3g_base_type(_name, _version)
		, value(default_value)
	{
	}

	virtual void print(FILE *out, std::string const &indent, int version);
	virtual int load(Stream &strm, int version);
	virtual int save(Stream &strm, int version);


	typename gen_type<T, len>::type value;
	enum
	{
		ARRAY_SIZE = len,
	};
};

#define DEFINE_M3G_TYPE(type, name, default_value, version) \
	fields[name] = (new m3g_type<type>(name, version, default_value))

#define DEFINE_M3G_FARRAY(type, len, name, version) \
	fields[name] = (new m3g_type<type, len>(name, version))

#define DEFINE_M3G_VARRAY(type, name, version) \
	fields[name] = (new m3g_type< std::vector<type> >(name, version))

#define M3G_TYPE(name, op) \
	op(fields[name])

#define M3G_TYPE_CAST(name, type) \
	dynamic_cast< m3g_type< type, 0 >* >(fields[name])->value
#define M3G_TYPE_CAST_ARRAY(name,  type, len) \
	dynamic_cast< m3g_type< type, len >* >(fields[name])->value

#define M3G_TYPE_CAST_OBJ(name, type, obj) \
	dynamic_cast< m3g_type< type, 0 >* >(obj->fields[name])->value
#define M3G_TYPE_CAST_ARRAY_OBJ(name, type, len, obj) \
	dynamic_cast< m3g_type< type, len >* >(obj->fields[name])->value


template<class T, int len>
struct m3g_type_print
{
	static void print(FILE *out,
		std::string const &indent,
		m3g_type<T, len> *v)
	{
		print_array(out, indent.c_str(),
			v->name.c_str(), v->value, len);
	}
};
template<class T>
struct m3g_type_print<T, 0>
{
	static void print(FILE *out,
		std::string const &indent,
		m3g_type<T, 0> *v)
	{
		print_value(out, indent.c_str(),
			v->name.c_str(), v->value);
	}
};
template<class T, int len>
struct m3g_type_read
{
	static int read(Stream &strm, m3g_type<T, len> *v)
	{
		return strm.read_fix_array(v->value, len);
	}
};
template<class T>
struct m3g_type_read<T, 0>
{
	static int read(Stream &strm, m3g_type<T, 0> *v)
	{
		return strm.read(&v->value);
	}
};

template<class T, int len>
struct m3g_type_write
{
	static int write(Stream &strm, m3g_type<T, len> *v)
	{
		//return strm.write_fix_array(v->value, len);
		return 0;
	}
};
template<class T>
struct m3g_type_write<T, 0>
{
	static int write(Stream &strm, m3g_type<T, 0> *v)
	{
		//return strm.write(&v->value);
		return 0;
	}
};

template<class T, int len>
inline void m3g_type<T, len>::print(FILE *out, std::string const &indent,
	int version)
{
	if (version_support & version)
		m3g_type_print<T, len>::print(out, indent, this);
}
template<class T, int len>
inline int m3g_type<T, len>::load(Stream &strm, int version)
{
	if (version_support & version)
		return m3g_type_read<T, len>::read(strm, this);
	return 0;
}
template<class T, int len>
inline int m3g_type<T, len>::save(Stream &strm, int version)
{
	if (version_support & version)
		return m3g_type_write<T, len>::write(strm, this);
	return 0;
}


#endif//__PROPERTY_H__

