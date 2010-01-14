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

#endif//__M3G_FORMAT_H__
