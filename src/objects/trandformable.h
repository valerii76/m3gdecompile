/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  trandformable.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/26/2010 10:36:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined (__TRANSFORMABLE_H__)
#define __TRANSFORMABLE_H__

// Transformable
struct transformable_object : object3d_object
{
	transformable()
	{
		DEFINE_M3G_TYPE(Boolean, "hasComponentTransform", false,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Vector3D, "translation", Vector3D(),
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Vector3D, "scale", Vector3D(),
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Float32, "orientationAngle", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Vector3D, "orientationAxis", Vector3D(),
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Boolean, "hasGeneralTransform", false,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Matrix, "transform", Matrix(),
			M3G_FILE_FORMAT_ALL);
	}

	template<class T>
	void traverse(T &op)
	{
		M3G_TYPE("hasComponentTransform", op);
		if (M3G_TYPE_CAST("hasComponentTransform", Boolean))
		{
			M3G_TYPE("translation", op);
			M3G_TYPE("scale", op);
			M3G_TYPE("orientationAngle", op);
			M3G_TYPE("orientationAxis", op);
		}
		M3G_TYPE("hasGeneralTransform", op);
		if (M3G_TYPE_CAST("hasGeneralTransform", Boolean))
			M3G_TYPE("transform", op);
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
		PRINT_TEMPLATE(object3d_object, "Transformable",
			out, indent, version);
	}
};



#endif//__TRANSFORMABLE_H__
