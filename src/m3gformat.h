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

#include "m3gfile.h"

// Header object
struct header_section
{
	enum
	{
		object_type = 0,
	};

	Byte version_number[2];
	Boolean has_external_references;
	UInt32 total_file_size;
	UInt32 approximate_content_size;
	StringUTF8 authoring_field;
};

// External reference
struct external_ref_section
{
	enum
	{
		object_type = 0xff,
	};

	StringUTF8 URI;
};

// External image reference
struct external_image_ref_section : external_ref_section
{
	enum
	{
		object_type = 0xfe,
	};

	Int32 format;
};

// External object reference
struct external_object_ref_section : external_ref_section
{
	enum
	{
		object_type = 0xfd,
	};

	std::vector<Int32> user_id;
};

// Object3D
struct object3d_section
{
	enum
	{
		object_type = -1,
	};

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
	Boolean animation_enbled;
};

// AnimationController
struct animation_controller_section : object3d_section
{
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
};

//AnimationTrack
struct animation_track_section : object3d_section
{
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
	} proterty_id;

	Boolean is_normalize_enabled;
};

// AppearanceBase
struct appearance_base_section : object3d_section
{
	union
	{
		Byte v20;
		SByte v10;
	} layer;

	ObjectIndex compositing_mode;
	ObjectIndex polygon_mode;
	Boolean is_deph_sort_enabled;
};

// Appearance
struct appearance_section : appearance_base_section
{
	enum
	{
		object_type = 3,
	};

	ObjectIndex fog;
	ObjectIndex point_sprite_mode;
	ObjectIndex material;
	std::vector<ObjectIndex> textures;
};

// Backgroud
struct background_section : object3d_section
{
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
};

// Transformable
struct transformable_section : object3d_section
{
	Boolean has_component_transform;
	Vector3D translation;
	Vector3D scale;
	Float32 orientation_angle;
	Vector3D orientation_axis;
	Boolean has_general_transform;
	Matrix transform;
};

// Node
struct node_section : transformable_section
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
};

// Camera
struct camera_section : node_section
{
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
};

// CompositionMode
struct composition_mode_section : object3d_section
{
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
};

// Fog
struct fog_section : object3d_section
{
	enum
	{
		object_type = 7,
	};

	ColorRGB color;
	Byte mode;
	Float32 dencity;
	Float32 near;
	Float32 far;
};

// Group
struct group_section : node_section
{
	enum
	{
		object_type = 9,
	};

	std::vector<ObjectIndex> children;
	Boolean is_lod_enabled;
	Float16 hysteresis;
	Float16 offset;
};

// ImageBase
struct image_base_section : object3d_section
{
	union
	{
		Int32 v20;
		Byte v10;
	} format;
	Boolean is_mutable;
	UInt32 width;
	UInt32 heigth;
};

// Image2D
struct image2d_section : image_base_section
{
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
};

// IndexBuffer
struct index_buffer_section : object3d_section
{
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

	enum
	{
		object_type = 27,
	};

	Byte encoding;
	Boolean is_immutable;
	Byte primitive_type;
	Byte strip_encoding;

	union_var primitime_count;
	union_array strip_lengths;
	union_var start_index;
	union_array indices;
	union_array index_deltas;
};

// Keyframe sequence
struct keyframe_sequence_section : object3d_section
{
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
		std::vector<Float32> vector_bias;
		std::vector<Float32> vector_scale;
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

	std::vector<event_s> events;

};


// Light
struct light_section : node_section
{
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
};

// Material
struct material_section : object3d_section
{
	enum
	{
		object_type = 13,
	};
	ColorRGB ambientColor;
	ColorRGBA diffuseColor;
	ColorRGB emissiveColor;
	ColorRGB specularColor;
	Float32 shininess;
	Boolean vertex_color_tracking_enabled;
};

