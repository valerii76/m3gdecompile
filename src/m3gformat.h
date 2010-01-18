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


struct base_object
{
	static base_object* make(int obj_type);
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

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
};

// Texture
struct texture_object : transformable_object
{
	ObjectIndex image;
	Byte level_filter;
	Byte image_filter;

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
};

// Shader
struct shader_object : object3d_object
{
	StringUTF8 source;

	virtual int load(Stream& strm, int version);
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
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
	virtual void print(FILE* out);
};


#endif//__M3G_FORMAT_H__
