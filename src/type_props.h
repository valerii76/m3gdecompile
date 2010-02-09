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

#include "m3gfile.h"
#include <string.h>
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
	static char const* to_hex(Float32 v) { return 0;}
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
struct type_props<StringUTF8>
{
	static char const *name;
	static char const* to_string(StringUTF8 &v);
	static char const* to_hex(StringUTF8 &v) { return 0;}
};

template<>
struct type_props<Boolean>
{
	static char const *name;
	static char const* to_string(Boolean v);
	static char const* to_hex(Boolean v) { return 0;}
};

template<>
struct type_props<Vector3D>
{
	static char const *name;
	static char const* to_string(Vector3D &v);
	static char const* to_hex(Vector3D &v) { return 0;}
};

template<>
struct type_props<Matrix>
{
	static char const *name;
	static char const* to_string(Matrix &v);
	static char const* to_hex(Matrix &v) { return 0;}
};

template<>
struct type_props<ColorRGB>
{
	static char const *name;
	static char const* to_string(ColorRGB &v);
	static char const* to_hex(ColorRGB &v) { return 0;}
};

template<>
struct type_props<ColorRGBA>
{
	static char const *name;
	static char const* to_string(ColorRGBA &v);
	static char const* to_hex(ColorRGBA &v) { return 0;}
};

struct type_props_oi
{
	static char const *name;
	static char const* to_string(ObjectIndex v);
	static char const* to_hex(ObjectIndex v) { return 0;}
};

struct type_props_fi
{
	static char const *name;
	static char const* to_string(ForwardIndex v);
	static char const* to_hex(ForwardIndex v) { return 0;}
};

template<class T>
inline void print_value(FILE *out, char const *indent, char const *name, T v)
{
	fprintf(out, "%s%s %s = %s;\n", indent, type_props<T>::name,
		name, type_props<T>::to_string(v));
}

inline void print_value_oi(
	FILE* out,
	char const* indent,
	char const* name,
	ObjectIndex& value)
{
	fprintf(out, "%s%s %s = %s;\n", indent, type_props_oi::name,
		name, type_props_oi::to_string(value));
}

inline void print_value_fi(
	FILE* out,
	char const* indent,
	char const* name,
	ForwardIndex& value)
{
	fprintf(out, "%s%s %s = %s;\n", indent, type_props_fi::name,
		name, type_props_fi::to_string(value));
}

template<class T>
inline void print_array(
	FILE *out,
	char const *indent,
	char const *name,
	T* v,
	int len,
	int hex,
	int varray = false)
{
	char new_indent[255];
	strcpy(new_indent, indent);
	strcat(new_indent, "\t");
	if (!varray)
		fprintf(out, "%s%s %s[%d] = {\n", indent, type_props<T>::name,
			name, len);

	int const cols = 80;
	char row[8196];
	int curr_len = 0;
	memset(row, 0, 8196);
	for (int i = 0; i < len; ++i)
	{
		char const *value_str = 0;
		if (hex)
			value_str = type_props<T>::to_hex(v[i]);
		else
			value_str = type_props<T>::to_string(v[i]);
		if (!hex)
		{
			if (i < (len-1))
				fprintf(out, "%s%s,\n", new_indent, value_str);
			else
				fprintf(out, "%s%s\n", new_indent, value_str);
		}
		else
		{
			int value_len = strlen(value_str);
			if ((curr_len + value_len) < cols)
			{
				strcat(row, value_str);
				curr_len = strlen(row);
			}
			else
			{
				if (strlen(row))
					fprintf(out, "%s%s\n", new_indent, row);
				strcpy(row, value_str);
				curr_len = value_len;
			}
			if (i < (len-1))
			{
				strcat(row, ", ");
				curr_len = strlen(row);
			}
		}
	}
	if (strlen(row))
		fprintf(out, "%s%s\n", new_indent, row);

	if (!varray)
		fprintf(out, "%s};\n", indent);
}

template<class T>
inline void print_varray(
	FILE *out,
	char const *indent,
	char const *name,
	std::vector<T> &v,
	int hex)
{
	char new_indent[255];
	strcpy(new_indent, indent);
	strcat(new_indent, "\t");
	fprintf(out, "%svarray(%s) %s\n%s{\n", indent,
		type_props<T>::name, name, indent);
	fprintf(out, "%sUInt32 count = %d;\n", new_indent, v.size());
	if (v.size())
		print_array(out, indent, name,
			&v.front(), v.size(), hex, 1);
	fprintf(out, "%s};\n", indent);
}

inline void print_array_oi(
	FILE *out,
	char const *indent,
	char const *name,
	ObjectIndex *v,
	int len,
	int varray = 0)
{
	char new_indent[255];
	strcpy(new_indent, indent);
	strcat(new_indent, "\t");
	if (!varray)
		fprintf(out, "%s%s %s[%d] = {\n", indent, type_props_oi::name,
			name, len);
	for (int i = 0; i < len; ++i)
	{
		if (i < (len-1))
			fprintf(out, "%s%s,\n",
				new_indent, type_props_oi::to_string(v[i]));
		else
			fprintf(out, "%s%s\n",
				new_indent, type_props_oi::to_string(v[i]));
	}
	if (!varray)
		fprintf(out, "%s};\n", indent);
}

inline void print_varray_oi(
	FILE *out,
	char const *indent,
	char const *name,
	std::vector<ObjectIndex> &v)
{
	char new_indent[255];
	strcpy(new_indent, indent);
	strcat(new_indent, "\t");
	fprintf(out, "%svarray(%s) %s\n%s{\n", indent,
		type_props_oi::name, name, indent);
	fprintf(out, "%sUInt32 count = %d;\n", new_indent, v.size());
	if (v.size())
		print_array_oi(out, indent, name, &v.front(), v.size(), 1);
	fprintf(out, "%s};\n", indent);
}

inline void print_array_fi(
	FILE *out,
	char const *indent,
	char const *name,
	ForwardIndex *v,
	int len,
	int varray = 0)
{
	char new_indent[255];
	strcpy(new_indent, indent);
	strcat(new_indent, "\t");
	if (!varray)
		fprintf(out, "%s%s %s[%d] = {\n", indent, type_props_fi::name,
			name, len);
	for (int i = 0; i < len; ++i)
	{
		if (i < (len-1))
			fprintf(out, "%s%s,\n",
				new_indent, type_props_fi::to_string(v[i]));
		else
			fprintf(out, "%s%s\n",
				new_indent, type_props_fi::to_string(v[i]));
	}
	if (!varray)
		fprintf(out, "%s};\n", indent);
}

inline void print_varray_fi(
	FILE *out,
	char const *indent,
	char const *name,
	std::vector<ForwardIndex> &v)
{
	char new_indent[255];
	strcpy(new_indent, indent);
	strcat(new_indent, "\t");
	fprintf(out, "%svarray(%s) %s\n%s{\n", indent,
		type_props_fi::name, name, indent);
	fprintf(out, "%sUInt32 count = %d;\n", new_indent, v.size());
	if (v.size())
		print_array_fi(out, indent, name, &v.front(), v.size(), 1);
	fprintf(out, "%s};\n", indent);
}
#endif//__TYPE_PROPS_H__
