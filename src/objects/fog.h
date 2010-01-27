/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  fog.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27.01.2010 13:15:20
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */

#if !defined (__FOG_H__)
#define __FOG_H__

#include "object3d.h"

// Fog
struct fog_object : object3d_object
{
	static base_object* make()
	{
		return new fog_object();
	}
	enum
	{
		object_type = 7,
	};

	fog_object()
	{
		DEFINE_M3G_TYPE(ColorRGB, "color", ColorRGB(),
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Byte, "mode", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Float32, "density", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Float32, "near", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Float32, "far", 0,
			M3G_FILE_FORMAT_ALL);
	}

	template<class T>
	void traverse(T &op)
	{
		Byte mode;
		M3G_TYPE("color", op);
		M3G_TYPE("mode", op);
		mode = M3G_TYPE_CAST("mode", Byte);
		if (mode == FOG_EXPONENTIAL ||
			(mode == FOG_EXPONENTIAL_SQUARED &&
			op.version == M3G_FILE_FORMAT_20))
		{
			M3G_TYPE("density", op);
		}
		else
		{
			M3G_TYPE("near", op);
			M3G_TYPE("far", op);
		}
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(object3d_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(object3d_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(object3d_object, "Fog",
			out, indent, version);
	}
};

#endif//__FOG_H__
