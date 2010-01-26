/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  object3d_object.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  26.01.2010 18:27:16
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined(__OBJECT3D_OBJECT_H__)
#define __OBJECT3D_OBJECT_H__

// Object3D
struct object3d_object : base_object
{
	struct anim_track
		: m3g_base_type
	{
		anim_track()
		{
			DEFINE_M3G_TYPE(ObjectIndex, "animationTrack",
				0, M3G_FILE_FORMAT_ALL);
			DEFINE_M3G_TYPE(UInt32, "animationTrackIndex",
				0, M3G_FILE_FORMAT_20);
		}
		template<class T>
		void traverse(T& op)
		{
			M3G_TYPE("animationTrack", op);
			M3G_TYPE("animationTrackIndex", op);
		}
		virtual int load(Stream &strm, int version)
		{
			LOAD_TEMPLATE(m3g_base_type, strm, version);
		}
		virtual int save(Stream &strm, int version)
		{
			SAVE_TEMPLATE(m3g_base_type, strm, version);
		}
		virtual void print(FILE *out, std::string const &indent,
			int version)
		{
			PRINT_TEMPLATE(m3g_base_type, "AnimTracks",
				out, indent, version);
		}
	};
	struct parameter
		: m3g_base_type
	{
		Int32 parameter_id;
		std::vector<Byte> parameter_value;

		parameter()
		{
			DEFINE_M3G_TYPE(Int32, "parameterID", 0,
				M3G_FILE_FORMAT_ALL);
			DEFINE_M3G_VARRAY(Byte, "parameterValue",
				M3G_FILE_FORMAT_ALL);
		}

		template<class T>
		void traverse(T& op)
		{
			M3G_TYPE("parameterID", op);
			M3G_TYPE("parameterValue", op);
		}
		virtual int load(Stream &strm, int version)
		{
			LOAD_TEMPLATE(m3g_base_type, strm, version);
		}
		virtual int save(Stream &strm, int version)
		{
			SAVE_TEMPLATE(m3g_base_type, strm, version);
		}
		virtual void print(FILE *out, std::string const &indent,
			int version)
		{
			PRINT_TEMPLATE(m3g_base_type, "Parameters",
				out, indent, version);
		}
	};

	object3d_object()
	{
		DEFINE_M3G_TYPE(Int32, "userID", 0, M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_VARRAY(anim_track, "animationTracks",
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_VARRAY(parameter, "parameters",
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Boolean, "animationEnabled", 0,
			M3G_FILE_FORMAT_20);
	}

	template<class T>
	void traverse(T op)
	{
		M3G_TYPE("userID", op);
		M3G_TYPE("animationTracks", op);
		M3G_TYPE("parameters", op);
		M3G_TYPE("animationEnabled", op);
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
		PRINT_TEMPLATE(base_object, "Object3D",
			out, indent, version);
	}
	virtual int class_type()
	{
		return OBJ_CLASS_OBJECT3D;
	}
};

inline void print_value(FILE *out, char const *indent, char const *name,
	std::vector< object3d_object::anim_track >& v)
{
}
inline void print_value(FILE *out, char const *indent, char const *name,
	std::vector< object3d_object::parameter > &v)
{
}

template<>
inline int Stream::read(std::vector< object3d_object::anim_track >* v)
{
	return 0;
}
template<>
inline int Stream::read(std::vector< object3d_object::parameter >* v)
{
	return 0;
}

#endif//__OBJECT3D_OBJECT_H__
