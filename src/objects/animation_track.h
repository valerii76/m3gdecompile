/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  animation_track.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/26/2010 08:24:12 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined (__ANIMATION_TRACK_H__)
#define __ANIMATION_TRACK_H__

#include "object3d.h"

//AnimationTrack
struct animation_track_object : object3d_object
{
	static base_object* make()
	{
		return new animation_track_object();
	}

	enum
	{
		object_type = 2,
	};

	animation_track_object()
	{
		DEFINE_M3G_TYPE(ObjectIndex, "keyframeSequence", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(ObjectIndex, "animationController", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(UInt16, "propertyID_20", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(UInt32, "propertyID_10", 0,
			M3G_FILE_FORMAT_10);
		DEFINE_M3G_TYPE(Boolean, "isNormalizeEnabled", false,
			M3G_FILE_FORMAT_20);
	}

	template<class T>
	void traverse(T& op)
	{
		M3G_TYPE("keyframeSequence", op);
		M3G_TYPE("animationController", op);

		if (op.version == M3G_FILE_FORMAT_20)
		{
			UInt16 prop;
			M3G_TYPE("propertyID_20", op);
			prop = M3G_TYPE_CAST("propertyID_20", UInt16);
			if (prop >= SHADERVARIABLE_FLOAT &&
				prop <= SHADERVARIABLE_SAMPLER_CUBE)
				M3G_TYPE("isNormalizeEnabled", op);
		}
		else
		{
			M3G_TYPE("propertyID_10", op);
		}
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
		PRINT_TEMPLATE(object3d_object, "AnimationTrack",
			out, indent, version);
	}
};

#endif//__ANIMATION_TRACK_H__
