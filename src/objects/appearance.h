/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  appearance.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/26/2010 09:10:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined (__APPEARANCE_H__)
#define __APPEARANCE_H__

#include "appearance_base.h"

// Appearance
struct appearance_object : appearance_base_object
{
	static base_object* make()
	{
		return new appearance_object();
	};

	enum
	{
		object_type = 3,
	};

	appearance_object()
	{
		DEFINE_M3G_TYPE(ObjectIndex, "fog", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(ObjectIndex, "pointSpriteMode", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(ObjectIndex, "material", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_VARRAY(ObjectIndex, "textures",
			M3G_FILE_FORMAT_ALL);
	}

	template<class T>
	void traverse(T &op)
	{
		M3G_TYPE("fog", op);
		if (op.version == M3G_FILE_FORMAT_20)
			M3G_TYPE("pointSpriteMode", op);
		else
			M3G_TYPE("polygonMode", op);
		M3G_TYPE("material", op);
		M3G_TYPE("textures", op);
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(appearance_base_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(appearance_base_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(appearance_base_object, "Appearance",
			out, indent, version);
	}
};

#endif//__APPEARANCE_H__
