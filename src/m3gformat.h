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

const int ANIMATIONTRACK_ALPHA = 256;
const int ANIMATIONTRACK_AMBIENT_COLOR = 257;
const int ANIMATIONTRACK_ANIMATION_POSITION = 277;
const int ANIMATIONTRACK_ANIMATION_SPEED = 278;
const int ANIMATIONTRACK_ANIMATION_WEIGHT = 279;
const int ANIMATIONTRACK_BOUNDING_BOX = 280;
const int ANIMATIONTRACK_BOUNDING_SPHERE = 281;
const int ANIMATIONTRACK_COLLISION_SHAPE = 282;
const int ANIMATIONTRACK_COLOR = 258;
const int ANIMATIONTRACK_CROP = 259;
const int ANIMATIONTRACK_DENSITY = 260;
const int ANIMATIONTRACK_DEPTH = 283;
const int ANIMATIONTRACK_DIFFUSE_COLOR = 261;
const int ANIMATIONTRACK_EMISSIVE_COLOR = 262;
const int ANIMATIONTRACK_FAR_DISTANCE = 263;
const int ANIMATIONTRACK_FIELD_OF_VIEW = 264;
const int ANIMATIONTRACK_INTENSITY = 265;
const int ANIMATIONTRACK_MORPH_WEIGHTS = 266;
const int ANIMATIONTRACK_NEAR_DISTANCE = 267;
const int ANIMATIONTRACK_ORIENTATION = 268;
const int ANIMATIONTRACK_PICKABILITY = 269;
const int ANIMATIONTRACK_POINT_SIZE = 284;
const int ANIMATIONTRACK_SCALE = 270;
const int ANIMATIONTRACK_SHININESS = 271;
const int ANIMATIONTRACK_SPECULAR_COLOR = 272;
const int ANIMATIONTRACK_SPOT_ANGLE = 273;
const int ANIMATIONTRACK_SPOT_EXPONENT = 274;
const int ANIMATIONTRACK_STENCIL = 285;
const int ANIMATIONTRACK_TRANSLATION = 275;
const int ANIMATIONTRACK_VISIBILITY = 276;
const int BACKGROUND_BORDER = 32;
const int BACKGROUND_REPEAT = 33;
const int BLENDER_ADD = 88;
const int BLENDER_CONSTANT_ALPHA = 125;
const int BLENDER_CONSTANT_COLOR = 123;
const int BLENDER_DST_ALPHA = 118;
const int BLENDER_DST_COLOR = 120;
const int BLENDER_ONE = 113;
const int BLENDER_ONE_MINUS_CONSTANT_ALPHA = 126;
const int BLENDER_ONE_MINUS_CONSTANT_COLOR = 124;
const int BLENDER_ONE_MINUS_DST_ALPHA = 119;
const int BLENDER_ONE_MINUS_DST_COLOR = 121;
const int BLENDER_ONE_MINUS_SRC_ALPHA = 117;
const int BLENDER_ONE_MINUS_SRC_COLOR = 115;
const int BLENDER_REVERSE_SUBTRACT = 90;
const int BLENDER_SRC_ALPHA = 116;
const int BLENDER_SRC_ALPHA_SATURATE = 122;
const int BLENDER_SRC_COLOR = 114;
const int BLENDER_SUBTRACT = 89;
const int BLENDER_ZERO = 112;
const int CAMERA_GENERIC = 48;
const int CAMERA_PARALLEL = 49;
const int CAMERA_PERSPECTIVE = 50;
const int CAMERA_SCREEN = 51;
const int COMPOSITINGMODE_ADD = 69;
const int COMPOSITINGMODE_ALPHA = 64;
const int COMPOSITINGMODE_ALPHA_ADD = 65;
const int COMPOSITINGMODE_ALPHA_DARKEN = 70;
const int COMPOSITINGMODE_ALPHA_PREMULTIPLIED = 71;
const int COMPOSITINGMODE_ALWAYS = 519;
const int COMPOSITINGMODE_EQUAL = 514;
const int COMPOSITINGMODE_GEQUAL = 518;
const int COMPOSITINGMODE_GREATER = 516;
const int COMPOSITINGMODE_LEQUAL = 515;
const int COMPOSITINGMODE_LESS = 513;
const int COMPOSITINGMODE_MODULATE = 66;
const int COMPOSITINGMODE_MODULATE_INV = 72;
const int COMPOSITINGMODE_MODULATE_X2 = 67;
const int COMPOSITINGMODE_NEVER = 512;
const int COMPOSITINGMODE_NOTEQUAL = 517;
const int COMPOSITINGMODE_REPLACE = 68;
const int FOG_EXPONENTIAL = 80;
const int FOG_EXPONENTIAL_SQUARED = 82;
const int FOG_LINEAR = 81;
const int GRAPHICS3D_ANTIALIAS = 2;
const int GRAPHICS3D_DEPTH = 64;
const int GRAPHICS3D_DITHER = 4;
const int GRAPHICS3D_NO_OVERLAYS = 32;
const int GRAPHICS3D_OVERWRITE = 16;
const int GRAPHICS3D_PURE3D = 48;
const int GRAPHICS3D_STENCIL = 128;
const int GRAPHICS3D_TRUE_COLOR = 8;
const int GRAPHICS3D_VALIDATE = 256;
const int IMAGEBASE_ALPHA = 96;
const int IMAGEBASE_LOSSLESS = 16384;
const int IMAGEBASE_LUMINANCE = 97;
const int IMAGEBASE_LUMINANCE_ALPHA = 98;
const int IMAGEBASE_NO_MIPMAPS = 32768;
const int IMAGEBASE_R_COMPRESSED = 105;
const int IMAGEBASE_RG_COMPRESSED = 106;
const int IMAGEBASE_RGB = 99;
const int IMAGEBASE_RGB_COMPRESSED = 107;
const int IMAGEBASE_RGB_ETC = 104;
const int IMAGEBASE_RGB565 = 101;
const int IMAGEBASE_RGBA = 100;
const int IMAGEBASE_RGBA_COMPRESSED = 108;
const int IMAGEBASE_RGBA4444 = 103;
const int IMAGEBASE_RGBA5551 = 102;
const int IMAGEBASE_Y_UP = 65536;
const int IMAGECUBE_NEG_X = 57;
const int IMAGECUBE_NEG_Y = 59;
const int IMAGECUBE_NEG_Z = 61;
const int IMAGECUBE_POS_X = 56;
const int IMAGECUBE_POS_Y = 58;
const int IMAGECUBE_POS_Z = 60;
const int INDEXBUFFER_LINES = 9;
const int INDEXBUFFER_POINT_SPRITES = 10;
const int INDEXBUFFER_TRIANGLES = 8;
const int KEYFRAMESEQUENCE_ADDITIVE_LOOP = 194;
const int KEYFRAMESEQUENCE_CONSTANT = 192;
const int KEYFRAMESEQUENCE_LINEAR = 176;
const int KEYFRAMESEQUENCE_LOOP = 193;
const int KEYFRAMESEQUENCE_SLERP = 177;
const int KEYFRAMESEQUENCE_SPLINE = 178;
const int KEYFRAMESEQUENCE_SQUAD = 179;
const int KEYFRAMESEQUENCE_STEP = 180;
const int LIGHT_AMBIENT = 128;
const int LIGHT_DIRECTIONAL = 129;
const int LIGHT_OMNI = 130;
const int LIGHT_SPOT = 131;
const int MATERIAL_AMBIENT = 1024;
const int MATERIAL_DIFFUSE = 2048;
const int MATERIAL_EMISSIVE = 4096;
const int MATERIAL_SPECULAR = 8192;
const int NODE_NONE = 144;
const int NODE_ORIGIN = 145;
const int NODE_X_AXIS = 146;
const int NODE_Y_AXIS = 147;
const int NODE_Z_AXIS = 148;
const int POLYGONMODE_CULL_BACK = 160;
const int POLYGONMODE_CULL_FRONT = 161;
const int POLYGONMODE_CULL_NONE = 162;
const int POLYGONMODE_SHADE_FLAT = 164;
const int POLYGONMODE_SHADE_SMOOTH = 165;
const int POLYGONMODE_WINDING_CCW = 168;
const int POLYGONMODE_WINDING_CW = 169;
const int SHADERUNIFORMS_ALPHA_FACTOR = 384;
const int SHADERUNIFORMS_BONE_MATRICES = 385;
const int SHADERUNIFORMS_CAMERA_FAR_DISTANCE = 386;
const int SHADERUNIFORMS_CAMERA_FIELD_OF_VIEW = 387;
const int SHADERUNIFORMS_CAMERA_NEAR_DISTANCE = 388;
const int SHADERUNIFORMS_CAMERA_PROJECTION = 389;
const int SHADERUNIFORMS_CAMERA_SPACE_DIRECTION = 390;
const int SHADERUNIFORMS_CAMERA_SPACE_POSITION = 391;
const int SHADERUNIFORMS_COMPOSITE_MATRIX = 392;
const int SHADERUNIFORMS_LIGHT_COLOR = 393;
const int SHADERUNIFORMS_MATRIX = 394;
const int SHADERUNIFORMS_MODEL_SPACE_DIRECTION = 395;
const int SHADERUNIFORMS_MODEL_SPACE_POSITION = 396;
const int SHADERUNIFORMS_ORIENTATION = 397;
const int SHADERUNIFORMS_SCALE = 398;
const int SHADERUNIFORMS_TRANSLATION = 399;
const int SHADERUNIFORMS_WORLD_SPACE_DIRECTION = 400;
const int SHADERUNIFORMS_WORLD_SPACE_POSITION = 401;
const int SHADERVARIABLE_BOOL = 321;
const int SHADERVARIABLE_BVEC2 = 326;
const int SHADERVARIABLE_BVEC3 = 327;
const int SHADERVARIABLE_BVEC4 = 328;
const int SHADERVARIABLE_FLOAT = 320;
const int SHADERVARIABLE_INT = 322;
const int SHADERVARIABLE_IVEC2 = 329;
const int SHADERVARIABLE_IVEC3 = 330;
const int SHADERVARIABLE_IVEC4 = 331;
const int SHADERVARIABLE_MAT2 = 332;
const int SHADERVARIABLE_MAT3 = 333;
const int SHADERVARIABLE_MAT3X4 = 335;
const int SHADERVARIABLE_MAT4 = 334;
const int SHADERVARIABLE_SAMPLER_2D = 336;
const int SHADERVARIABLE_SAMPLER_CUBE = 337;
const int SHADERVARIABLE_VEC2 = 323;
const int SHADERVARIABLE_VEC3 = 324;
const int SHADERVARIABLE_VEC4 = 325;
const int STENCIL_BACK = 262144;
const int STENCIL_DECR = 68;
const int STENCIL_DECR_WRAP = 71;
const int STENCIL_FRONT = 131072;
const int STENCIL_INCR = 67;
const int STENCIL_INCR_WRAP = 70;
const int STENCIL_INVERT = 69;
const int STENCIL_KEEP = 65;
const int STENCIL_REPLACE = 66;
const int STENCIL_ZERO = 64;
const int TEXTURE_FILTER_ANISOTROPIC = 211;
const int TEXTURE_FILTER_BASE_LEVEL = 208;
const int TEXTURE_FILTER_LINEAR = 209;
const int TEXTURE_FILTER_NEAREST = 210;
const int TEXTURE2D_FUNC_ADD = 224;
const int TEXTURE2D_FUNC_BLEND = 225;
const int TEXTURE2D_FUNC_DECAL = 226;
const int TEXTURE2D_FUNC_MODULATE = 227;
const int TEXTURE2D_FUNC_REPLACE = 228;
const int TEXTURE2D_WRAP_CLAMP = 240;
const int TEXTURE2D_WRAP_MIRROR = 242;
const int TEXTURE2D_WRAP_REPEAT = 241;
const int TEXTURECOMBINER_ADD = 16;
const int TEXTURECOMBINER_ADD_SIGNED = 17;
const int TEXTURECOMBINER_ALPHA = 512;
const int TEXTURECOMBINER_CONSTANT = 28;
const int TEXTURECOMBINER_DOT3_RGB = 18;
const int TEXTURECOMBINER_DOT3_RGBA = 19;
const int TEXTURECOMBINER_INTERPOLATE = 20;
const int TEXTURECOMBINER_INVERT = 256;
const int TEXTURECOMBINER_MODULATE = 21;
const int TEXTURECOMBINER_PREVIOUS = 30;
const int TEXTURECOMBINER_PRIMARY = 29;
const int TEXTURECOMBINER_REPLACE = 22;
const int TEXTURECOMBINER_SUBTRACT = 23;
const int TEXTURECOMBINER_TEXTURE = 31;
const int VERTEXARRAY_BYTE = 1;
const int VERTEXARRAY_FIXED = 3;
const int VERTEXARRAY_FLOAT = 4;
const int VERTEXARRAY_HALF = 5;
const int VERTEXARRAY_SHORT = 2;

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
struct base_object;
typedef base_object* (*make_t)();
make_t create_object[SECTION_COUNT];

