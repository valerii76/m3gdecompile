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

enum
{
	OBJ_CLASS_HEADER = 0,
	OBJ_CLASS_EXT_REF,
	OBJ_CLASS_EXT_IMG,
	OBJ_CLASS_EXT_OBJ,
	OBJ_CLASS_OBJECT3D,
};

struct base_object
{
	static base_object* make(int obj_type);
	virtual int class_type() = 0;
	virtual int load(Stream& strm, int version) = 0;
	virtual void print(FILE* out, char* indent) = 0;
};

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

	Byte version_number[2];
	Boolean has_external_references;
	UInt32 total_file_size;
	UInt32 approximate_content_size;
	StringUTF8 authoring_field;

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	StringUTF8 URI;

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	Int32 format;

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	std::vector<Int32> user_id;

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
	virtual int class_type()
	{
		return OBJ_CLASS_EXT_OBJ;
	}
};

// Object3D
struct object3d_object : base_object
{
	struct anim_track_s
	{
		ObjectIndex animation_track;
		UInt32 animation_track_index;
	};
	struct parameter_s
	{
		Int32 parameter_id;
		std::vector<Byte> parameter_value;
	};

	Int32 user_id;
	std::vector<anim_track_s> animation_tracks;
	std::vector<parameter_s> parameters;
	Boolean animation_enabled;

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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
	Boolean is_deph_sort_enabled;

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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
	Float32 heigth;
	Float32 fovy;
	Float32 aspect_ratio;
	Float32 near;
	Float32 far;

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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
	Float32 dencity;
	Float32 near;
	Float32 far;

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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
	UInt32 heigth;

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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
		std::vector<Int32> _int32;
		std::vector<Byte> _byte;
		std::vector<Int16> _int16;
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
};

// Texture
struct texture_object : transformable_object
{
	ObjectIndex image;
	Byte level_filter;
	Byte image_filter;

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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
	ObjectIndex position;
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
};

// Shader
struct shader_object : object3d_object
{
	StringUTF8 source;

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out, char* indent);
};

typedef std::vector<base_object*> lst_all_objects_t;
typedef std::vector<object3d_object*> lst_objects_t;
typedef std::vector<external_ref_object*> lst_ext_refs_t;
typedef std::vector<external_object_ref_object*> lst_ext_obj_refs_t;
typedef std::vector<external_image_ref_object*> lst_ext_img_refs_t;

#endif//__M3G_FORMAT_H__
