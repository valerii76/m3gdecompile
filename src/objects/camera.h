/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  camera.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27.01.2010 9:45:28
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */

#if !defined(__CAMERA_H__)
#define __CAMERA_H__

#include "node.h"

// Camera
struct camera_object : node_object
{
	static base_object* make()
	{
		return new camera_object();
	}

	enum
	{
		object_type = 5,
	};

	camera_object()
	{
		DEFINE_M3G_TYPE(Byte, "projectionType", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Matrix, "projectionMatrix", Matrix(),
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Float32, "x", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float32, "y", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float32, "width", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float32, "height", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Float32, "fovy", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Float32, "aspectRatio", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Float32, "near", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Float32, "far", 0,
			M3G_FILE_FORMAT_ALL);
	}
	template<class T>
	void traverse(T &op)
	{
		Byte projType;
		M3G_TYPE("projectionType", op);
		projType = M3G_TYPE_CAST("projectionType", Byte);
		if (projType == CAMERA_GENERIC)
			M3G_TYPE("projectionMatrix", op);
		else if (projType == CAMERA_SCREEN)
		{
			M3G_TYPE("x", op);
			M3G_TYPE("y", op);
			M3G_TYPE("width", op);
			M3G_TYPE("height", op);
		}
		else
		{
			M3G_TYPE("fovy", op);
			M3G_TYPE("aspectRatio", op);
			M3G_TYPE("near", op);
			M3G_TYPE("far", op);
		}
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
		PRINT_TEMPLATE(node_object, "Camera",
			out, indent, version);
	}
};


#endif//__CAMERA_H__
