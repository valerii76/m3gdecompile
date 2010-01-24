/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  m3gformat.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/14/2010 09:53:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined(__M3G_FORMAT_H__)
#define __M3G_FORMAT_H__

#include <stdio.h>
#include "m3gfile.h"
#include "stream.h"
#include <vector>
#include "property.h"
#include "m3gconstants.h"

enum
{
	OBJ_CLASS_HEADER = 0,
	OBJ_CLASS_EXT_REF,
	OBJ_CLASS_EXT_IMG,
	OBJ_CLASS_EXT_OBJ,
	OBJ_CLASS_OBJECT3D,
};

struct operation_load
{
	int size;
	Stream &strm;
	int version;
	operation_load(Stream& _strm, int _version)
		: size(0)
		, strm(_strm)
		, version(_version)
	{}

	void operator() (m3g_base_type* o)
	{
		size += o->load(strm, version);
	}
};
struct operation_print
{
	operation_print(FILE *_out, std::string const &_indent, int version)
		: out(_out)
		, file_version(version)
		, indent(_indent)
	{
	}

	void operator () (m3g_base_type* o)
	{
		o->print(out, indent, file_version);
	}

	FILE *out;
	std::string indent;
	int file_version;
};
struct operation_save
{
	int size;
	Stream &strm;
	int version;
	operation_save(Stream& _strm, int _version)
		: size(0)
		, strm(_strm)
		, version(_version)
	{}

	void operator() (m3g_base_type* o)
	{
		size += o->save(strm, version);
	}
};

struct base_object
	: m3g_base_type
{
	static base_object* make(int obj_type);
	virtual int class_type() = 0;
};

#define LOAD_TEMPLATE(base, strm, version) \
	operation_load op(strm, version); \
	op.size += base::load(strm, version); \
	traverse(op); \
	return op.size;

#define SAVE_TEMPLATE(base, strm, version) \
	operation_save op(strm, version); \
	op.size += base::save(strm, version); \
	traverse(op); \
	return op.size;

#define PRINT_TEMPLATE(base, name, out, indent, version) \
	operation_print op(out, indent + "\t", version); \
	fprintf(out, "%s%s\n%s{\n", indent, name, indent); \
	base::print(out, indent + "\t", version); \
	traverse(op); \
	fpritnf(out, "%s}\n", indent);

// Header object
struct header_object : base_object
{
	static base_object* make()
	{
		return new header_object();
	}

	enum
	{
		object_type = 0,
	};

