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

const struct m3g_const_names_s
{
	int value; char const* name;
} m3g_const_names[] =
{
	{ ANIMATIONTRACK_ALPHA, "ALPHA" },
	{ ANIMATIONTRACK_AMBIENT_COLOR, "AMBIENT_COLOR" },
	{ ANIMATIONTRACK_ANIMATION_POSITION, "ANIMATION_POSITION" },
	{ ANIMATIONTRACK_ANIMATION_SPEED, "ANIMATION_SPEED" },
	{ ANIMATIONTRACK_ANIMATION_WEIGHT, "ANIMATION_WEIGHT" },
	{ ANIMATIONTRACK_BOUNDING_BOX, "BOUNDING_BOX" },
	{ ANIMATIONTRACK_BOUNDING_SPHERE, "BOUNDING_SPHERE" },
	{ ANIMATIONTRACK_COLLISION_SHAPE, "COLLISION_SHAPE" },
	{ ANIMATIONTRACK_COLOR, "COLOR" },
	{ ANIMATIONTRACK_CROP, "CROP" },
	{ ANIMATIONTRACK_DENSITY, "DENSITY" },
	{ ANIMATIONTRACK_DEPTH, "DEPTH" },
	{ ANIMATIONTRACK_DIFFUSE_COLOR, "DIFFUSE_COLOR" },
	{ ANIMATIONTRACK_EMISSIVE_COLOR, "EMISSIVE_COLOR" },
	{ ANIMATIONTRACK_FAR_DISTANCE, "FAR_DISTANCE" },
	{ ANIMATIONTRACK_FIELD_OF_VIEW, "FIELD_OF_VIEW" },
	{ ANIMATIONTRACK_INTENSITY, "INTENSITY" },
	{ ANIMATIONTRACK_MORPH_WEIGHTS, "MORPH_WEIGHTS" },
	{ ANIMATIONTRACK_NEAR_DISTANCE, "NEAR_DISTANCE" },
	{ ANIMATIONTRACK_ORIENTATION, "ORIENTATION" },
	{ ANIMATIONTRACK_PICKABILITY, "PICKABILITY" },
	{ ANIMATIONTRACK_POINT_SIZE, "POINT_SIZE" },
	{ ANIMATIONTRACK_SCALE, "SCALE" },
	{ ANIMATIONTRACK_SHININESS, "SHININESS" },
	{ ANIMATIONTRACK_SPECULAR_COLOR, "SPECULAR_COLOR" },
	{ ANIMATIONTRACK_SPOT_ANGLE, "SPOT_ANGLE" },
	{ ANIMATIONTRACK_SPOT_EXPONENT, "SPOT_EXPONENT" },
	{ ANIMATIONTRACK_STENCIL, "STENCIL" },
	{ ANIMATIONTRACK_TRANSLATION, "TRANSLATION" },
	{ ANIMATIONTRACK_VISIBILITY, "VISIBILITY" },
	{ BACKGROUND_BORDER, "BORDER" },
	{ BACKGROUND_REPEAT, "REPEAT" },
	{ BLENDER_ADD, "ADD" },
	{ BLENDER_CONSTANT_ALPHA, "CONSTANT_ALPHA" },
	{ BLENDER_CONSTANT_COLOR, "CONSTANT_COLOR" },
	{ BLENDER_DST_ALPHA, "DST_ALPHA" },
	{ BLENDER_DST_COLOR, "DST_COLOR" },
	{ BLENDER_ONE, "ONE" },
	{ BLENDER_ONE_MINUS_CONSTANT_ALPHA, "ONE_MINUS_CONSTANT_ALPHA" },
	{ BLENDER_ONE_MINUS_CONSTANT_COLOR, "ONE_MINUS_CONSTANT_COLOR" },
	{ BLENDER_ONE_MINUS_DST_ALPHA, "ONE_MINUS_DST_ALPHA" },
	{ BLENDER_ONE_MINUS_DST_COLOR, "ONE_MINUS_DST_COLOR" },
	{ BLENDER_ONE_MINUS_SRC_ALPHA, "ONE_MINUS_SRC_ALPHA" },
	{ BLENDER_ONE_MINUS_SRC_COLOR, "ONE_MINUS_SRC_COLOR" },
	{ BLENDER_REVERSE_SUBTRACT, "REVERSE_SUBTRACT" },
	{ BLENDER_SRC_ALPHA, "SRC_ALPHA" },
	{ BLENDER_SRC_ALPHA_SATURATE, "SRC_ALPHA_SATURATE" },
	{ BLENDER_SRC_COLOR, "SRC_COLOR" },
	{ BLENDER_SUBTRACT, "SUBTRACT" },
	{ BLENDER_ZERO, "ZERO" },
	{ CAMERA_GENERIC, "GENERIC" },
	{ CAMERA_PARALLEL, "PARALLEL" },
	{ CAMERA_PERSPECTIVE, "PERSPECTIVE" },
	{ CAMERA_SCREEN, "SCREEN" },
	{ COMPOSITINGMODE_ADD, "ADD" },
	{ COMPOSITINGMODE_ALPHA, "ALPHA" },
	{ COMPOSITINGMODE_ALPHA_ADD, "ALPHA_ADD" },
	{ COMPOSITINGMODE_ALPHA_DARKEN, "ALPHA_DARKEN" },
	{ COMPOSITINGMODE_ALPHA_PREMULTIPLIED, "ALPHA_PREMULTIPLIED" },
	{ COMPOSITINGMODE_ALWAYS, "ALWAYS" },
	{ COMPOSITINGMODE_EQUAL, "EQUAL" },
	{ COMPOSITINGMODE_GEQUAL, "GEQUAL" },
	{ COMPOSITINGMODE_GREATER, "GREATER" },
	{ COMPOSITINGMODE_LEQUAL, "LEQUAL" },
	{ COMPOSITINGMODE_LESS, "LESS" },
	{ COMPOSITINGMODE_MODULATE, "MODULATE" },
	{ COMPOSITINGMODE_MODULATE_INV, "MODULATE_INV" },
	{ COMPOSITINGMODE_MODULATE_X2, "MODULATE_X2" },
	{ COMPOSITINGMODE_NEVER, "NEVER" },
	{ COMPOSITINGMODE_NOTEQUAL, "NOTEQUAL" },
	{ COMPOSITINGMODE_REPLACE, "REPLACE" },
	{ FOG_EXPONENTIAL, "EXPONENTIAL" },
	{ FOG_EXPONENTIAL_SQUARED, "EXPONENTIAL_SQUARED" },
	{ FOG_LINEAR, "LINEAR" },
	{ GRAPHICS3D_ANTIALIAS, "ANTIALIAS" },
	{ GRAPHICS3D_DEPTH, "DEPTH" },
	{ GRAPHICS3D_DITHER, "DITHER" },
	{ GRAPHICS3D_NO_OVERLAYS, "NO_OVERLAYS" },
	{ GRAPHICS3D_OVERWRITE, "OVERWRITE" },
	{ GRAPHICS3D_PURE3D, "PURE3D" },
	{ GRAPHICS3D_STENCIL, "STENCIL" },
	{ GRAPHICS3D_TRUE_COLOR, "TRUE_COLOR" },
	{ GRAPHICS3D_VALIDATE, "VALIDATE" },
	{ IMAGEBASE_ALPHA, "ALPHA" },
	{ IMAGEBASE_LOSSLESS, "LOSSLESS" },
	{ IMAGEBASE_LUMINANCE, "LUMINANCE" },
	{ IMAGEBASE_LUMINANCE_ALPHA, "LUMINANCE_ALPHA" },
	{ IMAGEBASE_NO_MIPMAPS, "NO_MIPMAPS" },
	{ IMAGEBASE_R_COMPRESSED, "R_COMPRESSED" },
	{ IMAGEBASE_RG_COMPRESSED, "RG_COMPRESSED" },
	{ IMAGEBASE_RGB, "RGB" },
	{ IMAGEBASE_RGB_COMPRESSED, "RGB_COMPRESSED" },
	{ IMAGEBASE_RGB_ETC, "RGB_ETC" },
	{ IMAGEBASE_RGB565, "RGB565" },
	{ IMAGEBASE_RGBA, "RGBA" },
	{ IMAGEBASE_RGBA_COMPRESSED, "RGBA_COMPRESSED" },
	{ IMAGEBASE_RGBA4444, "RGBA4444" },
	{ IMAGEBASE_RGBA5551, "RGBA5551" },
	{ IMAGEBASE_Y_UP, "Y_UP" },
	{ IMAGECUBE_NEG_X, "NEG_X" },
	{ IMAGECUBE_NEG_Y, "NEG_Y" },
	{ IMAGECUBE_NEG_Z, "NEG_Z" },
	{ IMAGECUBE_POS_X, "POS_X" },
	{ IMAGECUBE_POS_Y, "POS_Y" },
	{ IMAGECUBE_POS_Z, "POS_Z" },
	{ INDEXBUFFER_LINES, "LINES" },
	{ INDEXBUFFER_POINT_SPRITES, "POINT_SPRITES" },
	{ INDEXBUFFER_TRIANGLES, "TRIANGLES" },
	{ KEYFRAMESEQUENCE_ADDITIVE_LOOP, "ADDITIVE_LOOP" },
	{ KEYFRAMESEQUENCE_CONSTANT, "CONSTANT" },
	{ KEYFRAMESEQUENCE_LINEAR, "LINEAR" },
	{ KEYFRAMESEQUENCE_LOOP, "LOOP" },
	{ KEYFRAMESEQUENCE_SLERP, "SLERP" },
	{ KEYFRAMESEQUENCE_SPLINE, "SPLINE" },
	{ KEYFRAMESEQUENCE_SQUAD, "SQUAD" },
	{ KEYFRAMESEQUENCE_STEP, "STEP" },
	{ LIGHT_AMBIENT, "AMBIENT" },
	{ LIGHT_DIRECTIONAL, "DIRECTIONAL" },
	{ LIGHT_OMNI, "OMNI" },
	{ LIGHT_SPOT, "SPOT" },
	{ MATERIAL_AMBIENT, "AMBIENT" },
	{ MATERIAL_DIFFUSE, "DIFFUSE" },
	{ MATERIAL_EMISSIVE, "EMISSIVE" },
	{ MATERIAL_SPECULAR, "SPECULAR" },
	{ NODE_NONE, "NONE" },
	{ NODE_ORIGIN, "ORIGIN" },
	{ NODE_X_AXIS, "X_AXIS" },
	{ NODE_Y_AXIS, "Y_AXIS" },
	{ NODE_Z_AXIS, "Z_AXIS" },
	{ POLYGONMODE_CULL_BACK, "CULL_BACK" },
	{ POLYGONMODE_CULL_FRONT, "CULL_FRONT" },
	{ POLYGONMODE_CULL_NONE, "CULL_NONE" },
	{ POLYGONMODE_SHADE_FLAT, "SHADE_FLAT" },
	{ POLYGONMODE_SHADE_SMOOTH, "SHADE_SMOOTH" },
	{ POLYGONMODE_WINDING_CCW, "WINDING_CCW" },
	{ POLYGONMODE_WINDING_CW, "WINDING_CW" },
	{ SHADERUNIFORMS_ALPHA_FACTOR, "ALPHA_FACTOR" },
	{ SHADERUNIFORMS_BONE_MATRICES, "BONE_MATRICES" },
	{ SHADERUNIFORMS_CAMERA_FAR_DISTANCE, "CAMERA_FAR_DISTANCE" },
	{ SHADERUNIFORMS_CAMERA_FIELD_OF_VIEW, "CAMERA_FIELD_OF_VIEW" },
	{ SHADERUNIFORMS_CAMERA_NEAR_DISTANCE, "CAMERA_NEAR_DISTANCE" },
	{ SHADERUNIFORMS_CAMERA_PROJECTION, "CAMERA_PROJECTION" },
	{ SHADERUNIFORMS_CAMERA_SPACE_DIRECTION, "CAMERA_SPACE_DIRECTION" },
	{ SHADERUNIFORMS_CAMERA_SPACE_POSITION, "CAMERA_SPACE_POSITION" },
	{ SHADERUNIFORMS_COMPOSITE_MATRIX, "COMPOSITE_MATRIX" },
	{ SHADERUNIFORMS_LIGHT_COLOR, "LIGHT_COLOR" },
	{ SHADERUNIFORMS_MATRIX, "MATRIX" },
	{ SHADERUNIFORMS_MODEL_SPACE_DIRECTION, "MODEL_SPACE_DIRECTION" },
	{ SHADERUNIFORMS_MODEL_SPACE_POSITION, "MODEL_SPACE_POSITION" },
	{ SHADERUNIFORMS_ORIENTATION, "ORIENTATION" },
	{ SHADERUNIFORMS_SCALE, "SCALE" },
	{ SHADERUNIFORMS_TRANSLATION, "TRANSLATION" },
	{ SHADERUNIFORMS_WORLD_SPACE_DIRECTION, "WORLD_SPACE_DIRECTION" },
	{ SHADERUNIFORMS_WORLD_SPACE_POSITION, "WORLD_SPACE_POSITION" },
	{ SHADERVARIABLE_BOOL, "BOOL" },
	{ SHADERVARIABLE_BVEC2, "BVEC2" },
	{ SHADERVARIABLE_BVEC3, "BVEC3" },
	{ SHADERVARIABLE_BVEC4, "BVEC4" },
	{ SHADERVARIABLE_FLOAT, "FLOAT" },
	{ SHADERVARIABLE_INT, "INT" },
	{ SHADERVARIABLE_IVEC2, "IVEC2" },
	{ SHADERVARIABLE_IVEC3, "IVEC3" },
	{ SHADERVARIABLE_IVEC4, "IVEC4" },
	{ SHADERVARIABLE_MAT2, "MAT2" },
	{ SHADERVARIABLE_MAT3, "MAT3" },
	{ SHADERVARIABLE_MAT3X4, "MAT3X4" },
	{ SHADERVARIABLE_MAT4, "MAT4" },
	{ SHADERVARIABLE_SAMPLER_2D, "SAMPLER_2D" },
	{ SHADERVARIABLE_SAMPLER_CUBE, "SAMPLER_CUBE" },
	{ SHADERVARIABLE_VEC2, "VEC2" },
	{ SHADERVARIABLE_VEC3, "VEC3" },
	{ SHADERVARIABLE_VEC4, "VEC4" },
	{ STENCIL_BACK, "BACK" },
	{ STENCIL_DECR, "DECR" },
	{ STENCIL_DECR_WRAP, "DECR_WRAP" },
	{ STENCIL_FRONT, "FRONT" },
	{ STENCIL_INCR, "INCR" },
	{ STENCIL_INCR_WRAP, "INCR_WRAP" },
	{ STENCIL_INVERT, "INVERT" },
	{ STENCIL_KEEP, "KEEP" },
	{ STENCIL_REPLACE, "REPLACE" },
	{ STENCIL_ZERO, "ZERO" },
	{ TEXTURE_FILTER_ANISOTROPIC, "FILTER_ANISOTROPIC" },
	{ TEXTURE_FILTER_BASE_LEVEL, "FILTER_BASE_LEVEL" },
	{ TEXTURE_FILTER_LINEAR, "FILTER_LINEAR" },
	{ TEXTURE_FILTER_NEAREST, "FILTER_NEAREST" },
	{ TEXTURE2D_FUNC_ADD, "FUNC_ADD" },
	{ TEXTURE2D_FUNC_BLEND, "FUNC_BLEND" },
	{ TEXTURE2D_FUNC_DECAL, "FUNC_DECAL" },
	{ TEXTURE2D_FUNC_MODULATE, "FUNC_MODULATE" },
	{ TEXTURE2D_FUNC_REPLACE, "FUNC_REPLACE" },
	{ TEXTURE2D_WRAP_CLAMP, "WRAP_CLAMP" },
	{ TEXTURE2D_WRAP_MIRROR, "WRAP_MIRROR" },
	{ TEXTURE2D_WRAP_REPEAT, "WRAP_REPEAT" },
	{ TEXTURECOMBINER_ADD, "ADD" },
	{ TEXTURECOMBINER_ADD_SIGNED, "ADD_SIGNED" },
	{ TEXTURECOMBINER_ALPHA, "ALPHA" },
	{ TEXTURECOMBINER_CONSTANT, "CONSTANT" },
	{ TEXTURECOMBINER_DOT3_RGB, "DOT3_RGB" },
	{ TEXTURECOMBINER_DOT3_RGBA, "DOT3_RGBA" },
	{ TEXTURECOMBINER_INTERPOLATE, "INTERPOLATE" },
	{ TEXTURECOMBINER_INVERT, "INVERT" },
	{ TEXTURECOMBINER_MODULATE, "MODULATE" },
	{ TEXTURECOMBINER_PREVIOUS, "PREVIOUS" },
	{ TEXTURECOMBINER_PRIMARY, "PRIMARY" },
	{ TEXTURECOMBINER_REPLACE, "REPLACE" },
	{ TEXTURECOMBINER_SUBTRACT, "SUBTRACT" },
	{ TEXTURECOMBINER_TEXTURE, "TEXTURE" },
	{ VERTEXARRAY_BYTE, "BYTE" },
	{ VERTEXARRAY_FIXED, "FIXED" },
	{ VERTEXARRAY_FLOAT, "FLOAT" },
	{ VERTEXARRAY_HALF, "HALF" },
	{ VERTEXARRAY_SHORT, "SHORT" },
};

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
		register_object<animation_track_object>();
		register_object<appearance_object>();
		register_object<background_object>();
		register_object<camera_object>();
		register_object<composition_mode_object>();
		register_object<fog_object>();
		register_object<polygon_mode_object>();
		register_object<group_object>();
		register_object<image2d_object>();
		register_object<triangle_strip_array_object>();
		register_object<light_object>();
		register_object<material_object>();
		register_object<mesh_object>();
		register_object<morphing_mesh_object>();
		register_object<skinned_mesh_object>();
		register_object<texture2d_object>();
		register_object<sprite3d_object>();
		register_object<keyframe_sequence_object>();
		register_object<vertex_array_object>();
		register_object<vertex_buffer_object>();
		register_object<world_object>();
		register_object<blender_object>();
		register_object<dynamic2d_object>();
		register_object<fragment_shader_object>();
		register_object<image_cube_object>();
		register_object<index_buffer_object>();
		register_object<point_sprite_mode_object>();
		register_object<render_pass_object>();
		register_object<render_target_object>();
		register_object<shader_appearance_object>();
		register_object<shader_program_object>();
		register_object<shader_uniforms_object>();
		register_object<stencil_object>();
		register_object<texture_combiner_object>();
		register_object<texture_cube_object>();
		register_object<vertex_shader_object>();
	}
} do_object_registrator;

