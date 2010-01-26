/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  header_object.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26.01.2010 18:16:54
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (MSN:valerii76@hotmail.com)
 *                  valery.volgutov@lge.com
 *        Company:  LGERP St.Petersburg Lab
 *
 * =============================================================================
 */

#if !defined(__HEADER_OBJECT_H__)
#define __HEADER_OBJECT_H__

#include "m3gtypes.h"

// Header object
struct header_object : base_object
{
	static base_object* make()
	{
		return new header_object();
	}

	enum
	{
		object_type = 0,
	};

	header_object()
	{
		DEFINE_M3G_FARRAY(Byte, 2, "VersionNumber",
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Boolean, "hasExternalReferences", false,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(UInt32, "TotalFileSize", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(UInt32, "ApproximateContentSize", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(String, "AuthoringField", "",
			M3G_FILE_FORMAT_ALL);
	}

	template<class T>
	void traverse(T& op)
	{
		M3G_TYPE("VersionNumber", op);
		M3G_TYPE("hasExternalReferences", op);
		M3G_TYPE("TotalFileSize", op);
		M3G_TYPE("ApproximateContentSize", op);
		M3G_TYPE("AuthoringField", op);
	}

	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(base_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(base_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(base_object, "Header", out, indent, version);
	}
	virtual int class_type()
	{
		return OBJ_CLASS_HEADER;
	}
};

#endif//__HEADER_OBJECT_H__