	header_object()
	{
		DEFINE_M3G_FARRAY(Byte, 2, "VersionNumber",
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Boolean, "hasExternalReferences", false,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(UInt32, "TotalFileSize", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(UInt32, "ApproximateContentSize", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(StringUTF8, "AuthoringField", "",
			M3G_FILE_FORMAT_ALL);
	}

	template<class T>
	void traverse(T& op)
	{
		M3G_TYPE("VersionNumber", op);
		M3G_TYPE("hasExternalReferences", op);
		M3G_TYPE("TotalFileSize", op);
		M3G_TYPE("ApproximateContentSize", op);
		M3G_TYPE("AuthoringField", op);
	}

	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(base_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(base_object, strm version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(base_object, "Header", out, indent, version);
	}
	virtual int class_type()
	{
		return OBJ_CLASS_HEADER;
	}
};

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

// External image reference
struct external_image_ref_object : external_ref_object
{
	static base_object* make()
	{
		return new external_image_ref_object();
	}

	enum
	{
		object_type = 0xfe,
	};

	external_image_ref_object()
	{
		DEFINE_M3G_TYPE(Int32, "format", IMAGEBASE_RGBA,
			M3G_FILE_FORMAT_20);
	}

	template<class T>
	void traverse(T op)
	{
		M3G_TYPE("format", op);
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
		PRINT_TEMPLATE(external_ref_object, "ExternalImageReference",
			out, indent, version);
	}
	virtual int class_type()
	{
		return OBJ_CLASS_EXT_IMG;
	}
};

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
	};
	struct parameter_s
	{
		Int32 parameter_id;
		std::vector<Byte> parameter_value;
	};

	Int32 user_id;
	std::vector<anim_track> animation_tracks;
	std::vector<parameter_s> parameters;
	Boolean animation_enabled;

	object3d()
	{
		DEFINE_M3G_TYPE(Int32, "userID", 0, M3G_FILE_FORMAT_ALL);
		
	}

	template<class T>
	void traverse(T op)
	{
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

	Float32 speed;
	Float32 weight;
	Int32 active_interval_start;
	Int32 active_interval_end;
	Float32 reference_sequence_time;
	Int32 reference_world_time;

	template<class T>
	void traverse(T op)
	{
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

	ObjectIndex keyframe_sequence;
	ObjectIndex animation_controller;
	union
	{
		UInt16 v20;
		UInt32 v10;
	} property_id;

	Boolean is_normalize_enabled;

	template<class T>
	void traverse(T op)
	{
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

// AppearanceBase
struct appearance_base_object : object3d_object
{
	union
	{
		Byte v20;
		SByte v10;
	} layer;

	ObjectIndex compositing_mode;
	ObjectIndex polygon_mode;
	Boolean is_depth_sort_enabled;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "AppearanceBase",
			out, indent, version);
	}
};

// Appearance
struct appearance_object : appearance_base_object
{
	static base_object* make()
	{
		return new appearance_object();
	};

	enum
	{
		object_type = 3,
	};

	ObjectIndex fog;
	ObjectIndex point_sprite_mode;
	ObjectIndex material;
	std::vector<ObjectIndex> textures;

	template<class T>
	void traverse(T op)
	{
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(appearance_base_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(appearance_base_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(appearance_base_object, "Appearance",
			out, indent, version);
	}
};

// Backgroud
struct background_object : object3d_object
{
	static base_object* make()
	{
		return new background_object();
	}

	enum
	{
		object_type = 4,
	};

	ColorRGBA background_color;
	ObjectIndex background_image;
	Byte background_image_mode_x;
	Byte background_image_mode_y;
	Int32 crop_x;
	Int32 crop_y;
	Int32 crop_width;
	Int32 crop_heigth;
	Boolean depth_clear_enabled;
	Float32 depth;
	Int32 stencil;
	Int32 stencil_clear_mask;
	ColorRGBA color_clear_mask;
	Boolean color_clear_enabled;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "Background",
			out, indent, version);
	}
};

// Transformable
struct transformable_object : object3d_object
{
	Boolean has_component_transform;
	Vector3D translation;
	Vector3D scale;
	Float32 orientation_angle;
	Vector3D orientation_axis;
	Boolean has_general_transform;
	Matrix transform;

	template<class T>
	void traverse(T op)
	{
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

// Node
struct node_object : transformable_object
{
	Boolean enable_rendering;
	Boolean enable_picking;
	Byte alpha_factor;
	Int32 scope;
	Boolean has_alignment;
	Byte z_target;
	Byte y_target;
	ForwardIndex z_reference;
	ForwardIndex y_reference;
	Boolean has_bounding_box;
	Float32 bound_min_x;
	Float32 bound_max_x;
	Float32 bound_min_y;
	Float32 bound_max_y;
	Float32 bound_min_z;
	Float32 bound_max_z;
	Boolean has_bounding_sphere;
	Float32 bound_center_x;
	Float32 bound_center_y;
	Float32 bound_center_z;
	Float32 bound_radius;
	Boolean collision_enabled;
	Boolean has_collision_shape;
	Int32 orientations;
	Float32 min[13];
	Float32 max[13];
	Float32 lod_resolution;

	template<class T>
	void traverse(T op)
	{
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

	Byte projection_type;
	Matrix projection_matrix;
	Float32 x;
	Float32 y;
	Float32 width;
	Float32 height;
	Float32 fovy;
	Float32 aspect_ratio;
	Float32 near;
	Float32 far;

	template<class T>
	void traverse(T op)
	{
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

// CompositionMode
struct composition_mode_object : object3d_object
{
	static base_object* make()
	{
		return new composition_mode_object();
	}
	enum
	{
		object_type = 6,
	};

	Boolean depth_test_enabled;
	Boolean depth_write_enabled;
	Boolean color_write_enabled;
	Boolean alpha_write_enabled;
	Byte blending;
	Byte alpha_threshold;
	Float32 depth_offset_factor;
	Float32 depth_offset_units;
	UInt16 depth_test;
	UInt16 alpha_test;
	ObjectIndex blender;
	ObjectIndex stencil;
	ColorRGBA color_write_mask;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "CompositingMode",
			out, indent, version);
	}
};

// Fog
struct fog_object : object3d_object
{
	static base_object* make()
	{
		return new fog_object();
	}
	enum
	{
		object_type = 7,
	};

	ColorRGB color;
	Byte mode;
	Float32 density;
	Float32 near;
	Float32 far;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "Fog",
			out, indent, version);
	}
};

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

	template<class T>
	void traverse(T op)
	{
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

// ImageBase
struct image_base_object : object3d_object
{
	union
	{
		Int32 v20;
		Byte v10;
	} format;
	Boolean is_mutable;
	UInt32 width;
	UInt32 height;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "ImageBase",
			out, indent, version);
	}
};

// Image2D
struct image2d_object : image_base_object
{
	static base_object* make()
	{
		return new image2d_object();
	}
	enum
	{
		object_type = 10,
	};
	std::vector<Byte> palette;
	std::vector<Byte> base_pixels;

	struct mipmap_s
	{
		std::vector<Byte> mipmap_pixels;
	};
	Byte mipmap_count;
	std::vector<mipmap_s> mipmaps;

	template<class T>
	void traverse(T op)
	{
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(image_base_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(image_base_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(image_base_object, "Image2D",
			out, indent, version);
	}
};

// IndexBuffer
struct index_buffer_object : object3d_object
{
	static base_object* make()
	{
		return new index_buffer_object();
	}
	union union_var
	{
		UInt32 _uint32;
		Byte _byte;
		UInt16 _uint16;
	};

	struct union_array
	{
		std::vector<UInt32> _uint32;
		std::vector<Byte> _byte;
		std::vector<UInt16> _uint16;
	};
	struct union_array_deltas
	{
		std::vector<Int32> _i32;
		std::vector<Byte> _byte;
		std::vector<Int16> _i16;
	};

	enum
	{
		object_type = 27,
	};

	Byte encoding;
	Boolean is_immutable;
	Byte primitive_type;
	Byte strip_encoding;

	union_var primitive_count;
	union_array strip_lengths;
	union_var start_index;
	union_array indices;
	union_array_deltas index_deltas;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "IndexBuffer",
			out, indent, version);
	}
};

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

	struct union_array
	{
		std::vector<Float32> _float32;
		std::vector<Byte> _byte;
		std::vector<UInt16> _uint16;
	};

	struct keyframe_s
	{
		UInt32 time;
		union_array vector_value;
	};

	struct event_s
	{
		UInt32 event_time;
		Int32 event_id;
	};

	Byte interpolation;
	Byte repeat_mode;
	Byte encoding;
	UInt32 duration;
	UInt32 valid_range_first;
	UInt32 valid_range_last;
	UInt32 component_count;

	UInt32 keyframe_count;
	UInt32 channel_count;
	std::vector<keyframe_s> keyframes;
	std::vector<Float32> vector_bias;
	std::vector<Float32> vector_scale;

	std::vector<event_s> events;

	template<class T>
	void traverse(T op)
	{
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


// Light
struct light_object : node_object
{
	static base_object* make()
	{
		return new light_object();
	}
	enum
	{
		object_type = 12,
	};

	Float32 attenuation_constant;
	Float32 attenuation_linear;
	Float32 attenuation_quadratic;
	ColorRGB color;
	Byte mode;
	Float32 intensity;
	Float32 spot_angle;
	Float32 spot_exponent;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(node_object, "Light",
			out, indent, version);
	}
};

// Material
struct material_object : object3d_object
{
	static base_object* make()
	{
		return new material_object();
	}
	enum
	{
		object_type = 13,
	};
	ColorRGB ambient_color;
	ColorRGBA diffuse_color;
	ColorRGB emissive_color;
	ColorRGB specular_color;
	Float32 shininess;
	Boolean vertex_color_tracking_enabled;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "Material",
			out, indent, version);
	}
};

// Mesh
struct mesh_object : node_object
{
	static base_object* make()
	{
		return new mesh_object();
	}
	enum
	{
		object_type = 14,
	};

	struct submesh_s
	{
		ObjectIndex index_buffer;
		ObjectIndex appearance;
	};

	struct target_buf_s
	{
		ObjectIndex morph_target;
		Float32 initial_weight;
	};

	ObjectIndex vertex_buffer;
	UInt32 submesh_count;
	std::vector<submesh_s> submeshes;

	std::vector<target_buf_s> target_buffers;
	std::vector<UInt32> morph_subset;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(node_object, "Mesh",
			out, indent, version);
	}
};

// MorphingMesh
struct morphing_mesh_object : mesh_object
{
	static base_object* make()
	{
		return new morphing_mesh_object();
	}
	enum
	{
		object_type = 15,
	};