// Header object
int header_object::load(Stream& strm, int version)
{
	int size = 0;
	size += strm.read(&version_number);
	size += strm.read(&has_external_references);
	size += strm.read(&total_file_size);
	size += strm.read(&approximate_content_size);
	size += strm.read(&authoring_field);
	return size;
}
void header_object::print(FILE* out)
{
	fprintf(out, "version: %d.%d\n", version_number[0],
		version_number[1]);
	fprintf(out, "external refs: %d\n", has_external_references);
	fprintf(out, "total file size: %d\n", total_file_size);
	fprintf(out, "approximate context size: %d\n",
		approximate_content_size);
	fprintf(out, "authoring field: %s\n", authoring_field.c_str());
}

// External reference
int external_ref_object::load(Stream& strm, int version)
{
	return strm.read(&URI);
}

void external_ref_object::print(FILE* out)
{
	fprintf(out, "URI: %s\n", URI.c_str());
}

// External image reference
int external_image_ref_object::load(Stream& strm, int version)
{
	int size = 0;
	size += external_ref_object::load(strm, version);
	size += strm.read(&format);
	return size;
}

void external_image_ref_object::print(FILE* out)
{
	external_ref_object::print(out);
	fprintf(out, "format: %d\n", format);
}

// External object reference
int external_object_ref_object::load(Stream& strm, int version)
{
	int size = 0;
	size += external_ref_object::load(strm, version);
	size += strm.read_varray(&user_id);
	return size;
}
void external_object_ref_object::print(FILE* out)
{
	external_ref_object::print(out);
}

