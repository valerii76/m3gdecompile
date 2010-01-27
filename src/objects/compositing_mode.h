/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  compositing_mode.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27.01.2010 12:59:35
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined (__COMPOSITING_MODE_H__)
#define __COMPOSITING_MODE_H__

#include "object3d.h"

// CompositionMode
struct composition_mode_object : object3d_object
{
	static base_object* make()
	{
		return new composition_mode_object();
	}
	enum
	{
		object_type = 6,
	};

	composition_mode_object()
	{
		DEFINE_M3G_TYPE(Boolean, "depthTestEnabled", false,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Boolean, "depthWriteEnabled", false,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Boolean, "colorWriteEnabled", false,
			M3G_FILE_FORMAT_10);
		DEFINE_M3G_TYPE(Boolean, "alphaWriteEnabled", false,
			M3G_FILE_FORMAT_10);
		DEFINE_M3G_TYPE(Byte, "blending", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Byte, "alphaThreshold", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Float32, "depthOffsetFactor", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Float32, "depthOffsetUnits", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(UInt16, "depthTest", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(UInt16, "alphaTest", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(ObjectIndex, "blender", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(ObjectIndex, "stencil", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(ColorRGBA, "colorWriteMask", ColorRGBA(),
			M3G_FILE_FORMAT_20);
	}

	template<class T>
	void traverse(T &op)
	{
		M3G_TYPE("depthTestEnabled", op);
		M3G_TYPE("depthWriteEnabled", op);
		M3G_TYPE("colorWriteEnabled", op);
		M3G_TYPE("alphaWriteEnabled", op);
		M3G_TYPE("blending", op);
		M3G_TYPE("alphaThreshold", op);
		M3G_TYPE("depthOffsetFactor", op);
		M3G_TYPE("depthOffsetUnits", op);
		M3G_TYPE("depthTest", op);
		M3G_TYPE("alphaTest", op);
		M3G_TYPE("blender", op);
		M3G_TYPE("stencil", op);
		M3G_TYPE("colorWriteMask", op);
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
		PRINT_TEMPLATE(object3d_object, "CompositingMode",
			out, indent, version);
	}
};

#endif//__COMPOSITING_MODE_H__