	template<class T>
	void traverse(T op)
	{
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(mesh_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(mesh_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(mesh_object, "MorphingMesh",
			out, indent, version);
	}
};

// PolygonMode
struct polygon_mode_object : object3d_object
{
	static base_object* make()
	{
		return new polygon_mode_object();
	}
	enum
	{
		object_type = 8,
	};
	Byte culling;
	Byte shading;
	Byte winding;
	Boolean two_sided_lighting_enabled;
	Boolean local_camera_lighting_enabled;
	Boolean perspective_correction_enabled;
	Float32 line_width;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "PolygonMode",
			out, indent, version);
	}
};

// SkinnedMesh
struct skinned_mesh_object : mesh_object
{
	static base_object* make()
	{
		return new skinned_mesh_object();
	}
	enum
	{
		object_type = 16,
	};

	struct bone_s
	{
		ObjectIndex transform_node;
		UInt32 first_vertex;
		UInt32 vertex_count;
		Int32 weight;
	};

	ObjectIndex skeleton;
	Boolean is_using_add_transform;
	std::vector<bone_s> bones;

	template<class T>
	void traverse(T op)
	{
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(mesh_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(mesh_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(mesh_object, "SkinnedMesh",
			out, indent, version);
	}
};

// Sprite3D
struct sprite3d_object : node_object
{
	static base_object* make()
	{
		return new sprite3d_object();
	}
	enum
	{
		object_type = 18,
	};


	ObjectIndex image;
	ObjectIndex appearance;

	Boolean is_scaled;
	Int32 crop_x;
	Int32 crop_y;
	Int32 crop_width;
	Int32 crop_height;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(node_object, "Sprite3D",
			out, indent, version);
	}
};

// Texture
struct texture_object : transformable_object
{
	ObjectIndex image;
	Byte level_filter;
	Byte image_filter;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(transformable_object, "Texture",
			out, indent, version);
	}
};

// Texture2D
struct texture2d_object : texture_object
{
	static base_object* make()
	{
		return new texture2d_object();
	}
	enum
	{
		object_type = 17,
	};