// Object3D
int object3d_object::load(Stream& strm, int version)
{
	int size = 0;
	UInt32 count;
	size += strm.read(&user_id);

	/* read animation tracks */
	size += strm.read(&count);
	for (int i = 0; i < count; ++i)
	{
		anim_track_s track;
		size += strm.read(&track.animation_track);
		if (version == M3G_FILE_FORMAT_20)
			size = strm.read(&track.animation_track_index);
		animation_tracks.push_back(track);
	}

	/* read parameters */
	size += strm.read(&count);
	for (int i = 0; i < count; ++i)
	{
		parameter_s param;
		size += strm.read(&param.parameter_id);
		size += strm.read(&param.parameter_value);
		parameters.push_back(param);
	}

	if (version == M3G_FILE_FORMAT_20)
		size += strm.read(&animation_enabled);

	return size;
}

void object3d_object::print(FILE* out)
{
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

void animation_controller_object::print(FILE* out)
{
	object3d_object::print(out);
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
		strm.read(&property_id.v20);
		if (property_id.v20 >= SHADERVARIABLE_FLOAT &&
			property_id.v20 <= SHADERVARIABLE_SAMPLER_CUBE)
		{
			strm.read(&is_normalize_enabled);
		}
	}
	else
	{
		strm.read(&property_id.v10);
	}
}