template<class T>
void register_object()
{
	create_object[T::object_type] = T::make;
}

struct base_object
{
	virtual int load(Stream& strm, int version) = 0;
	virtual void print(FILE* out) = 0;
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

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += strm.read(&version_number);
		size += strm.read(&has_external_references);
		size += strm.read(&total_file_size);
		size += strm.read(&approximate_content_size);
		size += strm.read(&authoring_field);
		return size;
	}
	virtual void print(FILE* out)
	{
		fprintf(out, "version: %d.%d\n", version_number[0],
			version_number[1]);
		fprintf(out, "external refs: %d\n", has_external_references);
		fprintf(out, "total file size: %d\n", total_file_size);
		fprintf(out, "approximate context size: %d\n",
			approximate_content_size);
		fprintf(out, "authoring field: %s\n", authoring_field.c_str());
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

	virtual int load(Stream& strm, int version)
	{
		return strm.read(&URI);
	}

	virtual void print(FILE* out)
	{
		fprintf(out, "URI: %s\n", URI.c_str());
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

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += external_ref_object::load(strm, version);
		size += strm.read(&format);
		return size;
	}

	virtual void print(FILE* out)
	{
		external_ref_object::print(out);
		fprintf(out, "format: %d\n", format);
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

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += external_ref_object::load(strm, version);
		size += strm.read_varray(&user_id);
		return size;
	}
	virtual void print(FILE* out)
	{
		external_ref_object::print(out);
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

	virtual int load(Stream& strm, int version)
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

	virtual void print(FILE* out)
	{
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

	virtual int load(Stream& strm, int version)
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

	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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

	virtual int load(Stream& strm, int version)
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

	virtual int load(Stream& strm, int version)
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

	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		appearance_base_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += transformable_object::load(strm, version);
		size += strm.read(&enable_rendering);
		size += strm.read(&enable_picking);
		size += strm.read(&alpha_factor);
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
				size += strm.read_array(&min, 13);
				size += strm.read_array(&max, 13);
			}

			size += strm.read(&lod_resolution);
		}
		return size;
	}
	virtual void print(FILE* out)
	{
		transformable_object::print(out);
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
	Float32 heigth;
	Float32 fovy;
	Float32 aspect_ratio;
	Float32 near;
	Float32 far;

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		node_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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
	Float32 dencity;
	Float32 near;
	Float32 far;

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		node_object::print(out);
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
	UInt32 heigth;

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		image_base_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
			size += strm.read(&indices._uint32);
		else if (encoding == 129)
			size += strm.read(&indices._byte);
		else if (encoding == 130)
			size += strm.read(&indices._uint16);
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
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
				keyframes.push(kf);
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
			for (int i = 0 : i < event_count; ++i)
			{
				event_s e;
				size += strm.read(&e.event_time);
				size += strm.read(&e.event_id);
				events.push_back(e);
			}
		}
		return size;
	}
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		node_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
			for (int i = 0; i < morph_targer; ++i)
			{
				target_buf_s tb;
				size += strm.read(&tb.morph_target);
				size += strm.read(&tb.inital_weight);
				target_buffers.push_back(tb);
			}
			size += strm.read_varray(&morph_subset);
		}
		return size;
	}
	virtual void print(FILE* out)
	{
		node_object::print(out);
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

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += mesh_object::load(strm, version);
		if (version == M3G_FILE_FORMAT_10)
		{
			UInt32 morph_target;
			size += strm.read(&morph_target);
			for (int i = 0; i < morph_targer; ++i)
			{
				target_buf_s tb;
				size += strm.read(&tb.morph_target);
				size += strm.read(&tb.inital_weight);
				target_buffers.push_back(tb);
			}
		}
		return size;
	}
	virtual void print(FILE* out)
	{
		mesh_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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
		Int32 weght;
	};

	ObjectIndex skeleton;
	Boolean is_using_add_transform;
	std::vector<bone_s> bones;

	virtual int load(Stream& strm, int version)
	{
		UInt32 ref_count;
		int size = 0;
		size += mesh_object::load(strm);
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
	virtual void print(FILE* out)
	{
		mesh_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		node_object::print(out);
	}
};

