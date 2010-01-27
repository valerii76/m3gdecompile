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
#include "stream.h"
#include <vector>
#include "m3gtypes.h"
#include "property.h"
#include "m3gconstants.h"
#include "objects/base.h"
#include "objects/external_ref.h"
#include "objects/external_object_ref.h"
#include "objects/external_image_ref.h"



/*


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
*/
typedef std::vector<base_object*> lst_all_objects_t;
//typedef std::vector<object3d_object*> lst_objects_t;
typedef std::vector<external_ref_object*> lst_ext_refs_t;
typedef std::vector<external_object_ref_object*> lst_ext_obj_refs_t;
typedef std::vector<external_image_ref_object*> lst_ext_img_refs_t;

#endif//__M3G_FORMAT_H__
