/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  group.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27.01.2010 13:25:18
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */

#if !defined(__GROUP_H__)
#define __GROUP_H__

#include "node.h"

// Group
struct group_object : node_object
{
	static base_object* make()
	{
		return new group_object();
	}
	enum
	{
		object_type = 9,
	};

	std::vector<ObjectIndex> children;
	Boolean is_lod_enabled;
	Float16 hysteresis;
	Float16 offset;

	group_object()
	{
		DEFINE_M3G_VARRAY(ObjectIndex, "children",
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Boolean, "isLodEnabled", false,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float16, "hysteresis", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float16, "offset", 0,
			M3G_FILE_FORMAT_20);
	}

	template<class T>
	void traverse(T &op)
	{
		M3G_TYPE("children", op);
		M3G_TYPE("isLodEnabled", op);
		M3G_TYPE("hysteresis", op);
		M3G_TYPE("offset", op);
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(node_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(node_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(node_object, "Group",
			out, indent, version);
	}
};

#endif//__GROUP_H__

