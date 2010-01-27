/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  keyframe_sequence.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27.01.2010 17:47:06
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined(__KEYFRAME_SEQUENCE_H__)
#define __KEYFRAME_SEQUENCE_H__

// Keyframe sequence
struct keyframe_sequence_object : object3d_object
{
	static base_object* make()
	{
		return new keyframe_sequence_object();
	}
	enum
	{
		object_type = 19,
	};

	template<class T>
	struct keyframe
		: m3g_base_object
	{
		keyframe()
		{
			DEFINE_M3G_TYPE(UInt32, "time", 0,
				M3G_FILE_FORMAT_ALL);
			DEFINE_M3G_VARRAY(T, "vectorValue",
				M3G_FILE_FORMAT_ALL);
		}
		template<class O>
		void traverse(O &op)
		{
			M3G_TYPE("time", op);
			M3G_TYPE("vectorValue", op);
		}
		virtual int load(Stream& strm, int version)
		{
			LOAD_TEMPLATE(object3d_object, strm, version);
		}
		virtual int save(Stream& strm, int version)
		{
			SAVE_TEMPLATE(object3d_object, strm, version);
		}
		virtual void print(FILE* out, std::string const &indent,
			int version)
		{
			PRINT_TEMPLATE(object3d_object, "KeyframeItem",
				out, indent, version);
		}
	};

	struct event
	{
		event()
		{
			DEFINE_M3G_TYPE(UInt32, "eventTime", 0,
				M3G_FILE_FORMAT_20);
			DEFINE_M3G_TYPE(Int32, "eventID", 0,
				M3G_FILE_FORMAT_20);
		}
		template<class T>
		void traverse(T &op)
		{
			M3G_TYPE("eventTime", op);
			M3G_TYPE("eventID", op);
		}
		virtual int load(Stream& strm, int version)
		{
			LOAD_TEMPLATE(object3d_object, strm, version);
		}
		virtual int save(Stream& strm, int version)
		{
			SAVE_TEMPLATE(object3d_object, strm, version);
		}
		virtual void print(FILE* out, std::string const &indent,
			int version)
		{
			PRINT_TEMPLATE(object3d_object, "EventItem",
				out, indent, version);
		}
	};

	keyframe_sequence_object()
	{
		DEFINE_M3G_TYPE(Byte, "interpolation", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Byte, "repeatMode", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Byte, "encoding", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(UInt32, "duration", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(UInt32, "validRangeFirst", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(UInt32, "validRangeLast", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(UInt32, "componentCount", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(UInt32, "keyframeCount", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(UInt32, "channelCount", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_VARRAY(Float32, "vectorBias",
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_VARRAY(Float32, "vectorScale",
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_VARRAY(event, "events",
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_VARRAY(keyframe<Float32>, "keyframes_f",
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_VARRAY(keyframe<Byte>, "keyframes_b",
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_VARRAY(keyframe<UInt16>, "keyframes_ui16",
			M3G_FILE_FORMAT_ALL);
	}
	template<class T>
	void traverse(T &op)
	{
		Byte encoding;
		M3G_TYPE("interpolation", op);
		M3G_TYPE("repeatMode", op);
		M3G_TYPE("encoding", op);
		M3G_TYPE("duration", op);
		M3G_TYPE("validRangeFirst", op);
		M3G_TYPE("validRangeLast", op);
		M3G_TYPE("componentCount", op);
		M3G_TYPE("keyframeCount", op);
		M3G_TYPE("channelCount", op);

		encoding = M3G_TYPE_CAST("encoding", Byte);

		if (encoding == 0)
		{
			M3G_TYPE("keyframes_f", op);
		}
		else if (encoding == 1)
		{
			M3G_TYPE("vectorBias", op);
			M3G_TYPE("vectorScale", op);
			M3G_TYPE("keyframes_b", op);
		}
		else if(encoding == 2)
		{
			M3G_TYPE("vectorBias", op);
			M3G_TYPE("vectorScale", op);
			M3G_TYPE("keyframes_ui16", op);
		}

		M3G_TYPE("events", op);
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
		PRINT_TEMPLATE(object3d_object, "KeyframeSequence",
			out, indent, version);
	}
};


template<class T>
inline void print_value(FILE *out, char const *indent, char const *name,
	std::vector< keyframe_sequence_object::keyframe< T > >& v, int version)
{
	std::string new_indent = std::string(indent) + "\t";
	operation_print op(out, new_indent, version);
	if (v.size() == 0)
		return;
	fprintf(out, "%s%s\n%s{\n", indent, name, indent);
	//fprintf(out, "%sUInt32 count = %d;\n", new_indent.c_str(), v.size());
	for (int i = 0; i < v.size(); ++i)
	{
		fprintf(out, "%s/* %d */\n", new_indent.c_str(), i);
		v[i].traverse(op);
	}
	fprintf(out, "%s}\n", indent);
}
inline void print_value(FILE *out, char const *indent, char const *name,
	std::vector< keyframe_sequence_object::event > &v, int version)
{
	std::string new_indent = std::string(indent) + "\t";
	operation_print op(out, new_indent, version);
	if (v.size() == 0)
		return;
	fprintf(out, "%s%s\n%s{\n", indent, name, indent);
	fprintf(out, "%sUInt32 count = %d;\n", new_indent.c_str(), v.size());
	for (int i = 0; i < v.size(); ++i)
	{
		fprintf(out, "%s/* %d */\n", new_indent.c_str(), i);
		v[i].traverse(op);
	}
	fprintf(out, "%s}\n", indent);
}

template<class T>
inline int Stream::read(std::vector< keyframe_sequence_object::keyframe<T> >* v)
{
	int size = 0;
	UInt32 count = 0;
	size += impl->read((char*)&count, sizeof(UInt32));
	for (int i = 0; i < count; ++i)
	{
		keyframe_sequence_object::keyframe<T> t;
		t.load(*this, version);
		v->push_back(t);
	}
	return size;
}
template<>
inline int Stream::read(std::vector< keyframe_sequence_object::event >* v)
{
	int size = 0;
	UInt32 count = 0;
	size += impl->read((char*)&count, sizeof(UInt32));
	for (int i = 0; i < count; ++i)
	{
		keyframe_sequence_object::event t;
		t.load(*this, version);
		v->push_back(t);
	}
	return size;
}


#endif//__KEYFRAME_SEQUENCE_H__

