/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  base.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26.01.2010 18:32:04
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined(__BASE_H__)
#define __BASE_H__

#include "m3gtypes.h"
#include "stream.h"

enum
{
	OBJ_CLASS_HEADER = 0,
	OBJ_CLASS_EXT_REF,
	OBJ_CLASS_EXT_IMG,
	OBJ_CLASS_EXT_OBJ,
	OBJ_CLASS_OBJECT3D,
};

struct operation_load
{
	int size;
	Stream &strm;
	int version;
	operation_load(Stream& _strm, int _version)
		: size(0)
		, strm(_strm)
		, version(_version)
	{}

	void operator() (m3g_base_type* o)
	{
		size += o->load(strm, version);
	}
};
struct operation_print
{
	operation_print(FILE *_out, std::string const &_indent, int _version)
		: out(_out)
		, version(_version)
		, indent(_indent)
	{
	}

	void operator () (m3g_base_type* o)
	{
		o->print(out, indent, version);
	}

	FILE *out;
	std::string indent;
	int version;
};
struct operation_save
{
	int size;
	Stream &strm;
	int version;
	operation_save(Stream& _strm, int _version)
		: size(0)
		, strm(_strm)
		, version(_version)
	{}

	void operator() (m3g_base_type* o)
	{
		size += o->save(strm, version);
	}
};

struct base_object
	: m3g_base_type
{
	static base_object* make(int obj_type);
	virtual int class_type() = 0;
};

#define LOAD_TEMPLATE(base, strm, version) \
	operation_load op(strm, version); \
	op.size += base::load(strm, version); \
	traverse(op); \
	return op.size;

#define SAVE_TEMPLATE(base, strm, version) \
	operation_save op(strm, version); \
	op.size += base::save(strm, version); \
	traverse(op); \
	return op.size;

#define PRINT_TEMPLATE(base, name, out, indent, version) \
	operation_print op(out, indent + "\t", version); \
	fprintf(out, "%s%s\n%s{\n", indent.c_str(), name, indent.c_str()); \
	base::print(out, indent + "\t", version); \
	traverse(op); \
	fprintf(out, "%s}\n", indent.c_str());

#endif//__BASE_H__