	union
	{
		ColorRGBA rgba;
		ColorRGB rgb;
	} blend_color;

	Byte blending;
	Byte wrapping_s;
	Byte wrapping_t;

	ObjectIndex combiner;

	template<class T>
	void traverse(T op)
	{
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(texture_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(texture_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(texture_object, "Texture2D",
			out, indent, version);
	}
};

// TriangleStripArray
struct triangle_strip_array_object : index_buffer_object
{
	static base_object* make()
	{
		return new triangle_strip_array_object();
	}
	enum
	{
		object_type = 11,
	};

	template<class T>
	void traverse(T op)
	{
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(index_buffer_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(index_buffer_object, str, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(index_buffer_object, "TriangleStripArray",
			out, indent, version);
	}
};

// VertexArray
struct vertex_array_object : object3d_object
{
	static base_object* make()
	{
		return new vertex_array_object();
	}
	enum
	{
		object_type = 20,
	};

	Byte component_type;
	Byte component_count;
	Byte encoding;

	struct data_s
	{
		std::vector<Byte> _byte;
		std::vector<Int16> _i16;
		std::vector<Int32> _i32;
		std::vector<Float16> _float16;
		std::vector<Float32> _float32;
	};

	UInt16 vertex_count;
	std::vector<data_s> components;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "VertexArray",
			out, indent, version);
	}
};

// VertexBuffer
struct vertex_buffer_object : object3d_object
{
	static base_object* make()
	{
		return new vertex_buffer_object();
	}
	enum
	{
		object_type = 21,
	};

	struct coords_s
	{
		ObjectIndex coord;
		Float32 bias[3];
		Float32 scale;
	};

	struct attribute_s
	{
		StringUTF8 name;
		ObjectIndex attribute;
		Boolean _signed;
		Boolean _normalized;
		Float32 default_attribute_value[4];
	};

	ColorRGBA default_color;
	ObjectIndex positions;
	Float32 position_bias[3];
	Float32 position_scale;

	ObjectIndex normals;
	ObjectIndex colors;

	std::vector<coords_s> textures;

	Boolean is_immutable;
	ObjectIndex point_sizes;
	Float32 default_point_size;

	ObjectIndex bone_indices;
	ObjectIndex bone_weights;
	std::vector<attribute_s> attributes;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "VertexBuffer",
			out, indent, version);
	}
};

// World
struct world_object : group_object
{
	static base_object* make()
	{
		return new world_object();
	}
	enum
	{
		object_type = 22,
	};

