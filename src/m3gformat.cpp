/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  m3gformat.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/18/2010 07:15:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#include "m3gformat.h"
#include "type_props.h"


int const SECTION_COUNT = 256;
typedef base_object* (*make_t)();
make_t create_object[SECTION_COUNT];

base_object* base_object::make(int obj_type)
{
	if (create_object[obj_type])
		return create_object[obj_type]();
	return NULL;
}

template<class T>
void register_object()
{
	create_object[T::object_type] = T::make;
}

struct object_registrator
{
	object_registrator()
	{
		for (int i = 0; i < SECTION_COUNT; ++i)
			create_object[i] = NULL;

		//
		register_object<header_object>();
		register_object<external_ref_object>();
		register_object<external_image_ref_object>();
		register_object<external_object_ref_object>();
		register_object<animation_controller_object>();
//		register_object<animation_track_object>();
//		register_object<appearance_object>();
//		register_object<background_object>();
//		register_object<camera_object>();
//		register_object<composition_mode_object>();
//		register_object<fog_object>();
//		register_object<polygon_mode_object>();
//		register_object<group_object>();
//		register_object<image2d_object>();
//		register_object<triangle_strip_array_object>();
//		register_object<light_object>();
//		register_object<material_object>();
//		register_object<mesh_object>();
//		register_object<morphing_mesh_object>();
//		register_object<skinned_mesh_object>();
//		register_object<texture2d_object>();
//		register_object<sprite3d_object>();
//		register_object<keyframe_sequence_object>();
//		register_object<vertex_array_object>();
//		register_object<vertex_buffer_object>();
//		register_object<world_object>();
//		register_object<blender_object>();
//		register_object<dynamic2d_object>();
//		register_object<fragment_shader_object>();
//		register_object<image_cube_object>();
//		register_object<index_buffer_object>();
//		register_object<point_sprite_mode_object>();
//		register_object<render_pass_object>();
//		register_object<render_target_object>();
//		register_object<shader_appearance_object>();
//		register_object<shader_program_object>();
//		register_object<shader_uniforms_object>();
//		register_object<stencil_object>();
//		register_object<texture_combiner_object>();
//		register_object<texture_cube_object>();
//		register_object<vertex_shader_object>();
	}
} do_object_registrator;
/*
// Object3D
int object3d_object::load(Stream& strm, int version)
{
	int size = 0;
	UInt32 count;
	size += strm.read(&user_id);

	size += strm.read(&count);
	for (unsigned int i = 0; i < count; ++i)
	{
		anim_track_s track;
		size += strm.read(&track.animation_track);
		if (version == M3G_FILE_FORMAT_20)
			size = strm.read(&track.animation_track_index);
		animation_tracks.push_back(track);
	}

	size += strm.read(&count);
	for (unsigned int i = 0; i < count; ++i)
	{
		parameter_s param;
		size += strm.read(&param.parameter_id);
		size += strm.read_varray(&param.parameter_value);
		parameters.push_back(param);
	}

	if (version == M3G_FILE_FORMAT_20)
		size += strm.read(&animation_enabled);

	return size;
}

void object3d_object::print(FILE* out, std::string const &indent, int version)
{
//	UInt32 count;

//	OBJECT_PRINT_START("Object3D");
//	print_value(out, new_indent, "userID", user_id);
//	count = animation_tracks.size();
//	print_value(out, new_indent, "animationTrackCount", count);
//	for (int i = 0; i < count; ++i)
//	{
//		print_value_oi(out, new_indent, "animationTrack",
//			animation_tracks[i].animation_track);
//		if (version == M3G_FILE_FORMAT_20)
//			print_value(out, new_indent, "animationTrackIndex",
//				animation_tracks[i].animation_track_index);
//	}
//	count = parameters.size();
//	print_value(out, new_indent, "userParameterCount", count);
//	for (int i = 0; i < count; ++i)
//	{
//		print_value(out, new_indent, "parameterID",
//			parameters[i].parameter_id);
//		print_varray(out, new_indent, "parameterValue",
//			parameters[i].parameter_value);
//	}
//	if (version == M3G_FILE_FORMAT_20)
//		print_value(out, new_indent, "animationEnabled",
//			animation_enabled);
//	OBJECT_PRINT_END();
}

// AnimationController
int animation_controller_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&speed);
	size += strm.read(&weight);
	size += strm.read(&active_interval_start);
	size += strm.read(&active_interval_end);
	size += strm.read(&reference_sequence_time);
	size += strm.read(&reference_world_time);
	return size;
}

void animation_controller_object::print(FILE* out, std::string const &indent,
	int version)
{
//	OBJECT_PRINT_START("AnimationController");
//	object3d_object::print(out, new_indent, version);
//
//	print_value(out, new_indent, "speed", speed);
//	print_value(out, new_indent, "weight", weight);
//	print_value(out, new_indent, "activeIntervalStart",
//		active_interval_start);
//	print_value(out, new_indent, "activeIntervalEnd",
//		active_interval_end);
//	print_value(out, new_indent, "referenceSequenceTime",
//		reference_sequence_time);
//	print_value(out, new_indent, "referenceWorldTime",
//		reference_world_time);
//
//	OBJECT_PRINT_END();
}

//AnimationTrack
int animation_track_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&keyframe_sequence);
	size += strm.read(&animation_controller);
	if ( version == M3G_FILE_FORMAT_20)
	{
		size += strm.read(&property_id.v20);
		if (property_id.v20 >= SHADERVARIABLE_FLOAT &&
			property_id.v20 <= SHADERVARIABLE_SAMPLER_CUBE)
		{
			size += strm.read(&is_normalize_enabled);
		}
	}
	else
	{
		size += strm.read(&property_id.v10);
	}
	return size;
}

void animation_track_object::print(FILE* out, std::string const &indent,
	int version)
{
//	OBJECT_PRINT_START("AnimationTrack");
//	object3d_object::print(out, new_indent, version);
//
//	print_value_oi(out, new_indent, "keyframeSequence",
//		keyframe_sequence);
//	print_value_oi(out, new_indent, "animationController",
//		animation_controller);
//	if (version == M3G_FILE_FORMAT_20)
//	{
//		print_value(out, new_indent, "propertyID", property_id.v20);
//		if (property_id.v20 >= SHADERVARIABLE_FLOAT &&
//			property_id.v20 <= SHADERVARIABLE_SAMPLER_CUBE)
//			print_value(out, new_indent, "isNormalizedEnabled",
//				is_normalize_enabled);
//	}
//	else
//	{
//		print_value(out, new_indent, "propertyID", property_id.v10);
//	}
//
//	OBJECT_PRINT_END();
}

// AppearanceBase
int appearance_base_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);

	if (version == M3G_FILE_FORMAT_20)
	{
		size += strm.read(&layer.v20);
	}
	else
	{
		size += strm.read(&layer.v10);
	}

	size += strm.read(&compositing_mode);

	if (version == M3G_FILE_FORMAT_20)
	{
		size += strm.read(&polygon_mode);
		size += strm.read(&is_depth_sort_enabled);
	}
	return size;
}

void appearance_base_object::print(FILE* out, std::string const &indent,
	int version)
{
//	OBJECT_PRINT_START("AppearanceBase");
//	object3d_object::print(out, new_indent, version);
//
//	if (version == M3G_FILE_FORMAT_10)
//	{
//		print_value(out, new_indent, "layer", layer.v10);
//	}
//	else
//	{
//		print_value(out, new_indent, "layer", layer.v20);
//	}
//	print_value_oi(out, new_indent, "compositingMode", compositing_mode);
//
//	if(version == M3G_FILE_FORMAT_20)
//	{
//		print_value_oi(out, new_indent, "polygon_mode", polygon_mode);
//		print_value(out, new_indent, "isDepthSortEnabled",
//			is_depth_sort_enabled);
//	}
//
//	OBJECT_PRINT_END();
}

// Appearance
int appearance_object::load(Stream& strm, int version)
{
	int size = 0;
	size += appearance_base_object::load(strm, version);
	size += strm.read(&fog);

	if (version == M3G_FILE_FORMAT_20)
	{
		size += strm.read(&point_sprite_mode);
	}
	else
	{
		size += strm.read(&polygon_mode);
	}

	size += strm.read(&material);
	size += strm.read_varray(&textures);
	return size;
}
void appearance_object::print(FILE* out, std::string const &indent, int version)
{
//	OBJECT_PRINT_START("Appearance");
//	appearance_base_object::print(out, new_indent, version);
//
//	print_value_oi(out, new_indent, "fog", fog);
//	if (version == M3G_FILE_FORMAT_20)
//	{
//		print_value_oi(out, new_indent, "pointSpriteMode",
//			point_sprite_mode);
//	}
//	else
//	{
//		print_value_oi(out, new_indent, "polygonMode",
//			polygon_mode);
//	}
//	print_value_oi(out, new_indent, "material", material);
//	print_varray_oi(out, new_indent, "textures", textures);
//
//	OBJECT_PRINT_END();
}

// Backgroud
int background_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&background_color);
	size += strm.read(&background_image);
	size += strm.read(&background_image_mode_x);
	size += strm.read(&background_image_mode_y);
	size += strm.read(&crop_x);
	size += strm.read(&crop_y);
	size += strm.read(&crop_width);
	size += strm.read(&crop_heigth);
	size += strm.read(&depth_clear_enabled);

	if (version == M3G_FILE_FORMAT_20)
	{
		size += strm.read(&depth);
		size += strm.read(&stencil);
		size += strm.read(&stencil_clear_mask);
		size += strm.read(&color_clear_mask);
	}
	else
	{
		size += strm.read(&color_clear_enabled);
	}
	return size;
}
void background_object::print(FILE* out, std::string const &indent, int version)
{
//	OBJECT_PRINT_START("Background");
//	object3d_object::print(out, new_indent, version);
//
//	print_value(out, new_indent, "backgroudColor", background_color);
//	print_value_oi(out, new_indent, "backgroungImage", background_image);
//	print_value(out, new_indent, "backgroundImageModeX",
//		background_image_mode_x);
//	print_value(out, new_indent, "backgroundImageModeY",
//		background_image_mode_y);
//	print_value(out, new_indent, "cropX", crop_x);
//	print_value(out, new_indent, "cropY", crop_y);
//	print_value(out, new_indent, "cropWidth", crop_width);
//	print_value(out, new_indent, "cropHeight", crop_heigth);
//	print_value(out, new_indent, "depthClearEnabled", depth_clear_enabled);
//	if (version == M3G_FILE_FORMAT_20)
//	{
//		print_value(out, new_indent, "depth", depth);
//		print_value(out, new_indent, "stencil", stencil);
//		print_value(out, new_indent, "stencilClearmask",
//			stencil_clear_mask);
//		print_value(out, new_indent, "colorClearMask",
//			color_clear_mask);
//	}
//	else
//	{
//		print_value(out, new_indent, "colorClearEnabled",
//			color_clear_enabled);
//	}
//
//	OBJECT_PRINT_END();
}

// Transformable
int transformable_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&has_component_transform);

	if (has_component_transform)
	{
		size += strm.read(&translation);
		size += strm.read(&scale);
		size += strm.read(&orientation_angle);
		size += strm.read(&orientation_axis);
	}

	size += strm.read(&has_general_transform);

	if (has_general_transform)
	{
		size += strm.read(&transform);
	}

	return size;
}
void transformable_object::print(FILE* out, std::string const &indent,
	int version)
{
//	OBJECT_PRINT_START("Transformable");
//	object3d_object::print(out, new_indent, version);
//
//	print_value(out, new_indent, "hasComponentTransform",
//		has_component_transform);
//	if (has_component_transform)
//	{
//		print_value(out, new_indent, "translation", translation);
//		print_value(out, new_indent, "scale", scale);
//		print_value(out, new_indent, "orientationAngle",
//			orientation_angle);
//		print_value(out, new_indent, "oritntationAxis",
//			orientation_axis);
//	}
//	print_value(out, new_indent, "hasGenetalTransform",
//		has_general_transform);
//
//	if (has_general_transform)
//		print_value(out, new_indent, "transform", transform);
//
//	OBJECT_PRINT_END();
}

// Node
int node_object::load(Stream& strm, int version)
{
	int size = 0;
	size += transformable_object::load(strm, version);
	size += strm.read(&enable_rendering);
	size += strm.read(&enable_picking);
	size += strm.read(&alpha_factor);
	size += strm.read(&scope);
	size += strm.read(&has_alignment);

	if (has_alignment)
	{
		size += strm.read(&z_target);
		size += strm.read(&y_target);
		size += strm.read(&z_reference);
		size += strm.read(&y_reference);
	}

	if (version == M3G_FILE_FORMAT_20)
	{
		size += strm.read(&has_bounding_box);
		if (has_bounding_box)
		{
			size += strm.read(&bound_min_x);
			size += strm.read(&bound_max_x);
			size += strm.read(&bound_min_y);
			size += strm.read(&bound_max_y);
			size += strm.read(&bound_min_z);
			size += strm.read(&bound_max_z);
		}

		size += strm.read(&has_bounding_box);
		if (has_bounding_sphere)
		{
			size += strm.read(&bound_center_x);
			size += strm.read(&bound_center_y);
			size += strm.read(&bound_center_z);
			size += strm.read(&bound_radius);
		}

		size += strm.read(&collision_enabled);
		size += strm.read(&has_collision_shape);
		if (has_collision_shape)
		{
			size += strm.read(&orientations);
			size += strm.read_fix_array(min, 13);
			size += strm.read_fix_array(max, 13);
		}

		size += strm.read(&lod_resolution);
	}
	return size;
}
void node_object::print(FILE* out, std::string const &indent, int version)
{
//	OBJECT_PRINT_START("Node");
//	transformable_object::print(out, new_indent, version);
//
//	print_value(out, new_indent, "enableRendering", enable_rendering);
//	print_value(out, new_indent, "enablePicking", enable_picking);
//	print_value(out, new_indent, "alphaFactor", alpha_factor);
//	print_value(out, new_indent, "scope", scope);
//	print_value(out, new_indent, "hasAlignment", has_alignment);
//	if (has_alignment)
//	{
//		print_value(out, new_indent, "zTarget", z_target);
//		print_value(out, new_indent, "yTarget", y_target);
//		print_value_fi(out, new_indent, "zReference", z_reference);
//		print_value_fi(out, new_indent, "yReference", y_reference);
//	}
//	if (version == M3G_FILE_FORMAT_20)
//	{
//		print_value(out, new_indent, "hasBoundingBox",
//			has_bounding_box);
//		if (has_bounding_box)
//		{
//			print_value(out, new_indent, "boundMinX",
//				bound_min_x);
//			print_value(out, new_indent, "boundMaxX",
//				bound_max_x);
//			print_value(out, new_indent, "boundMinY",
//				bound_min_y);
//			print_value(out, new_indent, "boundMaxY",
//				bound_max_y);
//			print_value(out, new_indent, "bountMinZ",
//				bound_min_z);
//			print_value(out, new_indent, "bountMaxZ",
//				bound_max_z);
//		}
//		print_value(out, new_indent, "hasBoudingSphere",
//			has_bounding_sphere);
//		if (has_bounding_sphere)
//		{
//			print_value(out, new_indent, "boundCenterX",
//				bound_center_x);
//			print_value(out, new_indent, "boundCenterY",
//				bound_center_y);
//			print_value(out, new_indent, "boundCenterZ",
//				bound_center_z);
//			print_value(out, new_indent, "boudnRadius",
//				bound_radius);
//		}
//		print_value(out, new_indent, "collisionEnabled",
//			collision_enabled);
//		print_value(out, new_indent, "hasCollisionShape",
//			has_collision_shape);
//		if (has_collision_shape)
//		{
//			print_value(out, new_indent, "orientations",
//				orientations);
//			print_array(out, new_indent, "min", min, 13);
//			print_array(out, new_indent, "max", max, 13);
//		}
//		print_value(out, new_indent, "LODResolution", lod_resolution);
//	}
//
//	OBJECT_PRINT_END();
}

// Camera
int camera_object::load(Stream& strm, int version)
{
	int size = 0;
	size += node_object::load(strm, version);
	size += strm.read(&projection_type);
	if (projection_type == CAMERA_GENERIC)
	{
		size += strm.read(&projection_matrix);
	}
	else if (version == M3G_FILE_FORMAT_20 &&
		projection_type == CAMERA_SCREEN)
	{
		size += strm.read(&x);
		size += strm.read(&y);
		size += strm.read(&width);
		size += strm.read(&height);
	}
	else
	{
		size += strm.read(&fovy);
		size += strm.read(&aspect_ratio);
		size += strm.read(&near);
		size += strm.read(&far);
	}
	return size;
}
void camera_object::print(FILE* out, std::string const &indent, int version)
{
//	OBJECT_PRINT_START("Camera");
//	node_object::print(out, new_indent, version);
//
//	print_value(out, new_indent, "projectionType", projection_type);
//	if (projection_type == CAMERA_GENERIC)
//	{
//		print_value(out, new_indent, "projectionMatrix",
//			projection_matrix);
//	}
//	else if (version == M3G_FILE_FORMAT_20 &&
//		projection_type == CAMERA_SCREEN)
//	{
//		print_value(out, new_indent, "x", x);
//		print_value(out, new_indent, "y", y);
//		print_value(out, new_indent, "width", width);
//		print_value(out, new_indent, "height", height);
//	}
//	else
//	{
//		print_value(out, new_indent, "fovy", fovy);
//		print_value(out, new_indent, "AspectRatio", aspect_ratio);
//		print_value(out, new_indent, "near", near);
//		print_value(out, new_indent, "far", far);
//	}
//
//	OBJECT_PRINT_END();
}

// CompositionMode
int composition_mode_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&depth_test_enabled);
	size += strm.read(&depth_write_enabled);

	if (version == M3G_FILE_FORMAT_10)
	{
		size += strm.read(&color_write_enabled);
		size += strm.read(&alpha_write_enabled);
	}

	size += strm.read(&blending);
	size += strm.read(&alpha_threshold);
	size += strm.read(&depth_offset_factor);
	size += strm.read(&depth_offset_units);

	if (version == M3G_FILE_FORMAT_20)
	{
		size += strm.read(&depth_test);
		size += strm.read(&alpha_test);
		size += strm.read(&blender);
		size += strm.read(&stencil);
		size += strm.read(&color_write_mask);
	}
	return size;
}
void composition_mode_object::print(FILE* out, std::string const &indent,
	int version)
{
//	OBJECT_PRINT_START("CompositingMode");
//	object3d_object::print(out, new_indent, version);
//
//	print_value(out, new_indent, "depthTestEnabled",
//		depth_test_enabled);
//	print_value(out, new_indent, "depthWriteEnabled",
//		depth_write_enabled);
//	if (version == M3G_FILE_FORMAT_10)
//	{
//		print_value(out, new_indent, "colorWriteEnabled",
//			color_write_enabled);
//		print_value(out, new_indent, "alphaWriteEnabled",
//			alpha_write_enabled);
//	}
//	print_value(out, new_indent, "blending", blending);
//	print_value(out, new_indent, "alpha_threshold", alpha_threshold);
//	print_value(out, new_indent, "depthOffsetFactor", depth_offset_factor);
//	print_value(out, new_indent, "depthOffsetUnits", depth_offset_units);
//	if (version == M3G_FILE_FORMAT_20)
//	{
//		print_value(out, new_indent, "depthTest", depth_test);
//		print_value(out, new_indent, "alphaTest", alpha_test);
//		print_value_oi(out, new_indent, "blender", blender);
//		print_value_oi(out, new_indent, "stencil", stencil);
//		print_value(out, new_indent, "colorWriteMask",
//			color_write_mask);
//	}
//
//	OBJECT_PRINT_END();
}

// Fog
int fog_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&color);
	size += strm.read(&mode);

	if (mode == FOG_EXPONENTIAL || (version == M3G_FILE_FORMAT_10
		&& mode == FOG_EXPONENTIAL_SQUARED))
	{
		size += strm.read(&density);
	}
	else if (mode == FOG_LINEAR)
	{
		size += strm.read(&near);
		size += strm.read(&far);
	}
	return size;
}
void fog_object::print(FILE* out, std::string const &indent, int version)
{
//	OBJECT_PRINT_START("Fog");
//	object3d_object::print(out, new_indent, version);
//
//	print_value(out, new_indent, "color", color);
//	print_value(out, new_indent, "mode", mode);
//	if (mode == FOG_EXPONENTIAL || (version == M3G_FILE_FORMAT_10
//		&& mode == FOG_EXPONENTIAL_SQUARED))
//		print_value(out, new_indent, "density", density);
//	else if (mode == FOG_LINEAR)
//	{
//		print_value(out, new_indent, "near", near);
//		print_value(out, new_indent, "far", far);
//	}
//
//	OBJECT_PRINT_END();
}

// Group
int group_object::load(Stream& strm, int version)
{
	int size = 0;
	size += node_object::load(strm, version);
	size += strm.read_varray(&children);

	if (version == M3G_FILE_FORMAT_20)
	{
		size += strm.read(&is_lod_enabled);
		size += strm.read(&hysteresis);
		size += strm.read(&offset);
	}
	return size;
}
void group_object::print(FILE* out, std::string const &indent, int version)
{
//	OBJECT_PRINT_START("Group");
//	node_object::print(out, new_indent, version);
//
//	print_varray(out, new_indent, "children", children);
//	if (version == M3G_FILE_FORMAT_20)
//	{
//		print_value(out, new_indent, "isLodEnabled", is_lod_enabled);
//		print_value(out, new_indent, "hysteresis", hysteresis);
//		print_value(out, new_indent, "offset", offset);
//	}
//
//	OBJECT_PRINT_END();
}

// ImageBase
int image_base_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	if (version == M3G_FILE_FORMAT_20)
	{
		size += strm.read(&format.v20);
	}
	else
	{
		size += strm.read(&format.v10);
	}
	size += strm.read(&is_mutable);
	size += strm.read(&width);
	size += strm.read(&height);
	return size;
}
void image_base_object::print(FILE* out, std::string const &indent, int version)
{
//	OBJECT_PRINT_START("ImageBase");
//	object3d_object::print(out, new_indent, version);
//
//	if (version == M3G_FILE_FORMAT_20)
//	{
//		print_value(out, new_indent, "format", format.v20);
//	}
//	else
//	{
//		print_value(out, new_indent, "format", format.v10);
//	}
//
//	print_value(out, new_indent, "isMutable", is_mutable);
//	print_value(out, new_indent, "width", width);
//	print_value(out, new_indent, "height", height);
//
//	OBJECT_PRINT_END();
}

// Image2D
int image2d_object::load(Stream& strm, int version)
{
	int size = 0;
	size += image_base_object::load(strm, version);
	if (is_mutable == false)
	{
		size += strm.read_varray(&palette);
		size += strm.read_varray(&base_pixels);

		if (version == M3G_FILE_FORMAT_20)
		{
			size += strm.read(&mipmap_count);
			for (int i = 0; i < mipmap_count; ++i)
			{
				mipmap_s mm;
				size += strm.read(&mm.mipmap_pixels);
				mipmaps.push_back(mm);
			}
		}
	}
	return size;
}
void image2d_object::print(FILE* out, std::string const &indent, int version)
{
//	OBJECT_PRINT_START("Image2D");
//	image_base_object::print(out, new_indent, version);
//
//	if (is_mutable == false)
//	{
//		print_varray(out, new_indent, "palette", palette);
//		print_varray(out, new_indent, "basePixels", base_pixels);
//
//		if (version == M3G_FILE_FORMAT_20)
//		{
//			print_value(out, new_indent, "mipmapCount",
//				mipmap_count);
//			for (int i = 0; i < mipmap_count; ++i)
//			{
//				print_varray(out, new_indent, "mipmapPixels",
//					mipmaps[i].mipmap_pixels);
//			}
//		}
//	}
//
//	OBJECT_PRINT_END();
}

// IndexBuffer
int index_buffer_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&encoding);

	if (version == M3G_FILE_FORMAT_20)
	{
		size += strm.read(&is_immutable);
		size += strm.read(&primitive_type);
		size += strm.read(&strip_encoding);
		if (strip_encoding == 0 || strip_encoding == 128)
		{
			size += strm.read(&primitive_count._uint32);
			if (strip_encoding == 128)
				size += strm.read_array(
					&strip_lengths._uint32,
					primitive_count._uint32);
		}
		else if (strip_encoding == 1 || strip_encoding == 129)
		{
			size += strm.read(&primitive_count._byte);
			if (strip_encoding == 129)
				size += strm.read_array(
					&strip_lengths._byte,
					primitive_count._byte);
		}
		else if (strip_encoding = 2 || strip_encoding == 130)
		{
			size += strm.read(&primitive_count._uint16);
			if (strip_encoding == 130)
				size += strm.read_array(
					&strip_lengths._uint16,
					primitive_count._uint16);
		}
	}
	if (encoding == 0)
		size += strm.read(&start_index._uint32);
	else if (encoding == 1)
		size += strm.read(&start_index._byte);
	else if (encoding == 2)
		size += strm.read(&start_index._uint16);
	else if (encoding == 128)
		size += strm.read_varray(&indices._uint32);
	else if (encoding == 129)
		size += strm.read_varray(&indices._byte);
	else if (encoding == 130)
		size += strm.read_varray(&indices._uint16);
	else if (version == M3G_FILE_FORMAT_20)
	{
		if (encoding == 192)
			size += strm.read_varray(&index_deltas._i32);
		else if (encoding == 193)
			size += strm.read_varray(&index_deltas._byte);
		else if (encoding == 194)
			size += strm.read_varray(&index_deltas._i16);
	}
	return size;
}
void index_buffer_object::print(FILE* out, std::string const &indent,
	int version)
{
//	OBJECT_PRINT_START("IndexBuffer");
//	object3d_object::print(out, new_indent, version);
//
//	print_value(out, new_indent, "encoding", encoding);
//
//	if (version == M3G_FILE_FORMAT_20)
//	{
//		print_value(out, new_indent, "isImmutable", is_immutable);
//		print_value(out, new_indent, "primitiveType", primitive_type);
//		print_value(out, new_indent, "stripEncoding", strip_encoding);
//
//		if (strip_encoding == 0 || strip_encoding == 128)
//		{
//			print_value(out, new_indent, "primitiveCount",
//				primitive_count._uint32);
//			if (strip_encoding == 128)
//				print_array(out, new_indent, "stripLengths",
//					&strip_lengths._uint32.front(),
//					primitive_count._uint32);
//		}
//		else if (strip_encoding == 1 || strip_encoding == 129)
//		{
//			print_value(out, new_indent, "primitiveCount",
//				primitive_count._byte);
//			if (strip_encoding == 129)
//				print_array(out, new_indent, "stripLengths",
//					&strip_lengths._byte.front(),
//					primitive_count._byte);
//		}
//		else if (strip_encoding == 2 || strip_encoding == 130)
//		{
//			print_value(out, new_indent, "primitiveCount",
//				primitive_count._uint16);
//			if (strip_encoding == 130)
//				print_array(out, new_indent, "stripLengths",
//					&strip_lengths._uint16.front(),
//					primitive_count._uint16);
//		}
//	}
//
//	if (encoding == 0)
//		print_value(out, new_indent, "startIndex",
//			start_index._uint32);
//	else if (encoding == 1)
//		print_value(out, new_indent, "startIndex",
//			start_index._byte);
//	else if (encoding == 2)
//		print_value(out, new_indent, "startIndex",
//			start_index._uint16);
//	else if (encoding == 128)
//		print_varray(out, new_indent, "indices",
//			indices._uint32);
//	else if (encoding == 129)
//		print_varray(out, new_indent, "indices",
//			indices._byte);
//	else if (encoding == 130)
//		print_varray(out, new_indent, "indices",
//			indices._uint16);
//	else if (version == M3G_FILE_FORMAT_20)
//	{
//		if (encoding == 192)
//			print_varray(out, new_indent, "indexDeltas",
//				index_deltas._i32);
//		else if (encoding == 193)
//			print_varray(out, new_indent, "indexDeltas",
//				index_deltas._byte);
//		else if (encoding == 194)
//			print_varray(out, new_indent, "indexDeltas",
//				index_deltas._i16);
//	}
//
//	OBJECT_PRINT_END();
}

// Keyframe sequence
int keyframe_sequence_object::load(Stream& strm, int version)
{
	int size = 0;
	channel_count = 1;
	size += object3d_object::load(strm, version);
	size += strm.read(&interpolation);
	size += strm.read(&repeat_mode);
	size += strm.read(&encoding);
	size += strm.read(&duration);
	size += strm.read(&valid_range_first);
	size += strm.read(&valid_range_last);
	size += strm.read(&component_count);
	size += strm.read(&keyframe_count);

	if (version == M3G_FILE_FORMAT_20)
		size += strm.read(&channel_count);

	if (encoding == 0)
	{
		for (unsigned int i = 0; i < keyframe_count; ++i)
		{
			keyframe_s kf;
			size += strm.read(&kf.time);
			size += strm.read_array(
				&kf.vector_value._float32,
				component_count * channel_count);
			keyframes.push_back(kf);
		}
	}
	else if (encoding == 1)
	{
		size += strm.read_array(&vector_bias, component_count);
		size += strm.read_array(&vector_scale, component_count);
		for (unsigned int i = 0; i < keyframe_count; ++i)
		{
			keyframe_s kf;
			size += strm.read(&kf.time);
			size += strm.read_array(&kf.vector_value._byte,
				component_count * channel_count);
			keyframes.push_back(kf);
		}
	}
	else if (encoding == 2)
	{
		size += strm.read_array(&vector_bias, component_count);
		size += strm.read_array(&vector_scale, component_count);
		for (unsigned int i = 0; i < keyframe_count; ++i)
		{
			keyframe_s kf;
			size += strm.read(&kf.time);
			size += strm.read_array(
				&kf.vector_value._uint16,
				keyframe_count * channel_count);
			keyframes.push_back(kf);
		}
	}

	if (version == M3G_FILE_FORMAT_20)
	{
		UInt32 event_count;
		size += strm.read(&event_count);
		for (unsigned int i = 0; i < event_count; ++i)
		{
			event_s e;
			size += strm.read(&e.event_time);
			size += strm.read(&e.event_id);
			events.push_back(e);
		}
	}
	return size;
}
void keyframe_sequence_object::print(FILE* out, std::string const &indent,
	int version)
{
//	OBJECT_PRINT_START("KeyframeSequence");
//	object3d_object::print(out, new_indent, version);
//
//	print_value(out, new_indent, "interpolation", interpolation);
//	print_value(out, new_indent, "repeatMode", repeat_mode);
//	print_value(out, new_indent, "encoding", encoding);
//	print_value(out, new_indent, "duration", duration);
//	print_value(out, new_indent, "validRangeFirst", valid_range_first);
//	print_value(out, new_indent, "validRangeLast", valid_range_last);
//	print_value(out, new_indent, "componentCount", component_count);
//	print_value(out, new_indent, "keyframeCount", keyframe_count);
//
//	if (version == M3G_FILE_FORMAT_20)
//		print_value(out, new_indent, "channelCount", channel_count);
//
//	if (encoding == 0)
//	{
//		for (int i = 0; i < keyframe_count; ++i)
//		{
//			print_value(out, new_indent, "time",
//				keyframes[i].time);
//			print_array(out, new_indent, "vectorValue",
//				&keyframes[i].vector_value._float32.front(),
//				component_count * channel_count);
//		}
//	}
//	if (encoding == 1)
//	{
//		print_array(out, new_indent, "vectorBias",
//			&vector_bias.front(), component_count);
//		print_array(out, new_indent, "vectorScale",
//			&vector_scale.front(), component_count);
//
//		for (int i = 0; i < keyframe_count; ++i)
//		{
//			print_value(out, new_indent, "time",
//				keyframes[i].time);
//			print_array(out, new_indent, "vectorValue",
//				&keyframes[i].vector_value._byte.front(),
//				component_count * channel_count);
//		}
//	}
//	else if (encoding == 2)
//	{
//		print_array(out, new_indent, "vectorBias",
//			&vector_bias.front(), component_count);
//		print_array(out, new_indent, "vectorScale",
//			&vector_scale.front(), component_count);
//
//		for (int i = 0; i < keyframe_count; ++i)
//		{
//			print_value(out, new_indent, "time",
//				keyframes[i].time);
//			print_array(out, new_indent, "vectorValue",
//				&keyframes[i].vector_value._uint16.front(),
//				component_count * channel_count);
//		}
//	}
//
//	if (version == M3G_FILE_FORMAT_20)
//	{
//		UInt32 event_count = events.size();
//		print_value(out, new_indent, "eventCount", event_count);
//		for (int i = 0; i < event_count; ++i)
//		{
//			print_value(out, new_indent, "eventTime",
//				events[i].event_time);
//			print_value(out, new_indent, "eventID",
//				events[i].event_id);
//		}
//	}
//
//	OBJECT_PRINT_END();
}



// Light
int light_object::load(Stream& strm, int version)
{
	int size = 0;
	size += node_object::load(strm, version);
	size += strm.read(&attenuation_constant);
	size += strm.read(&attenuation_linear);
	size += strm.read(&attenuation_quadratic);
	size += strm.read(&color);
	size += strm.read(&mode);
	size += strm.read(&intensity);
	size += strm.read(&spot_angle);
	size += strm.read(&spot_exponent);
	return size;
}
void light_object::print(FILE* out, std::string const &indent, int version)
{
//	OBJECT_PRINT_START("Light");
//	node_object::print(out, new_indent, version);
//
//	print_value(out, new_indent, "attenuationConstant",
//		attenuation_constant);
//	print_value(out, new_indent, "attenuationLinear",
//		attenuation_linear);
//	print_value(out, new_indent, "attenuationQuadratic",
//		attenuation_quadratic);
//	print_value(out, new_indent, "color", color);
//	print_value(out, new_indent, "mode", mode);
//	print_value(out, new_indent, "intensity", intensity);
//	print_value(out, new_indent, "spotAngle", spot_angle);
//	print_value(out, new_indent, "spotExponent", spot_exponent);
//
//	OBJECT_PRINT_END();
}

// Material
int material_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&ambient_color);
	size += strm.read(&diffuse_color);
	size += strm.read(&emissive_color);
	size += strm.read(&specular_color);
	size += strm.read(&shininess);
	size += strm.read(&vertex_color_tracking_enabled);
	return size;
}
void material_object::print(FILE* out, std::string const &indent, int version)
{
//	OBJECT_PRINT_START("Material");
//	object3d_object::print(out, new_indent, version);
//
//	print_value(out, new_indent, "ambientColor", ambient_color);
//	print_value(out, new_indent, "diffuseColor", diffuse_color);
//	print_value(out, new_indent, "emissiveColor", emissive_color);
//	print_value(out, new_indent, "specularColor", specular_color);
//	print_value(out, new_indent, "shininess", shininess);
//	print_value(out, new_indent, "vertexColorTrackingEnabled",
//		vertex_color_tracking_enabled);
//
//	OBJECT_PRINT_END();
}

// Mesh
int mesh_object::load(Stream& strm, int version)
{
	int size = 0;
	size += node_object::load(strm, version);
	size += strm.read(&vertex_buffer);
	size += strm.read(&submesh_count);
	for (unsigned int i = 0; i < submesh_count; ++i)
	{
		submesh_s m;
		size += strm.read(&m.index_buffer);
		size += strm.read(&m.appearance);
		submeshes.push_back(m);
	}

	if (version == M3G_FILE_FORMAT_20)
	{
		UInt32 morph_target;
		size += strm.read(&morph_target);
		for (int i = 0; i < morph_target; ++i)
		{
			target_buf_s tb;
			size += strm.read(&tb.morph_target);
			size += strm.read(&tb.initial_weight);
			target_buffers.push_back(tb);
		}
		size += strm.read_varray(&morph_subset);
	}
	return size;
}
void mesh_object::print(FILE* out, std::string const &indent, int version)
{
//	OBJECT_PRINT_START("Mesh");
//	node_object::print(out, new_indent, version);
//
//	print_value_oi(out, new_indent, "vertexBuffer", vertex_buffer);
//	print_value(out, new_indent, "submeshCount", submesh_count);
//	for (int i = 0; i < submesh_count; ++i)
//	{
//		print_value_oi(out, new_indent, "indexBuffer",
//			submeshes[i].index_buffer);
//		print_value_oi(out, new_indent, "appearance",
//			submeshes[i].appearance);
//	}
//
//	if (version == M3G_FILE_FORMAT_20)
//	{
//		UInt32 morph_target_count = target_buffers.size();
//		print_value(out, new_indent, "morphTargetCount",
//			morph_target_count);
//		for (int i = 0; i < morph_target_count; ++i)
//		{
//			print_value_oi(out, new_indent, "morphTarget",
//				target_buffers[i].morph_target);
//			print_value(out, new_indent, "initialWeight",
//				target_buffers[i].initial_weight);
//		}
//		print_varray(out, new_indent, "morphSubset", morph_subset);
//	}
//
//	OBJECT_PRINT_END();
}

// MorphingMesh
int morphing_mesh_object::load(Stream& strm, int version)
{
	int size = 0;
	size += mesh_object::load(strm, version);
	if (version == M3G_FILE_FORMAT_10)
	{
		UInt32 morph_target;
		size += strm.read(&morph_target);
		for (unsigned int i = 0; i < morph_target; ++i)
		{
			target_buf_s tb;
			size += strm.read(&tb.morph_target);
			size += strm.read(&tb.initial_weight);
			target_buffers.push_back(tb);
		}
	}
	return size;
}
void morphing_mesh_object::print(FILE* out, std::string const &indent,
	int version)
{
//	OBJECT_PRINT_START("MorphingMesh");
//	mesh_object::print(out, new_indent, version);
//
//	if (version == M3G_FILE_FORMAT_10)
//	{
//		UInt32 morph_target_count = target_buffers.size();
//		print_value(out, new_indent, "morphTargetCount",
//			morph_target_count);
//		for (int i = 0; i < morph_target_count; ++i)
//		{
//			print_value_oi(out, new_indent, "morphTarget",
//				target_buffers[i].morph_target);
//			print_value(out, new_indent, "initialWeight",
//				target_buffers[i].initial_weight);
//		}
//	}
//
//	OBJECT_PRINT_END();
}

// PolygonMode
int polygon_mode_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&culling);
	size += strm.read(&shading);
	size += strm.read(&winding);
	size += strm.read(&two_sided_lighting_enabled);
	size += strm.read(&local_camera_lighting_enabled);
	size += strm.read(&perspective_correction_enabled);
	if (version == M3G_FILE_FORMAT_20)
		size += strm.read(&line_width);
	return size;
}
void polygon_mode_object::print(FILE* out, std::string const &indent,
	int version)
{
//	OBJECT_PRINT_START("PolygonMode");
//	object3d_object::print(out, new_indent, version);
//
//	print_value(out, new_indent, "culling", culling);
//	print_value(out, new_indent, "shading", shading);
//	print_value(out, new_indent, "winding", winding);
//	print_value(out, new_indent, "twoSidedLightingEnabled",
//		two_sided_lighting_enabled);
//	print_value(out, new_indent, "localCameraLightingEnabled",
//		local_camera_lighting_enabled);
//	print_value(out, new_indent, "perspectiveCorrectionEnabled",
//		perspective_correction_enabled);
//
//	if (version == M3G_FILE_FORMAT_20)
//		print_value(out, new_indent, "lineWidth", line_width);
//
//	OBJECT_PRINT_END();
}

// SkinnedMesh
int skinned_mesh_object::load(Stream& strm, int version)
{
	UInt32 ref_count;
	int size = 0;
	size += mesh_object::load(strm, version);
	size += strm.read(&skeleton);
	if (version == M3G_FILE_FORMAT_20)
		size += strm.read(&is_using_add_transform);
	size += strm.read(&ref_count);
	for (unsigned int i = 0; i < ref_count; ++i)
	{
		bone_s b;
		size += strm.read(&b.transform_node);
		if (is_using_add_transform)
		{
			size += strm.read(&b.first_vertex);
			size += strm.read(&b.vertex_count);
			size += strm.read(&b.weight);
		}
		bones.push_back(b);
	}
	return size;
}
void skinned_mesh_object::print(FILE* out, std::string const &indent,
	int version)
{
//	OBJECT_PRINT_START("SkinnedMesh");
//	mesh_object::print(out, new_indent, version);
//
//	print_value_oi(out, new_indent, "skeleton", skeleton);
//
//	if (version == M3G_FILE_FORMAT_20)
//		print_value(out, new_indent, "isUsingAddTransform",
//			is_using_add_transform);
//
//	UInt32 transform_reference_count = bones.size();
//	print_value(out, new_indent, "transformReferenceCount",
//		transform_reference_count);
//	for (int i = 0; i < transform_reference_count; ++i)
//	{
//		print_value_oi(out, new_indent, "transformNode",
//			bones[i].transform_node);
//		if (is_using_add_transform)
//		{
//			print_value(out, new_indent, "firstVertex",
//				bones[i].first_vertex);
//			print_value(out, new_indent, "vertexCount",
//				bones[i].vertex_count);
//			print_value(out, new_indent, "weight",
//				bones[i].weight);
//		}
//	}
//
//	OBJECT_PRINT_END();
}

// Sprite3D
int sprite3d_object::load(Stream& strm, int version)
{
	int size = 0;
	size += node_object::load(strm, version);
	size += strm.read(&image);
	size += strm.read(&appearance);
	size += strm.read(&is_scaled);
	size += strm.read(&crop_x);
	size += strm.read(&crop_y);
	size += strm.read(&crop_width);
	size += strm.read(&crop_height);
	return size;
}
void sprite3d_object::print(FILE* out, std::string const &indent, int version)
{
//	OBJECT_PRINT_START("Sprite3D");
//	node_object::print(out, new_indent, version);
//
//	print_value_oi(out, new_indent, "image", image);
//	print_value_oi(out, new_indent, "appearance", appearance);
//	print_value(out, new_indent, "isScaled", is_scaled);
//	print_value(out, new_indent, "cropX", crop_x);
//	print_value(out, new_indent, "cropY", crop_y);
//	print_value(out, new_indent, "cropWidth", crop_width);
//	print_value(out, new_indent, "cropHeight", crop_height);
//
//	OBJECT_PRINT_END();
}

// Texture
int texture_object::load(Stream& strm, int version)
{
	int size = 0;
	size += transformable_object::load(strm, version);
	size += strm.read(&image);
	if (version == M3G_FILE_FORMAT_20)
	{
		size += strm.read(&level_filter);
		size += strm.read(&image_filter);
	}
	return size;
}
void texture_object::print(FILE* out, std::string const &indent, int version)
{
//	OBJECT_PRINT_START("Texture");
//	transformable_object::print(out, new_indent, version);
//
//	print_value_oi(out, new_indent, "image", image);
//	if (version == M3G_FILE_FORMAT_20)
//	{
//		print_value(out, new_indent, "levelFilter", level_filter);
//		print_value(out, new_indent, "imageFilter", image_filter);
//	}
//
//	OBJECT_PRINT_END();
}

// Texture2D
int texture2d_object::load(Stream& strm, int version)
{
	int size = 0;
	size += texture_object::load(strm, version);
	if (version == M3G_FILE_FORMAT_20)
		size += strm.read(&blend_color.rgba);
	else
		size += strm.read(&blend_color.rgb);
	size += strm.read(&blending);
	size += strm.read(&wrapping_s);
	size += strm.read(&wrapping_t);
	if (version == M3G_FILE_FORMAT_20)
		size += strm.read(&combiner);
	else
	{
		size += strm.read(&level_filter);
		size += strm.read(&image_filter);
	}
	return size;
}
void texture2d_object::print(FILE* out, std::string const &indent, int version)
{
//	OBJECT_PRINT_START("Texture2D");
//	texture_object::print(out, new_indent, version);
//
//	if (version == M3G_FILE_FORMAT_20)
//		print_value(out, new_indent, "blendColor",
//			blend_color.rgba);
//	else
//		print_value(out, new_indent, "blendColor",
//			blend_color.rgb);
//
//	print_value(out, new_indent, "blending", blending);
//	print_value(out, new_indent, "wrappingS", wrapping_s);
//	print_value(out, new_indent, "wrappingT", wrapping_t);
//
//	if (version == M3G_FILE_FORMAT_20)
//		print_value_oi(out, new_indent, "combiner", combiner);
//	else
//	{
//		print_value(out, new_indent, "levelFilter", level_filter);
//		print_value(out, new_indent, "imageFilter", image_filter);
//	}
//
//	OBJECT_PRINT_END();
}

// TriangleStripArray
int triangle_strip_array_object::load(Stream& strm, int version)
{
	int size = 0;
	size += index_buffer_object::load(strm, version);

	if (version == M3G_FILE_FORMAT_10)
	{
		size += strm.read_varray(&strip_lengths._uint32);
	}
	return size;
}
void triangle_strip_array_object::print(FILE* out,
	std::string const &indent, int version)
{
//	OBJECT_PRINT_START("TriangleStripArray");
//	index_buffer_object::print(out, new_indent, version);
//
//	if (version == M3G_FILE_FORMAT_10)
//		print_varray(out, new_indent, "stripLengths",
//			strip_lengths._uint32);
//
//	OBJECT_PRINT_END();
}

// VertexArray
int vertex_array_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&component_type);
	size += strm.read(&component_count);
	size += strm.read(&encoding);
	size += strm.read(&vertex_count);

	for (int i = 0; i < vertex_count; ++i)
	{
		data_s v;
		if (component_type == VERTEXARRAY_BYTE)
			size += strm.read_array(&v._byte,
				component_count);
		else if (component_type == VERTEXARRAY_SHORT)
			size += strm.read_array(&v._i16,
				component_count);
		else if (version == M3G_FILE_FORMAT_20)
		{
			if (component_type == VERTEXARRAY_FIXED)
				size += strm.read_array(&v._i32,
					component_count);
			else if (component_type == VERTEXARRAY_HALF)
				size += strm.read_array(&v._float16,
					component_count);
			else if (component_type == VERTEXARRAY_FLOAT)
				size += strm.read_array(&v._float32,
					component_type);
		}
		components.push_back(v);
	}
	return size;
}

void vertex_array_object::print(FILE* out, std::string const &indent,
	int version)
{
//	OBJECT_PRINT_START("VertexArray");
//	object3d_object::print(out, new_indent, version);
//
//	print_value(out, new_indent, "componentType", component_type);
//	print_value(out, new_indent, "compoenntCount", component_count);
//	print_value(out, new_indent, "encoding", encoding);
//	print_value(out, new_indent, "vertexCount", vertex_count);
//
//	for (int i = 0; i < vertex_count; ++i)
//	{
//		if (component_type == VERTEXARRAY_BYTE)
//			print_array(out, new_indent, "components",
//				&components[i]._byte.front(),
//				component_count);
//		else if (component_type == VERTEXARRAY_SHORT)
//			print_array(out, new_indent, "components",
//				&components[i]._i16.front(),
//				component_count);
//		else if (version == M3G_FILE_FORMAT_20)
//		{
//			if (component_type == VERTEXARRAY_FIXED)
//				print_array(out, new_indent, "components",
//					&components[i]._i32.front(),
//					component_count);
//			else if (component_type == VERTEXARRAY_HALF)
//				; 
//			else if (component_type == VERTEXARRAY_FLOAT)
//				print_array(out, new_indent, "components",
//					&components[i]._float32.front(),
//					component_count);
//		}
//	}
//
//	OBJECT_PRINT_END();
}

// VertexBuffer
int vertex_buffer_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&default_color);
	size += strm.read(&positions);
	size += strm.read_fix_array(position_bias, 3);
	size += strm.read(&position_scale);
	size += strm.read(&normals);
	size += strm.read(&colors);

	UInt32 tex_count;
	size += strm.read(&tex_count);
	for (unsigned int i = 0; i < tex_count; ++i)
	{
		coords_s crd;
		size += strm.read(&crd.coord);
		size += strm.read_fix_array(crd.bias, 3);
		size += strm.read(&crd.scale);
		textures.push_back(crd);
	}

	if (version == M3G_FILE_FORMAT_20)
	{
		size += strm.read(&is_immutable);
		size += strm.read(&point_sizes);
		size += strm.read(&default_point_size);
		size += strm.read(&bone_indices);
		size += strm.read(&bone_weights);

		UInt32 attr_count;
		size += strm.read(&attr_count);
		for (unsigned int i = 0; i < attr_count; ++i)
		{
			attribute_s a;
			size += strm.read(&a.name);
			size += strm.read(&a.attribute);
			size += strm.read(&a._signed);
			size += strm.read(&a._normalized);
			size += strm.read_fix_array(
				a.default_attribute_value, 4);
			attributes.push_back(a);
		}
	}
	return size;
}
void vertex_buffer_object::print(FILE* out, std::string const &indent,
	int version)
{
//	OBJECT_PRINT_START("VertexBuffer");
//	object3d_object::print(out, new_indent, version);
//
//	print_value(out, new_indent, "defaultColor", default_color);
//	print_value_oi(out, new_indent, "positions", positions);
//	print_array(out, new_indent, "positionBias", position_bias, 3);
//	print_value(out, new_indent, "positionScale", position_scale);
//	print_value_oi(out, new_indent, "normals", normals);
//	print_value_oi(out, new_indent, "colors", colors);
//
//	UInt32 tex_count = textures.size();
//	print_value(out, new_indent, "texcoordsArrayCount", tex_count);
//	for (int i = 0; i < tex_count; ++i)
//	{
//		print_value_oi(out, new_indent, "texCoords",
//			textures[i].coord);
//		print_array(out, new_indent, "texCoordBias",
//			textures[i].bias, 3);
//		print_value(out, new_indent, "texCoordScale",
//			textures[i].scale);
//	}
//
//	if (version == M3G_FILE_FORMAT_20)
//	{
//		print_value(out, new_indent, "isImmutable", is_immutable);
//		print_value_oi(out, new_indent, "pointSizes", point_sizes);
//		print_value(out, new_indent, "defaultPointSize",
//			default_point_size);
//		print_value_oi(out, new_indent, "boneIndices", bone_indices);
//		print_value_oi(out, new_indent, "boneWeights", bone_weights);
//
//		UInt32 attr_count = attributes.size();;
//		print_value(out, new_indent, "namedAttributeCount",
//			attr_count);
//		for (int i = 0; i < attr_count; ++i)
//		{
//			print_value(out, new_indent, "name",
//				attributes[i].name);
//			print_value_oi(out, new_indent, "attribute",
//				attributes[i].attribute);
//			print_value(out, new_indent, "signed",
//				attributes[i]._signed);
//			print_value(out, new_indent, "normalized",
//				attributes[i]._normalized);
//			print_array(out, new_indent, "defaultAttributeValue",
//				attributes[i].default_attribute_value, 4);
//		}
//	}
//
//	OBJECT_PRINT_END();
}

// World
int world_object::load(Stream& strm, int version)
{
	int size = 0;
	size += group_object::load(strm, version);
	size += strm.read(&active_camera);
	size += strm.read(&background);
	return size;
}
void world_object::print(FILE* out, std::string const &indent, int version)
{
//	OBJECT_PRINT_START("World");
//	group_object::print(out, new_indent, version);
//
//	print_value_oi(out, new_indent, "activeCamera", active_camera);
//	print_value_oi(out, new_indent, "background", background);
//
//	OBJECT_PRINT_END();
}

// Blender
int blender_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&func_alpha);
	size += strm.read(&src_alpha);
	size += strm.read(&dst_alpha);
	size += strm.read(&func_color);
	size += strm.read(&src_color);
	size += strm.read(&dst_color);
	size += strm.read(&blend_color);
	return size;
}
void blender_object::print(FILE* out, std::string const &indent, int version)
{
	object3d_object::print(out, indent, version);
}

// DynamicImage2D
int dynamic2d_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	return size;
}
void dynamic2d_object::print(FILE* out, std::string const &indent, int version)
{
	object3d_object::print(out, indent, version);
}

// Shader
int shader_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&source);
	return size;
}
void shader_object::print(FILE* out, std::string const &indent, int version)
{
	object3d_object::print(out, indent, version);
}

// FragmentShader
int fragment_shader_object::load(Stream& strm, int version)
{
	int size = 0;
	size += shader_object::load(strm, version);
	return size;
}
void fragment_shader_object::print(FILE* out, std::string const &indent,
	int version)
{
	shader_object::print(out, indent, version);
}

// ImageCube
int image_cube_object::load(Stream& strm, int version)
{
	int size = 0;
	size += image_base_object::load(strm, version);

	if (!is_mutable)
	{
		for (int i = 0; i < 6; ++i)
		{
			size += strm.read_varray(&mipmaps[i].pixels);
			size += strm.read(&mipmaps[i].mipmap_count);
			for (int j = 0;
				j < mipmaps[i].mipmap_count; ++j)
			{
				face_s::mipmap_s mm;
				size += strm.read_varray(&mm.values);
				mipmaps[i].mipmap_pixels.push_back(mm);
			}
		}
	}
	return size;
}
void image_cube_object::print(FILE* out, std::string const &indent, int version)
{
	image_base_object::print(out, indent, version);
}

// PointSpriteMode
int point_sprite_mode_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&point_fade_threshold);
	size += strm.read(&point_attenuation_a);
	size += strm.read(&point_attenuation_b);
	size += strm.read(&point_attenuation_c);
	size += strm.read(&point_size_clamp_min);
	size += strm.read(&point_size_clamp_max);
	return size;
}
void point_sprite_mode_object::print(FILE* out, std::string const &indent,
	int version)
{
	object3d_object::print(out, indent, version);
}

// RenderPass
int render_pass_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&scene);
	size += strm.read(&camera);
	size += strm.read(&background);
	size += strm.read(&target);
	size += strm.read(&flags);
	size += strm.read(&depth_range_near);
	size += strm.read(&depth_range_far);
	size += strm.read(&is_viewport_set);
	if (is_viewport_set)
	{
		size += strm.read(&viewport_x);
		size += strm.read(&viewport_y);
		size += strm.read(&viewport_width);
		size += strm.read(&viewport_height);
	}
	return size;
}
void render_pass_object::print(FILE* out, std::string const &indent,
	int version)
{
	object3d_object::print(out, indent, version);
}

// RenderTarget
int render_target_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&target);
	size += strm.read(&target_level);
	size += strm.read(&target_face);
	return size;
}
void render_target_object::print(FILE* out, std::string const &indent,
	int version)
{
	object3d_object::print(out, indent, version);
}

// ShaderAppearance
int shader_appearance_object::load(Stream& strm, int version)
{
	int size = 0;
	size += appearance_base_object::load(strm, version);
	size += strm.read(&shader_program);
	size += strm.read_varray(&shader_uniforms);
	size += strm.read(&is_validate_enabled);
	return size;
}
void shader_appearance_object::print(FILE* out, std::string const &indent,
	int version)
{
	appearance_base_object::print(out, indent, version);
}

// ShaderProgram
int shader_program_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&fragment_shader);
	size += strm.read(&vertex_shader);
	return size;
}
void shader_program_object::print(FILE* out, std::string const &indent,
	int version)
{
	object3d_object::print(out, indent, version);
}

// ShaderUniforms
int shader_uniforms_object::load(Stream& strm, int version)
{
	UInt32 count;
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&count);
	for (unsigned int i = 0; i < count; ++i)
	{
		uniform_s u;
		size += strm.read(&u.name);
		size += strm.read(&u.type);
		size += strm.read(&u.binding_type);
		size += strm.read(&u.length);

		if (u.binding_type == 0)
		{
			if (u.type == SHADERVARIABLE_BOOL)
				size += strm.read_array(&u.value._bool,
					u.length);
			else if (u.type == SHADERVARIABLE_BVEC2)
				size += strm.read_array(&u.value._bool,
					2 * u.length);
			else if (u.type == SHADERVARIABLE_BVEC3)
				size += strm.read_array(&u.value._bool,
					3 * u.length);
			else if (u.type == SHADERVARIABLE_BVEC4)
				size += strm.read_array(&u.value._bool,
					4 * u.length);
			else if (u.type == SHADERVARIABLE_INT)
				size += strm.read_array(&u.value._i32,
					u.length);
			else if (u.type == SHADERVARIABLE_IVEC2)
				size += strm.read_array(&u.value._i32,
					2 * u.length);
			else if (u.type == SHADERVARIABLE_IVEC3)
				size += strm.read_array(&u.value._i32,
					3 * u.length);
			else if (u.type == SHADERVARIABLE_IVEC4)
				size += strm.read_array(&u.value._i32,
					4 * u.length);
			else if (u.type == SHADERVARIABLE_FLOAT)
				size += strm.read_array(
					&u.value._float32,
					u.length);
			else if (u.type == SHADERVARIABLE_VEC2)
				size += strm.read_array(
					&u.value._float32,
					2 * u.length);
			else if (u.type == SHADERVARIABLE_VEC3)
				size += strm.read_array(
					&u.value._float32,
					3 * u.length);
			else if (u.type == SHADERVARIABLE_VEC4)
				size += strm.read_array(
					&u.value._float32,
					4 * u.length);
			else if (u.type == SHADERVARIABLE_MAT2)
				size += strm.read_array(
					&u.value._float32,
					4 * u.length);
			else if (u.type == SHADERVARIABLE_MAT3)
				size += strm.read_array(
					&u.value._float32,
					9 * u.length);
			else if (u.type == SHADERVARIABLE_MAT3X4)
				size += strm.read_array(
					&u.value._float32,
					12 * u.length);
			else if (u.type == SHADERVARIABLE_MAT4)
				size += strm.read_array(
					&u.value._float32,
					16 * u.length);
			else if (u.type == SHADERVARIABLE_SAMPLER_2D)
				size += strm.read_array(
					&u.value._index,
					u.length);
			else if (u.type == SHADERVARIABLE_SAMPLER_CUBE)
				size += strm.read_array(
					&u.value._index,
					u.length);

			UInt32 track_count;
			size += strm.read(&track_count);
			for (int j = 0; j < size; ++j)
			{
				uniform_s::track_s t;
				size += strm.read(&t.animation_track);
				size += strm.read(&t.channel_index);
				u.tracks.push_back(t);
			}
		}
		else if (u.binding_type == 1)
		{
			ForwardIndex i;
			size += strm.read_varray(&u.node_from);
			size += strm.read(&i);
			u.node_to.push_back(i);
		}
		else if (u.binding_type == 2)
		{
			ForwardIndex i;
			size += strm.read(&i);
			size += strm.read_varray(&u.node_to);
			u.node_from.push_back(i);
		}
		else if (u.binding_type == 3)
		{
			size += strm.read_varray(&u.source);
			size += strm.read(&u.property);
		}
		uniforms.push_back(u);
	}
	return size;
}
void shader_uniforms_object::print(FILE* out, std::string const &indent,
	int version)
{
	object3d_object::print(out, indent, version);
}

// Stencil
int stencil_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&stencil_func_front);
	size += strm.read(&stencil_ref_front);
	size += strm.read(&stencil_mask_front);
	size += strm.read(&stencil_write_mask_front);
	size += strm.read(&stencil_fail_op_front);
	size += strm.read(&stencil_pass_depth_fail_op_front);
	size += strm.read(&stencil_pass_depth_pass_op_front);
	size += strm.read(&stencil_func_back);
	size += strm.read(&stencil_ref_back);
	size += strm.read(&stencil_mask_back);
	size += strm.read(&stencil_write_mask_back);
	size += strm.read(&stencil_fail_op_back);
	size += strm.read(&stencil_pass_depth_fail_op_back);
	size += strm.read(&stencil_pass_depth_pass_op_back);
	return size;
}
void stencil_object::print(FILE* out, std::string const &indent, int version)
{
	object3d_object::print(out, indent, version);
}

// TextureCombiner
int texture_combiner_object::load(Stream& strm, int version)
{
	int size = 0;
	size = object3d_object::load(strm, version);
	size += strm.read(&color_function);
	size += strm.read(&color_scale);
	size += strm.read(&color_source0);

	if (color_function != TEXTURECOMBINER_REPLACE)
	{
		size = strm.read(&color_source1);
		if (color_function != TEXTURECOMBINER_INTERPOLATE)
			size += strm.read(&color_source2);
	}

	size += strm.read(&alpha_function);
	size += strm.read(&alpha_scale);
	size += strm.read(&alpha_source0);

	if (alpha_function != TEXTURECOMBINER_REPLACE)
	{
		size = strm.read(&alpha_source1);
		if (alpha_function != TEXTURECOMBINER_INTERPOLATE)
			size += strm.read(&alpha_source2);
	}
	return size;
}
void texture_combiner_object::print(FILE* out, std::string const &indent,
	int version)
{
	object3d_object::print(out, indent, version);
}

// TextureCube
int texture_cube_object::load(Stream& strm, int version)
{
	int size = 0;
	size += texture_object::load(strm, version);
	return size;
}
void texture_cube_object::print(FILE* out, std::string const &indent,
	int version)
{
	texture_object::print(out, indent, version);
}

// VertexShader
int vertex_shader_object::load(Stream& strm, int version)
{
	int size = 0;
	size += shader_object::load(strm, version);
	return size;
}
void vertex_shader_object::print(FILE* out, std::string const &indent,
	int version)
{
	shader_object::print(out, indent, version);
}
*/