// Texture
struct texture_object : transformable_object
{
	ObjectIndex image;
	Byte level_filter;
	Byte image_filter;

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += transformable_object::load(strm, version);
		if (version == M3G_FILE_FORMAT_20)
		{
			size += strm.read(&level_filter);
			size += strm.read(&image_filter);
		}
		return size;
	}
	virtual void print(FILE* out)
	{
		transformable_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		texture_object::print(out);
	}
};

// TriangleStripArray
struct triangle_strip_array_object : index_buffer_object
{
	static base_object* make()
	{
		return new triangle_strip_array();
	}
	enum
	{
		object_type = 11,
	};

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += index_buffer_object::load(strm, version);

		if (version == M3G_FILE_FORMAT_10)
		{
			size += strm.read_varray(&strip_lengths);
		}
		return size;
	}
	virtual void print(FILE* out)
	{
		index_buffer_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
	ObjectIndex point_sizes;
	Float32 default_point_size;

	ObjectIndex bone_indices;
	ObjectIndex bone_weights;
	std::vector<attribute_s> attributes;

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += object3d_object::load(strm, version);
		size += strm.read(&default_color);
		size += strm.read(&position);
		size += strm.read_array(&position_bias, 3);
		size += strm.read(&position_scale);
		size += strm.read(&normals);
		size += strm.read(&colors);

		UInt32 tex_count;
		size += strm.read(&tex_count);
		for (int i = 0; i < tex_count; ++i)
		{
			coords_s crd;
			size += strm.read(&crd.coord);
			size += strm.read_array(&crd.bias, 3);
			size += strm,read(&crd.scale);
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
					&a.default_attribute_value, 4);
				attributes.push_back(a);
			}
		}
		return size;
	}
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += group_object::load(strm, version);
		size += strm.read(&active_camera);
		size += strm.read(&background);
	}
	virtual void print(FILE* out)
	{
		group_node::print(out);
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

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
	}
};

