/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  image2D.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27.01.2010 13:38:58
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined(__IMAGE2D_H__)
#define __IMAGE2D_H__

#include "image_base.h"

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

	struct mipmap
		: m3g_base_type
	{
		std::vector<Byte> mipmap_pixels;
		mipmap()
		{
			DEFINE_M3G_VARRAY(Byte, "mipmapPixels",
				M3G_FILE_FORMAT_20);
		}
		template<class T>
		void traverse(T &op)
		{
			M3G_TYPE("mipmapPixels", op);
		}
		virtual int load(Stream &strm, int version)
		{
			LOAD_TEMPLATE(m3g_base_type, strm, version);
		}
		virtual int save(Stream &strm, int version)
		{
			SAVE_TEMPLATE(m3g_base_type, strm, version);
		}
		virtual void print(FILE *out, std::string const &indent,
			int version)
		{
			PRINT_TEMPLATE(m3g_base_type, "MipmapItem",
				out, indent, version);
		}
	};

	image2d_object()
	{
		DEFINE_M3G_VARRAY(Byte, "palette",
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_VARRAY(Byte, "basePixels",
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Byte, "mipmapCount", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_VARRAY(mipmap, "Mipmaps",
			M3G_FILE_FORMAT_20);
	}

	template<class T>
	void traverse(T &op)
	{
		if (M3G_TYPE_CAST("isMutable", Boolean))
		{
			Byte mmCount;
			M3G_TYPE("palette", op);
			M3G_TYPE("basePixels", op);
			M3G_TYPE("mipmapCount", op);
			mmCount = M3G_TYPE_CAST("mipmapCount", Byte);
			M3G_TYPE("Mipmaps", op);
		}
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

inline void print_value(FILE *out, char const *indent, char const *name,
	std::vector< image2d_object::mipmap>& v, int version)
{
	std::string new_indent = std::string(indent) + "\t";
	operation_print op(out, new_indent, version);
	if (v.size() == 0)
		return;
	fprintf(out, "%s%s\n%s{\n", indent, name, indent);
	fprintf(out, "%sByte count = %d;\n", new_indent.c_str(), v.size());
	for (int i = 0; i < v.size(); ++i)
	{
		fprintf(out, "%s/* %d */\n", new_indent.c_str(), i);
		v[i].traverse(op);
	}
	fprintf(out, "%s}\n", indent);
}
template<>
inline int Stream::read(std::vector< image2d_object::mipmap > > *v, int count)
{
	int size = 0;
	for (int i = 0; i < count; ++i)
	{
		image2d_object::mipmaps t;
		t.load(*this, version);
		v->push_back(t);
	}
	return size;
}

#endif//__IMAGE2D_H__

