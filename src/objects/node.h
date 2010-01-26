/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  node.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/26/2010 10:48:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined(__NODE_H__)
#define __NODE_H__

#include "objects/transformable.h"

// Node
struct node_object : transformable_object
{
	node_object()
	{
		DEFINE_M3G_TYPE(Boolean, "enableRendering", true,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Boolean, "enablePicking", false,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Byte, "alphaFactor", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Int32, "scope", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Boolean, "hasAlignment", false,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Byte, "zTarget", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Byte, "yTarget", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(ForwardIndex, "zReference", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(ForwardIndex, "yReference", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Boolean, "hasBoundingBox", false,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float32, "boundMinX", 0, M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float32, "boundMaxX", 0, M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float32, "boundMinY", 0, M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float32, "boundMaxY", 0, M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float32, "boundMinZ", 0, M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float32, "boundMaxZ", 0, M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Boolean, "hasBoundingSphere", false,T
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float32, "boundCenterX", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float32, "boundCenterY", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float32, "boundCenterZ", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float32, "boundRadius", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Boolean, "collisionEnabled", false,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Boolean, "hasCollisionShape", false,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Int32, "orientations", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_FARRAY(Float32, "min", 13, M3G_FILE_FORMAT_20);
		DEFINE_M3G_FARRAY(Float32, "max", 13, M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float32, "LODResolution", 0,
			M3G_FILE_FORMAT_20);
	}

	template<class T>
	void traverse(T &op)
	{
		M3G_TYPE("enableRendering", op);
		M3G_TYPE("enablePicking", op);
		M3G_TYPE("alphaFactor", op);
		M3G_TYPE("scope", op);
		M3G_TYPE("hasAlignment", op);
		if (M3G_TYPE_CAST("hasAlignment", Boolean))
		{
			M3G_TYPE("zTarget", op);
			M3G_TYPE("yTarget", op);
			M3G_TYPE("zReference", op);
			M3G_TYPE("yReference", op);
		}

		M3G_TYPE("hasBoundingBox", op);
		if (M3G_TYPE_CAST("hasBoundingBox", Boolean))
		{
			M3G_TYPE("boundMinX", op);
			M3G_TYPE("boundMaxX", op);
			M3G_TYPE("boundMinY", op);
			M3G_TYPE("boundMaxY", op);
			M3G_TYPE("boundMinZ", op);
			M3G_TYPE("boundMaxZ", op);
		}
		M3G_TYPE("hasBoundingSphere", op);
		if (M3G_TYPE_CAST("hasBoundingSphere", op))
		{
			M3G_TYPE("boundCenterX", op);
			M3G_TYPE("boundCenterY", op);
			M3G_TYPE("boundCenterZ", op);
			M3G_TYPE("boundRadius", op);
		}
		M3G_TYPE("collisionEnabled", op);
		M3G_TYPE("hasCollisionShape", op);
		if (M3G_TYPE_CAST("hasCollisionShape", Boolean))
		{
			M3G_TYPE("orientations", op);
			M3G_TYPE("min", op);
			M3G_TYPE("max", op);
		}
		M3G_TYPE("LODResolution", op);
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(transformable_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(transformable_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(transformable_object, "Node",
			out, indent, version);
	}
};

#endif//__NODE_H__