// DynamicImage2D
struct dynamic2d_object : object3d_object
{
	static base_object* make()
	{
		new return dynamic2d_object();
	}
	enum
	{
		object_type = 24,
	};

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += dynamic2d_object::load(strm, version);
		return size;
	}
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
	}
};

// Shader
struct shader_object : object3d_object
{
	StringUTF8 source;

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += object3d_object::load(strm, version);
		size += strm.read(&source);
		return size;
	}
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
	}
};

// FragmentShader
struct fragment_shader_object : shader_object
{
	static base_object* make()
	{
		return fragment_shader_object();
	}
	enum
	{
		object_type = 25,
	};

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += shader_object::load(strm, version);
		return size;
	}
	virtual void print(FILE* out)
	{
		shader_object::print(out);
	}
};

// ImageCube
struct image_cube_object : image_base_object
{
	static base_object* make()
	{
		return image_cube_object();
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

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += image_base_object::load(strm, version);

		if (!is_mutable)
		{
			for (int i = 0; i < 6; ++i)
			{
				size += strm.read_varray(&mipmaps[i].pixels);
				size += strm.read(&mipmaps[i].mipmap_count);
				for (int j = 0; j < mipmap_count; ++j)
				{
					face_s::mipmap_s mm;
					size += strm.read_varray(&mm.values);
					mipmaps[i].mipmaps_pixels.push_back(mm);
				}
			}
		}
		return size;
	}
	virtual void print(FILE* out)
	{
		image_base_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += object3d_object::load(strm, version);
		size += strm.read(&scene);
		size += strm.read(&camera);
		size += strm.read(&background);
		size += strm.read(&targer);
		size += strm.read(&flags);
		size += strm.read(&depth_range_near);
		size += strm.read(&depth_range_far);
		size += strm.read(&is_viewport_set);
		if (is_viewport_set)
		{
			size += strm.read(viewport_x);
			size += strm.read(viewport_y);
			size += strm.read(viewport_width);
			size += strm.read(viewport_height);
		}
		return size;
	}
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
	}
};

