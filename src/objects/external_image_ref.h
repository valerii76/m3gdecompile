/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  external_image_ref_object.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26.01.2010 18:22:41
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (MSN:valerii76@hotmail.com)
 *                  valery.volgutov@lge.com
 *        Company:  LGERP St.Petersburg Lab
 *
 * =============================================================================
 */
#if !defined(__EXTERNAL_IMAGE_REF_H__)
#define __EXTERNAL_IMAGE_REF_H__

// External image reference
struct external_image_ref_object : external_ref_object
{
	static base_object* make()
	{
		return new external_image_ref_object();
	}

	enum
	{
		object_type = 0xfe,
	};

	external_image_ref_object()
	{
		DEFINE_M3G_TYPE(Int32, "format", IMAGEBASE_RGBA,
			M3G_FILE_FORMAT_20);
	}

	template<class T>
	void traverse(T op)
	{
		M3G_TYPE("format", op);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(external_ref_object, strm, version);
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(external_ref_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(external_ref_object, "ExternalImageReference",
			out, indent, version);
	}
	virtual int class_type()
	{
		return OBJ_CLASS_EXT_IMG;
	}
};

#endif//__EXTERNAL_IMAGE_REF_H__
