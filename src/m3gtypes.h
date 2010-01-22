/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  m3gtypes.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22.01.2010 17:04:23
 *       Revision:  none
 *       Compiler:  
 *
 *         Author:  Valery Volgutov (MSN:valerii76@hotmail.com)
 *                  valery.volgutov@lge.com
 *        Company:  LGERP St.Petersburg Lab
 *
 * =============================================================================
 */
#if !defined(__M3GTYPES_H__)
#define __M3GTYPES_H__

#include <string>

typedef unsigned char	Byte;
typedef char		SByte;
typedef short		Int16;
typedef unsigned short	UInt16;
typedef long		Int32;
typedef unsigned long	UInt32;
typedef float		Float32;
typedef short		Float16;	//FIXME: NEED TO HALF-PERCISION FLOAT
typedef bool		Boolean;
typedef std::string	StringUTF8;

struct Vector3D
{
	Float32	x;
	Float32	y;
	Float32	z;
};

struct Matrix
{
	Float32 v[16];
};

struct ColorRGB
{
	Byte red;
	Byte green;
	Byte blue;
};

struct ColorRGBA
{
	Byte red;
	Byte green;
	Byte blue;
	Byte alpha;
};

typedef UInt32		ObjectIndex;
typedef UInt32		ForwardIndex;

#endif//__M3GTYPES_H__
