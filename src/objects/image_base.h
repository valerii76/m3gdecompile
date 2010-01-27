/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  image_base.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27.01.2010 13:32:28
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */

#if !defined(__IMAGE_BASE_H__)
#define __IMAGE_BASE_H__

#include "object3d.h"

// ImageBase
struct image_base_object : object3d_object
{
	image_base_object()
	{
		DEFINE_M3G_TYPE(Int32, "format_20", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Byte, "format_10", 0,
			M3G_FILE_FORMAT_10);
		DEFINE_M3G_TYPE(Boolean, "isMutable", false,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(UInt32, "width", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(UInt32, "height", 0,
			M3G_FILE_FORMAT_ALL);
	}

	template<class T>
	void traverse(T &op)
	{
		M3G_TYPE("format_20", op);
		M3G_TYPE("format_10", op);
		M3G_TYPE("isMutable", op);
		M3G_TYPE("width", op);
		M3G_TYPE("height", op);
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
		PRINT_TEMPLATE(object3d_object, "ImageBase",
			out, indent, version);
	}
};


#endif//__IMAGE_BASE_H__