void animation_track_object::print(FILE* out)
{
	object3d_object::print(out);
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
		size += strm.read(&is_deph_sort_enabled);
	}
	return size;
}

void appearance_base_object::print(FILE* out)
{
	object3d_object::print(out);
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
void appearance_object::print(FILE* out)
{
	appearance_base_object::print(out);
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
void background_object::print(FILE* out)
{
	object3d_object::print(out);
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
void transformable_object::print(FILE* out)
{
	object3d_object::print(out);
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
			size += strm.read_array(&min, 1);
			size += strm.read_array(&max, 1);
		}

		size += strm.read(&lod_resolution);
	}
	return size;
}
void node_object::print(FILE* out)
{
	transformable_object::print(out);
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
		size += strm.read(&heigth);
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
void camera_object::print(FILE* out)
{
	node_object::print(out);
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
void composition_mode_object::print(FILE* out)
{
	object3d_object::print(out);
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
		size += strm.read(&dencity);
	}
	else
	{
		size += strm.read(&near);
		size += strm.read(&far);
	}
	return size;
}
void fog_object::print(FILE* out)
{
	object3d_object::print(out);
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
void group_object::print(FILE* out)
{
	node_object::print(out);
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
	size += strm.read(&heigth);
	return size;
}
void image_base_object::print(FILE* out)
{
	object3d_object::print(out);
}

// Image2D
int image2d_object::load(Stream& strm, int version)
{
	int size = 0;
	size += image_base_object::load(strm, version);
	if (is_mutable)
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
void image2d_object::print(FILE* out)
{
	image_base_object::print(out);
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
			size += strm.read_varray(&index_deltas._int32);
		else if (encoding == 193)
			size += strm.read_varray(&index_deltas._byte);
		else if (encoding == 194)
			size += strm.read_varray(&index_deltas._int16);
	}
	return size;
}
void index_buffer_object::print(FILE* out)
{
	object3d_object::print(out);
}

// Keyframe sequence
int keyframe_sequence_object::load(Stream& strm, int version)
{
	int size = 0;
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
		for (int i = 0; i < keyframe_count; ++i)
		{
			keyframe_s kf;
			size += strm.read(&kf.time);
			size += strm.read_array(
				&kf.vector_value._float32,
				keyframe_count * channel_count);
			keyframes.push_back(kf);
		}
	}
	else if (encoding == 1)
	{
		size += strm.read_array(&vector_bias, component_count);
		size += strm.read_array(&vector_scale, component_count);
		for (int i = 0; i < keyframe_count; ++i)
		{
			keyframe_s kf;
			size += strm.read(&kf.time);
			size += strm.read_array(&kf.vector_value._byte,
				keyframe_count * channel_count);
			keyframes.push_back(kf);
		}
	}
	else if (encoding == 2)
	{
		size += strm.read_array(&vector_bias, component_count);
		size += strm.read_array(&vector_scale, component_count);
		for (int i = 0; i < keyframe_count; ++i)
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
		for (int i = 0; i < event_count; ++i)
		{
			event_s e;
			size += strm.read(&e.event_time);
			size += strm.read(&e.event_id);
			events.push_back(e);
		}
	}
	return size;
}
void keyframe_sequence_object::print(FILE* out)
{
	object3d_object::print(out);
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
void light_object::print(FILE* out)
{
	node_object::print(out);
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
void material_object::print(FILE* out)
{
	object3d_object::print(out);
}

// Mesh
int mesh_object::load(Stream& strm, int version)
{
	int size = 0;
	size += node_object::load(strm, version);
	size += strm.read(&vertex_buffer);
	size += strm.read(&submesh_count);
	for (int i = 0; i < submesh_count; ++i)
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
void mesh_object::print(FILE* out)
{
	node_object::print(out);
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
		for (int i = 0; i < morph_target; ++i)
		{
			target_buf_s tb;
			size += strm.read(&tb.morph_target);
			size += strm.read(&tb.initial_weight);
			target_buffers.push_back(tb);
		}
	}
	return size;
}
void morphing_mesh_object::print(FILE* out)
{
	mesh_object::print(out);
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
void polygon_mode_object::print(FILE* out)
{
	object3d_object::print(out);
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
	for (int i = 0; i < ref_count; ++i)
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
void skinned_mesh_object::print(FILE* out)
{
	mesh_object::print(out);
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
void sprite3d_object::print(FILE* out)
{
	node_object::print(out);
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
void texture_object::print(FILE* out)
{
	transformable_object::print(out);
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
void texture2d_object::print(FILE* out)
{
	texture_object::print(out);
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
void triangle_strip_array_object::print(FILE* out)
{
	index_buffer_object::print(out);
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
	}
	return size;
}

void vertex_array_object::print(FILE* out)
{
	object3d_object::print(out);
}

// VertexBuffer
int vertex_buffer_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&default_color);
	size += strm.read(&position);
	size += strm.read_array(&position_bias, 1);
	size += strm.read(&position_scale);
	size += strm.read(&normals);
	size += strm.read(&colors);

	UInt32 tex_count;
	size += strm.read(&tex_count);
	for (int i = 0; i < tex_count; ++i)
	{
		coords_s crd;
		size += strm.read(&crd.coord);
		size += strm.read_array(&crd.bias, 1);
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
		for (int i = 0; i < attr_count; ++i)
		{
			attribute_s a;
			size += strm.read(&a.name);
			size += strm.read(&a.attribute);
			size += strm.read(&a._signed);
			size += strm.read(&a._normalized);
			size += strm.read_array(
				&a.default_attribute_value, 1);
			attributes.push_back(a);
		}
	}
	return size;
}
void vertex_buffer_object::print(FILE* out)
{
	object3d_object::print(out);
}

// World
int world_object::load(Stream& strm, int version)
{
	int size = 0;
	size += group_object::load(strm, version);
	size += strm.read(&active_camera);
	size += strm.read(&background);
}
void world_object::print(FILE* out)
{
	group_object::print(out);
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
void blender_object::print(FILE* out)
{
	object3d_object::print(out);
}

// DynamicImage2D
int dynamic2d_object::load(Stream& strm, int version)
{
	int size = 0;
	size += dynamic2d_object::load(strm, version);
	return size;
}
void dynamic2d_object::print(FILE* out)
{
	object3d_object::print(out);
}

// Shader
int shader_object::load(Stream& strm, int version)
{
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&source);
	return size;
}
void shader_object::print(FILE* out)
{
	object3d_object::print(out);
}

// FragmentShader
int fragment_shader_object::load(Stream& strm, int version)
{
	int size = 0;
	size += shader_object::load(strm, version);
	return size;
}
void fragment_shader_object::print(FILE* out)
{
	shader_object::print(out);
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
void image_cube_object::print(FILE* out)
{
	image_base_object::print(out);
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
void point_sprite_mode_object::print(FILE* out)
{
	object3d_object::print(out);
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
void render_pass_object::print(FILE* out)
{
	object3d_object::print(out);
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
void render_target_object::print(FILE* out)
{
	object3d_object::print(out);
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
void shader_appearance_object::print(FILE* out)
{
	appearance_base_object::print(out);
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
void shader_program_object::print(FILE* out)
{
	object3d_object::print(out);
}

// ShaderUniforms
int shader_uniforms_object::load(Stream& strm, int version)
{
	UInt32 count;
	int size = 0;
	size += object3d_object::load(strm, version);
	size += strm.read(&count);
	for (int i = 0; i < count; ++i)
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
void shader_uniforms_object::print(FILE* out)
{
	object3d_object::print(out);
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
void stencil_object::print(FILE* out)
{
	object3d_object::print(out);
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
}
void texture_combiner_object::print(FILE* out)
{
	object3d_object::print(out);
}

// TextureCube
int texture_cube_object::load(Stream& strm, int version)
{
	int size = 0;
	size += texture_object::load(strm, version);
	return size;
}
void texture_cube_object::print(FILE* out)
{
	texture_object::print(out);
}

// VertexShader
int vertex_shader_object::load(Stream& strm, int version)
{
	int size = 0;
	size += shader_object::load(strm, version);
	return size;
}
void vertex_shader_object::print(FILE* out)
{
	shader_object::print(out);
}

