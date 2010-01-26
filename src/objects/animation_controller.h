/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  animation_controller_object.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26.01.2010 18:29:13
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined(__ANIMATION_CONTROLLER_OBJECT_H__)
#define __ANIMATION_CONTROLLER_OBJECT_H__

// AnimationController
struct animation_controller_object : object3d_object
{
	static base_object* make()
	{
		return new animation_controller_object();
	}

	enum
	{
		object_type = 1,
	};

	animation_controller_object()
	{
		DEFINE_M3G_TYPE(Float32, "speed", 0, M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Float32, "weight", 0, M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Int32, "activeIntervalStart", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Int32, "activeIntervalEnd", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Float32, "referenceSequenceTime", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Int32, "referenceWorldTime", 0,
			M3G_FILE_FORMAT_ALL);
	}

	template<class T>
	void traverse(T op)
	{
		object3d_object::traverse(op);
		M3G_TYPE("speed", op);
		M3G_TYPE("weight", op);
		M3G_TYPE("activeIntervalStart", op);
		M3G_TYPE("activeIntervalEnd", op);
		M3G_TYPE("referenceSequenceTime", op);
		M3G_TYPE("referenceWorldTime", op);
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
		PRINT_TEMPLATE(object3d_object, "AnimationController",
			out, indent, version);
	}
};

#endif//__ANIMATION_CONTROLLER_OBJECT_H__
