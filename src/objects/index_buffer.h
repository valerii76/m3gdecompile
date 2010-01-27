/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  index_buffer.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27.01.2010 17:03:59
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined(__INDEX_BUFFER_H__)
#define __INDEX_BUFFER_H__

#include "object3d.h"

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

	index_buffer_object()
	{
		DEFINE_M3G_TYPE(Byte, "encoding", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Boolean, "isImmutable", false,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Byte, "primitiveType", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Byte, "stripEncoding", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(UInt32, "primitiveCount_ui32", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_VARRAY(UInt32, "stripLengths_ui32",
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(Byte, "primitiveCount_b", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_VARRAY(Byte, "stripLengths_b",
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(UInt16, "primitiveCount_ui16", 0,
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_VARRAY(UInt16, "stripLengths_ui16",
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_TYPE(UInt32, "startIndex_ui32", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(Byte, "startIndex_b", 0,
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_TYPE(UInt16, "startIndex_ui16", 0
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_VARRAY(UInt32, "indices_ui32",
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_VARRAY(Byte, "indices_b",
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_VARRAY(UInt16, "indices_ui16",
			M3G_FILE_FORMAT_ALL);
		DEFINE_M3G_VARRAY(Int32, "indexDeltas_i32",
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_VARRAY(Byte, "indexDeltas_b",
			M3G_FILE_FORMAT_20);
		DEFINE_M3G_VARRAY(Int16, "indexDeltas_i16",
			M3G_FILE_FORMAT_20);
	}
	template<class T>
	void traverse(T &op)
	{
		Byte encoding;
		M3G_TYPE("encoding", op);
		encoding = M3G_TYPE_CAST("encoding", Byte);
		if (op.version == M3G_FILE_FORMAT_20)
		{
			Byte stripEncoding;
			M3G_TYPE("isImmutable", op);
			M3G_TYPE("primitiveType", op);
			M3G_TYPE("stripEncoding", op);
			stripEncoding = M3G_TYPE_CAST("stripEncoding", Byte);
			if (stripEncoding == 0 || stripEncoding == 128)
			{
				M3G_TYPE("primitiveCount_ui32", op);
				if (stripEncoding == 128)
					M3G_TYPE("stripLengths_ui32", op);
			}
			else if (stripEncoding == 1 || stripEncoding == 129)
			{
				M3G_TYPE("primitiveCount_b", op);
				if (stripEncoding == 129)
					M3G_TYPE("stripLengths_b", op);
			}
			else if (stripEncoding == 2 || stripEncoding == 130)
			{
				M3G_TYPE("primitiveCount_ui16", op);
				if (stripEncoding == 130)
					M3G_TYPE("stripLengths_ui16", op);
			}
		}
		if (encoding == 0)
			M3G_TYPE("startIndex_ui32", op);
		else if (encoding == 1)
			M3G_TYPE("startIndex_b", op);
		else if (encoding == 2)
			M3G_TYPE("startIndex_ui16", op);
		else if (encoding == 128)
			M3G_TYPE("indices_ui32", op);
		else if (encoding == 129)
			M3G_TYPE("indices_b", op);
		else if (encoding == 130)
			M3G_TYPE("indices_ui16", op);
		else if (encoding == 192)
			M3G_TYPE("indexDeltas_i32", op);
		else if (encoding == 193)
			M3G_TYPE("indexDeltas_b", op);
		else if (encoding == 194)
			M3G_TYPE("indexDeltas_i16", op);
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


#endif//__INDEX_BUFFER_H__

