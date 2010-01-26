/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  type_props.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/19/2010 10:08:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !(defined __TYPE_PROPS_H__)
#define __TYPE_PROPS_H__

#include "m3gtypes.h"
#include <vector>
#include <stdio.h>

template<class T>
struct type_props;

template<>
struct type_props<Byte>
{
	static char const *name;
	static char const* to_string(Byte v);
	static char const* to_hex(Byte v);
};

template<>
struct type_props<SByte>
{
	static char const *name;
	static char const* to_string(SByte v);
	static char const* to_hex(SByte v);
};

template<>
struct type_props<Int16>
{
	static char const *name;
	static char const* to_string(Int16 v);
	static char const* to_hex(Int32 v);
};

template<>
struct type_props<UInt16>
{
	static char const *name;
	static char const* to_string(UInt16 v);
	static char const* to_hex(UInt16 v);
};

template<>
struct type_props<Int32>
{
	static char const *name;
	static char const* to_string(Int32 v);
	static char const* to_hex(Int32 v);
};

template<>
struct type_props<UInt32>
{
	static char const *name;
	static char const* to_string(UInt32 v);
	static char const* to_hex(UInt32 v);
};

template<>
struct type_props<Float32>
{
	static char const *name;
	static char const* to_string(Float32 v);
};
/*
template<>
struct type_props<Float16>
{
	static char const *name;
	static char const* to_string(Float16 v);
};
*/

template<>
struct type_props<String>
{
	static char const *name;
	static char const* to_string(String &v);
};

template<>
struct type_props<Boolean>
{
	static char const *name;
	static char const* to_string(Boolean v);
};

template<>
struct type_props<Vector3D>
{
	static char const *name;
	static char const* to_string(Vector3D &v);
};

template<>
struct type_props<Matrix>
{
	static char const *name;
	static char const* to_string(Matrix &v);
};

template<>
struct type_props<ColorRGB>
{
	static char const *name;
	static char const* to_string(ColorRGB &v);
};

template<>
struct type_props<ColorRGBA>
{
	static char const *name;
	static char const* to_string(ColorRGBA &v);
};

struct type_props_oi
{
	static char const *name;
	static char const* to_string(ObjectIndex v);
};

struct type_props_fi
{
	static char const *name;
	static char const* to_string(ForwardIndex v);
};

template<class T>
inline void print_value(FILE *out, char const *indent,
	char const *name, T &v, int version)
{
	fprintf(out, "%s%s %s = %s;\n", indent, type_props<T>::name,
		name, type_props<T>::to_string(v));
}

inline void print_value_oi(
	FILE* out,
	char const* indent,
	char const* name,
	ObjectIndex& value,
	int version)
{
	fprintf(out, "%s%s %s = %s;\n", indent, type_props_oi::name,
		name, type_props_oi::to_string(value));
}

inline void print_value_fi(
	FILE* out,
	char const* indent,
	char const* name,
	ForwardIndex& value,
	int version)
{
	fprintf(out, "%s%s %s = %s;\n", indent, type_props_fi::name,
		name, type_props_fi::to_string(value));
}

template<class T>
inline void print_value(
	FILE *out,
	char const *indent,
	char const *name,
	T* v,
	int len,
	int version,
	int varray = 0)
{
	if (varray == 0)
		fprintf(out, "%s%s %s[%d] = {\n", indent, type_props<T>::name,
			name, len);
	for (int i = 0; i < len; ++i)
	{
		if (i < (len-1))
			fprintf(out, "%s%s,\n",
				indent, type_props<T>::to_string(v[i]));
		else
			fprintf(out, "%s%s\n",
				indent, type_props<T>::to_string(v[i]));
	}
	if (varray == 0)
		fprintf(out, "%s};\n", indent);
}

template<class T>
inline void print_value(
	FILE *out,
	char const *indent,
	char const *name,
	std::vector<T> &v,
	int version)
{
	fprintf(out, "%s%s %s [] = {\n", indent, type_props<T>::name, name);
	fprintf(out, "%sUInt32 count = %d;\n", indent, v.size());
	if (v.size())
		print_value(out, indent, name, &v.front(), v.size(),
			version, 1);
	fprintf(out, "%s};\n", indent);
}

inline void print_array_oi(
	FILE *out,
	char const *indent,
	char const *name,
	ObjectIndex *v,
	int len,
	int version)
{
	fprintf(out, "%s%s %s[%d] = {\n", indent, type_props_oi::name,
		name, len);
	for (int i = 0; i < len; ++i)
	{
		if (i < (len-1))
			fprintf(out, "%s%s,\n",
				indent, type_props_oi::to_string(v[i]));
		else
			fprintf(out, "%s%s\n",
				indent, type_props_oi::to_string(v[i]));
	}
	fprintf(out, "%s};\n", indent);
}

inline void print_varray_oi(
	FILE *out,
	char const *indent,
	char const *name,
	std::vector<ObjectIndex> &v,
	int version)
{
	fprintf(out, "%sUInt32 count = %d;\n", indent, v.size());
	if (v.size())
		print_array_oi(out, indent, name, &v.front(),
			v.size(), version);
}

#endif//__TYPE_PROPS_H__
