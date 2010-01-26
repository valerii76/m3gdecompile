/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  external_ref_object.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26.01.2010 18:19:50
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (MSN:valerii76@hotmail.com)
 *                  valery.volgutov@lge.com
 *        Company:  LGERP St.Petersburg Lab
 *
 * =============================================================================
 */
#if !defined(__EXTERNAL_REF_OBJECT_H__)
#define __EXTERNAL_REF_OBJECT_H__

// External reference
struct external_ref_object : base_object
{
	static base_object* make()
	{
		return new external_ref_object();
	}
	enum
	{
		object_type = 0xff,
	};

	external_ref_object()
	{
		DEFINE_M3G_TYPE(String, "URI", "", M3G_FILE_FORMAT_ALL);
	}

	template<class T>
	void traverse(T& op)
	{
		M3G_TYPE("URI", op);
	}

	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(base_object, strm, version);
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(base_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(base_object, "ExternalReference", out,
			indent, version);
	}
	virtual int class_type()
	{
		return OBJ_CLASS_EXT_REF;
	}
};

#endif//__EXTERNAL_REF_OBJECT_H__