// Mesh
struct mesh_section : node_section
{
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
		ObjectIndex morphTarget;
		Float32 initial_weight;
	};

	ObjectIndex vertex_buffer;
	UInt32 submesh_count;
	std::vector<submesh_s> submeshes;

	std::vector<target_buf_s> target_buffers;
	std::vector<UInt32> morph_subset;
};

// MorphingMesh
struct morphing_mesh_section : mesh_section
{
	enum
	{
		object_type = 15,
	};
};

// PolygonMode
struct polygon_mode_section : object3d_section
{
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
};

// SkinnedMesh
struct skinned_mesh_section : mesh_section
{
	enum
	{
		object_type = 16,
	};

	struct bone_s
	{
		ObjectIndex transform_node;
		UInt32 first_vertex;
		UInt32 vertex_count;
		Int32 weght;
	};

	ObjectIndex skeleton;
	Boolean is_using_add_transform;
	std::vector<bone_s> bones;
};

// Sprite3D
struct sprite3d_section : node_section
{
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
};

// Texture
struct texture_section : transformable_section
{
	ObjectIndex image;
	Byte level_filter;
	Byte image_filter;
};

// Texture2D
struct texture2d_section : texture_section
{
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
};

// TriangleStripArray
struct triangle_strip_array_section
{
	enum
	{
		object_type = 11,
	};
};

// VertexArray
struct vertex_array_section : object3d_section
{
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
};

// VertexBuffer
struct vertex_buffer_section : object3d_section
{
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
		Float32 default_attribute_value;
	};

	ColorRGBA default_color;
	ObjectIndex position;
	Float32 position_bias[3];
	Float32 position_scale;

	ObjectIndex normals;
	ObjectIndex colors;

	std::vector<coords_s> textures;

	Boolean is_immutable;
	ObjectIndex pointSizes;
	Float32 default_point_size;

	ObjectIndex bone_indices;
	ObjectIndex bone_weights;
	std::vector<attribute_s> attributes;
};

// World
struct world_section : group_section
{
	enum
	{
		object_type = 22,
	};

	ObjectIndex active_camera;
	ObjectIndex background;
};

// Blender
struct blender_section : object3d_section
{
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
};

// DynamicImage2D
struct dynamic2d_section : object3d_section
{
	enum
	{
		object_type = 24,
	};
};

// Shader
struct shader_section : object3d_section
{
	StringUTF8 source;
};

// FragmentShader
struct fragment_shader_section : shader_section
{
	enum
	{
		object_type = 25,
	};
};

// ImageCube
struct image_cube_section : image_base_section
{
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
	face_s mapmaps[6];
};

// PointSpriteMode
struct point_sprite_mode_section : object3d_section
{
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
};

// RenderPass
struct render_pass_section : object3d_section
{
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
	Float32 depth_range_Far;
	Boolean is_viewport_set;

	Int32 viewport_x;
	Int32 viewport_y;
	Int32 viewport_width;
	Int32 viewport_height;
};

// RenderTarget
struct render_target_section : object3d_section
{
	enum
	{
		object_type = 30,
	};

	ObjectIndex target;
	Byte target_level;
	Byte target_face;
};

// ShaderAppearance
struct shader_appearance_section : appearance_base_section
{
	enum
	{
		object_type = 31,
	};

	ObjectIndex shader_program;
	std::vector<ObjectIndex> shader_uniforms;
	Boolean is_validate_enabled;
};

// ShaderProgram
struct shader_program_section : object3d_section
{
	enum
	{
		object_type = 32,
	};

	ObjectIndex fragment_shader;
	ObjectIndex vertex_shader;
};

// ShaderUniforms
struct shader_uniforms_section : object3d_section
{
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
};

// Stencil
struct stencil_section : object3d_section
{
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
};

// TextureCombiner
struct texture_combiner_section : object3d_section
{
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
};

// TextureCube
struct texture_cube_section : texture_section
{
	enum
	{
		object_type = 36,
	};
};

// VertexShader
struct vertex_shader_section : shader_section
{
	enum
	{
		object_type = 37,
	};
};

#endif//__M3G_FORMAT_H__
