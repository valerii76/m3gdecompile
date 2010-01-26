/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  background.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/26/2010 10:14:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined (__BACKGROUND_H__)
#define __BACKGROUND_H__

#include "object3d.h"

// Backgroud
struct background_object : object3d_object
{
	static base_object* make()
	{
		return new background_object();
	}

	enum
	{
		object_type = 4,
	};

	background_object()
	{
		DEFINE_M3G_TYPE(ColorRGBA, "backgroundColor", ColorRGBA(),
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(ObjectIndex, "backgroundImage", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Byte, "backgroundImageModeX", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Byte, "backgroundImageModeY", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Int32, "cropX", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Int32, "cropY", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Int32, "cropWidth", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Int32, "cropHeight", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Boolean, "depthClearEnabled", false,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Float32, "depth", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Int32, "stencil", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Int32, "stencilClearMask", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(ColorRGBA, "colorClearMask", ColorRGBA(),
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Boolean, "colorClearEnabled", false,
			M3G_FILE_FORMAT_10);
	}

	template<class T>
	void traverse(T &op)
	{
		M3G_TYPE("backgroundColor", op);
		M3G_TYPE("backgroundImage", op);
		M3G_TYPE("backgroundImageModeX", op);
		M3G_TYPE("backgroundImageModeY", op);
		M3G_TYPE("cropX", op);
		M3G_TYPE("cropY", op);
		M3G_TYPE("cropWidth", op);
		M3G_TYPE("cropHeight", op);
		M3G_TYPE("depthClearEnabled", op);
		M3G_TYPE("depth", op);
		M3G_TYPE("stencil", op);
		M3G_TYPE("stencilClearMask", op);
		M3G_TYPE("colorClearMask", op);
		M3G_TYPE("colorClearEnabled", op);
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
		PRINT_TEMPLATE(object3d_object, "Background",
			out, indent, version);
	}
};

#endif//__BACKGROUND_H__
