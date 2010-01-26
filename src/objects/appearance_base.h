/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  appearance_base.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/26/2010 09:02:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined (__APPEARANCE_BASE_H__)
#define __APPEARANCE_BASE_H__

#include "objects/object3d.h"

// AppearanceBase
struct appearance_base_object : object3d_object
{
	appearance_base_object()
	{
		DEFINE_M3G_TYPE(Byte, "layer_20", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(SByte, "layer_10", 0,
			M3G_FILE_FORMAT_10);
		DEFINE_M3G_TYPE(ObjectIndex, "compositingMode", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(ObjectIndex, "polygonMode", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Boolean, "isDepthSortEnabled", false,
			M3G_FILE_FORMAT_20);
	}

	template<class T>
	void traverse(T &op)
	{
		M3G_TYPE("layer_20", op);
		M3G_TYPE("layer_10", op);
		M3G_TYPE("compositingMode", op);
		if (op.version == M3G_FILE_FORMAT_20)
		{
			M3G_TYPE("polygonMode", op);
			M3G_TYPE("isDepthSortEnabled", op);
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
		PRINT_TEMPLATE(object3d_object, "AppearanceBase",
			out, indent, version);
	}
};


#endif//__APPEARANCE_BASE_H__
