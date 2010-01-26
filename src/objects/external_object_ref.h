/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  external_object_ref_object.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26.01.2010 18:25:10
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined(__EXTERNAL_OBJECT_REF_OBJECT_H__)
#define __EXTERNAL_OBJECT_REF_OBJECT_H__

// External object reference
struct external_object_ref_object : external_ref_object
{
	static base_object* make()
	{
		return new external_object_ref_object();
	}

	enum
	{
		object_type = 0xfd,
	};

	external_object_ref_object()
	{
		DEFINE_M3G_VARRAY(Int32, "userID", M3G_FILE_FORMAT_20);
	}

	template<class T>
	void traverse(T op)
	{
		M3G_TYPE("userID", op);
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
		PRINT_TEMPLATE(external_ref_object, "ExternalObjectReference",
			out, indent, version);
	}
	virtual int class_type()
	{
		return OBJ_CLASS_EXT_OBJ;
	}
};

#endif//__EXTERNAL_OBJECT_REF_OBJECT_H__