	ObjectIndex active_camera;
	ObjectIndex background;

	template<class T>
	void traverse(T op)
	{
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(group_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(group_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(group_object, "World",
			out, indent, version);
	}
};

// Blender
struct blender_object : object3d_object
{
	static base_object* make()
	{
		return new blender_object();
	}
	enum
	{
		object_type = 23,
	};

	Byte func_alpha;
	Byte src_alpha;
	Byte dst_alpha;

	Byte func_color;
	Byte src_color;
	Byte dst_color;

	ColorRGBA blend_color;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "Blender",
			out, indent, version);
	}
};

// DynamicImage2D
struct dynamic2d_object : object3d_object
{
	static base_object* make()
	{
		return new dynamic2d_object();
	}
	enum
	{
		object_type = 24,
	};

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "DynamicImage2D",
			out, indent, version);
	}
};

// Shader
struct shader_object : object3d_object
{
	StringUTF8 source;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "Shader",
			out, indent, version);
	}
};

// FragmentShader
struct fragment_shader_object : shader_object
{
	static base_object* make()
	{
		return new fragment_shader_object();
	}
	enum
	{
		object_type = 25,
	};

	template<class T>
	void traverse(T op)
	{
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(shader_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(shader_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(shader_object, "FragmentShader",
			out, indent, version);
	}
};

// ImageCube
struct image_cube_object : image_base_object
{
	static base_object* make()
	{
		return new image_cube_object();
	}
	enum
	{
		object_type = 26,
	};

	struct face_s
	{
		std::vector<Byte> pixels;
		Byte mipmap_count;
		struct mipmap_s
		{
			std::vector<Byte> values;
		};
		std::vector<mipmap_s> mipmap_pixels;
	};
	face_s mipmaps[6];

	template<class T>
	void traverse(T op)
	{
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(image_base_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(image_base_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(image_base_object, "ImageCube",
			out, indent, version);
	}
};

// PointSpriteMode
struct point_sprite_mode_object : object3d_object
{
	static base_object* make()
	{
		return new point_sprite_mode_object();
	}
	enum
	{
		object_type = 28,
	};

	Float32  point_fade_threshold;
	Float32  point_attenuation_a;
	Float32  point_attenuation_b;
	Float32  point_attenuation_c;
	Float32  point_size_clamp_min;
	Float32  point_size_clamp_max;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "PointSpriteMode",
			out, indent, version);
	}
};

// RenderPass
struct render_pass_object : object3d_object
{
	static base_object* make()
	{
		return new render_pass_object();
	}
	enum
	{
		object_type = 29,
	};

	ObjectIndex  scene;
	ObjectIndex  camera;
	ObjectIndex  background;
	ObjectIndex  target;
	UInt32 flags;
	Float32 depth_range_near;
	Float32 depth_range_far;
	Boolean is_viewport_set;

	Int32 viewport_x;
	Int32 viewport_y;
	Int32 viewport_width;
	Int32 viewport_height;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "RenderPass",
			out, indent, version);
	}
};

// RenderTarget
struct render_target_object : object3d_object
{
	static base_object* make()
	{
		return new render_target_object();
	}
	enum
	{
		object_type = 30,
	};

	ObjectIndex target;
	Byte target_level;
	Byte target_face;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "RenderTarget",
			out, indent, version);
	}
};

// ShaderAppearance
struct shader_appearance_object : appearance_base_object
{
	static base_object* make()
	{
		return new shader_appearance_object();
	}
	enum
	{
		object_type = 31,
	};

	ObjectIndex shader_program;
	std::vector<ObjectIndex> shader_uniforms;
	Boolean is_validate_enabled;