// RenderTarget
struct render_target_object : object3d_object
{
	static base_object* make()
	{
		retun new render_target_object();
	}
	enum
	{
		object_type = 30,
	};

	ObjectIndex target;
	Byte target_level;
	Byte target_face;

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += object3d_object::load(strm, version);
		size += strm.read(&target);
		size += strm.read(&target_level);
		size += strm.read(&target_face);
		return size;
	}
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
	}
};

// ShaderAppearance
struct shader_appearance_object : appearance_base_object
{
	static base_object* make()
	{
		return shader_appearance_object();
	}
	enum
	{
		object_type = 31,
	};

	ObjectIndex shader_program;
	std::vector<ObjectIndex> shader_uniforms;
	Boolean is_validate_enabled;

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += appearance_base_object::load(strm, version);
		size += strm.read(&shader_program);
		size += strm.read_varray(&shader_uniforms);
		size += strm.read(&is_validate_enabled);
		return size;
	}
	virtual void print(FILE* out)
	{
		appearance_base_object::print(out);
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

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += object3d_object::load(strm, version);
		size += strm.read(&fragment_shader);
		size += strm.read(&vertex_shader);
		return size;
	}
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
	}
};

// ShaderUniforms
struct shader_uniforms_object : object3d_object
{
	static base_object* make()
	{
		return shader_uniforms_object();
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

	virtual int load(Stream& strm, int version)
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
				if (type == SHADERVARIABLE_BOOL)
					size += strm.read_array(&u.value._bool,
						length);
				else if (type == SHADERVARIABLE_BVEC2)
					size += strm.read_array(&u.value._bool,
						2 * length);
				else if (type == SHADERVARIABLE_BVEC3)
					size += strm.read_array(&u.value._bool,
						3 * length);
				else if (type == SHADERVARIABLE_BVEC4)
					size += strm.read_array(&u.value._bool,
						4 * length);
				else if (type == SHADERVARIABLE_INT)
					size += strm.read_array(&u.value._int32,
						length);
				else if (type == SHADERVARIABLE_INT2)
					size += strm.read_array(&u.value._int32,
						2 * length);
				else if (type == SHADERVARIABLE_INT3)
					size += strm.read_array(&u.value._int32,
						3 * length);
				else if (type == SHADERVARIABLE_INT4)
					size += strm.read_array(&u.value._int32,
						4 * length);
				else if (type == SHADERVARIABLE_FLOAT)
					size += strm.read_array(
						&u.value._float32,
						length);
				else if (type == SHADERVARIABLE_VEC2)
					size += strm.read_array(
						&u.value._float32,
						2 * length);
				else if (type == SHADERVARIABLE_VEC3)
					size += strm.read_array(
						&u.value._float32,
						3 * length);
				else if (type == SHADERVARIABLE_VEC4)
					size += strm.read_array(
						&u.value._float32,
						4 * length);
				else if (type == SHADERVARIABLE_MAT2)
					size += strm.read_array(
						&u.value._float32,
						4 * length);
				else if (type == SHADERVARIABLE_MAT3)
					size += strm.read_array(
						&u.value._float32,
						9 * length);
				else if (type == SHADERVARIABLE_MAT3X4)
					size += strm.read_array(
						&u.value._float32,
						12 * length);
				else if (type == SHADERVARIABLE_MAT4)
					size += strm.read_array(
						&u.value._float32,
						16 * length);
				else if (type == SHADERVARIABLE_SAMPLER_2D)
					size += strm.read_array(
						&u.value._index,
						length);
				else if (type == SHADERVARIABLE_SAMPLER_CUBE)
					size += strm.read_array(
						&u.value._index,
						length);

				UInt32 track_count;
				size += strm.read(&track_count);
				for (int j = 0; j < size; ++j)
				{
					track_s t;
					size += strm.read(&t.animation_track);
					size += strm.read(&t.channel_index);
					u.tracks.push_back(t);
				}
			}
			else if (binding_type == 1)
			{
				ForwardIndex i;
				size += strm.read_varray(&u.node_from);
				size += strm.read(&i);
				u.node_to.push_back(i);
			}
			else if (binding_type == 2)
			{
				ForwardIndex i;
				size += strm.read(&i);
				size += strm.read_varray(&u.node_to);
				u.node_from.push_back(i);
			}
			else if (binding_type == 3)
			{
				size += strm.read_varray(&u.source);
				size += strm.read(u.property);
			}
			uniforms.push_back(u);
		}
		return size;
	}
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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

	virtual int load(Stream& strm, int version)
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
	virtual void print(FILE* out)
	{
		object3d_object::print(out);
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

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += texture_object::load(strm, version);
		return size;
	}
	virtual void print(FILE* out)
	{
		texture_object::print(out);
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

	virtual int load(Stream& strm, int version)
	{
		int size = 0;
		size += shader_object::load(strm, version);
		return size;
	}
	virtual void print(FILE* out)
	{
		shader_object::print(out);
	}
};

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

#endif//__M3G_FORMAT_H__
