/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  type_props.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/19/2010 11:12:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#include "type_props.h"

char const *type_props<Byte>::name = "Byte";
char const* type_props<Byte>::to_string(Byte v)
{
	static char str[255];
	sprintf(str, "%d", v);
	return str;
}
char const* type_props<Byte>::to_hex(Byte v)
{
	static char str[255];
	sprintf(str, "0x%X", v);
	return str;
}


char const *type_props<SByte>::name = "SByte";
char const* type_props<SByte>::to_string(SByte v)
{
	static char str[255];
	sprintf(str, "%d", v);
	return str;
}
char const* type_props<SByte>::to_hex(SByte v)
{
	static char str[255];
	sprintf(str, "0x%X", v);
	return str;
}


char const *type_props<Int16>::name = "Int16";
char const* type_props<Int16>::to_string(Int16 v)
{
	static char str[255];
	sprintf(str, "%d", v);
	return str;
}
char const* type_props<Int16>::to_hex(Int32 v)
{
	static char str[255];
	sprintf(str, "0x%X", v);
	return str;
}


char const *type_props<UInt16>::name = "UInt16";
char const* type_props<UInt16>::to_string(UInt16 v)
{
	static char str[255];
	sprintf(str, "%d", v);
	return str;
}
char const* type_props<UInt16>::to_hex(UInt16 v)
{
	static char str[255];
	sprintf(str, "0x%X", v);
	return str;
}


char const *type_props<Int32>::name = "Int32";
char const* type_props<Int32>::to_string(Int32 v)
{
	static char str[255];
	sprintf(str, "%d", v);
	return str;
}
char const* type_props<Int32>::to_hex(Int32 v)
{
	static char str[255];
	sprintf(str, "0x%X", v);
	return str;
}


char const *type_props<UInt32>::name = "UInt32";
char const* type_props<UInt32>::to_string(UInt32 v)
{
	static char str[255];
	sprintf(str, "%d", v);
	return str;
}
char const* type_props<UInt32>::to_hex(UInt32 v)
{
	static char str[255];
	sprintf(str, "0x%X", v);
	return str;
}

char const *type_props<Float32>::name = "Float32";
char const* type_props<Float32>::to_string(Float32 v)
{
	static char str[255];
	sprintf(str, "%g", v);
	return str;
}

/*
char const *type_props<Float16>::name = "Float16";
char const* type_props<Float16>::to_string(Float16 v)
{
	static char str[255];
	sprintf(str, "%g", v);
	return str;
}
*/

char const *type_props<StringUTF8>::name = "String";
char const* type_props<StringUTF8>::to_string(StringUTF8 &v)
{
	static StringUTF8 str;
	str = '\"' + v + '\"';
	return str.c_str();
}


char const *type_props<Boolean>::name = "Boolean";
char const* type_props<Boolean>::to_string(Boolean v)
{
	static char t[] = "true";
	static char f[] = "false";
	return v ? t : f;
}


char const *type_props<Vector3D>::name = "Vector3D";
char const* type_props<Vector3D>::to_string(Vector3D &v)
{
	static char str[512];
	sprintf(str, "{ %g, %g, %g }", v.x, v.y, v.z);
	return str;
}


char const *type_props<Matrix>::name = "Matrix";
char const* type_props<Matrix>::to_string(Matrix &v)
{
	static char str[2048];
	sprintf(str, "{ %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g, %g }",
		v.v[0], v.v[1], v.v[2], v.v[3],
		v.v[4], v.v[5], v.v[6], v.v[7],
		v.v[8], v.v[9], v.v[10], v.v[11],
		v.v[12], v.v[13], v.v[14], v.v[15]);
	return str;
}


char const *type_props<ColorRGB>::name = "ColorRGB";
char const* type_props<ColorRGB>::to_string(ColorRGB &v)
{
	static char str[255];
	sprintf(str, "{ %d, %d, %d }", v.red, v.green, v.blue);
	return str;
}


char const *type_props<ColorRGBA>::name = "ColorRGBA";
char const* type_props<ColorRGBA>::to_string(ColorRGBA &v)
{
	static char str[255];
	sprintf(str, "{ %d, %d, %d, %d }",
		v.red, v.green, v.blue, v.alpha);
	return str;
}


char const *type_props_oi::name = "ObjectIndex";
char const* type_props_oi::to_string(ObjectIndex v)
{
	static char str[255];
	sprintf(str, "%d", v);
	return str;
}


char const *type_props_fi::name = "ForwardIndex";
char const* type_props_fi::to_string(ForwardIndex v)
{
	static char str[255];
	sprintf(str, "%d", v);
	return str;
}