	template<class T>
	void traverse(T op)
	{
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(appearance_base_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(appearance_base_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(appearance_base_object, "ShaderAppearance",
			out, indent, version);
	}
};

// ShaderProgram
struct shader_program_object : object3d_object
{
	static base_object* make()
	{
		return new shader_program_object();
	}
	enum
	{
		object_type = 32,
	};

	ObjectIndex fragment_shader;
	ObjectIndex vertex_shader;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "ShaderProgram",
			out, indent, version);
	}
};

// ShaderUniforms
struct shader_uniforms_object : object3d_object
{
	static base_object* make()
	{
		return new shader_uniforms_object();
	}
	enum
	{
		object_type = 33,
	};


	struct uniform_s
	{
		struct union_array
		{
			std::vector<Boolean> _bool;
			std::vector<Int32> _i32;
			std::vector<Float32> _float32;
			std::vector<ObjectIndex> _index;
		};

		struct track_s
		{
			ObjectIndex animation_track;
			UInt32 channel_index;
		};

		StringUTF8 name;
		UInt16 type;
		UInt16 binding_type;
		UInt32 length;

		union_array value;
		std::vector<track_s> tracks;

		std::vector<ForwardIndex> node_from;
		std::vector<ForwardIndex> node_to;

		std::vector<ForwardIndex> source;
		UInt32 property;
	};

	std::vector<uniform_s> uniforms;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "ShaderUniforms",
			out, indent, version);
	}
};

// Stencil
struct stencil_object : object3d_object
{
	static base_object* make()
	{
		return new stencil_object();
	}
	enum
	{
		object_type = 34,
	};


	Int16 stencil_func_front;
	Int32 stencil_ref_front;
	Int32 stencil_mask_front;

	Int32 stencil_write_mask_front;

	Byte stencil_fail_op_front;
	Byte stencil_pass_depth_fail_op_front;
	Byte stencil_pass_depth_pass_op_front;

	Int16 stencil_func_back;
	Int32 stencil_ref_back;
	Int32 stencil_mask_back;

	Int32 stencil_write_mask_back;

	Byte stencil_fail_op_back;
	Byte stencil_pass_depth_fail_op_back;
	Byte stencil_pass_depth_pass_op_back;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "Stencil",
			out, indent, version);
	}
};

// TextureCombiner
struct texture_combiner_object : object3d_object
{
	static base_object* make()
	{
		return new texture_combiner_object();
	}
	enum
	{
		object_type = 35,
	};

	Byte color_function;
	Byte color_scale;
	UInt16 color_source0;
	UInt16 color_source1;
	UInt16 color_source2;
	Byte alpha_function;
	Byte alpha_scale;
	UInt16 alpha_source0;
	UInt16 alpha_source1;
	UInt16 alpha_source2;

	template<class T>
	void traverse(T op)
	{
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
		PRINT_TEMPLATE(object3d_object, "TextureCombiner",
			out, indent, version);
	}
};

// TextureCube
struct texture_cube_object : texture_object
{
	static base_object* make()
	{
		return new texture_cube_object();
	}
	enum
	{
		object_type = 36,
	};

	template<class T>
	void traverse(T op)
	{
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(texture_object, strm, version);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(texture_object, strm, version);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(texture_object, "TextureCube",
			out, indent, version);
	}
};

// VertexShader
struct vertex_shader_object : shader_object
{
	static base_object* make()
	{
		return new vertex_shader_object();
	}
	enum
	{
		object_type = 37,
	};

	template<class T>
	void traverse(T op)
	{
	}
	virtual int load(Stream& strm, int version)
	{
		LOAD_TEMPLATE(shader_object, strm, vertex);
	}
	virtual int save(Stream& strm, int version)
	{
		SAVE_TEMPLATE(shader_object, strm, vertex);
	}
	virtual void print(FILE* out, std::string const &indent, int version)
	{
		PRINT_TEMPLATE(shader_object, "VertexShader",
			out, indent, version);
	}
};

typedef std::vector<base_object*> lst_all_objects_t;
typedef std::vector<object3d_object*> lst_objects_t;
typedef std::vector<external_ref_object*> lst_ext_refs_t;
typedef std::vector<external_object_ref_object*> lst_ext_obj_refs_t;
typedef std::vector<external_image_ref_object*> lst_ext_img_refs_t;

#endif//__M3G_FORMAT_H__
