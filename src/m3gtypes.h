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

enum
{
	M3G_FILE_FORMAT_10 = 1,
	M3G_FILE_FORMAT_20 = 1 << 1,
	M3G_FILE_FORMAT_ALL = (M3G_FILE_FORMAT_10 | M3G_FILE_FORMAT_20),
};

#define M3G_TRUE 1
#define M3G_FALSE 0


struct m3g_base_type
{
	m3g_base_type()
		: name("")
		, version_support(M3G_FILE_FORMAT_ALL)
	{}

	m3g_base_type(std::string const &_name, int version)
		: name(_name)
		, version_support(version)
	{
	}

	lst_fields_t fields;
	virtual void print(FILE *out, std::string const &indent,
		int version)
	{
	}
	virtual int load(Stream &strm, int version)
	{
		return 0;
	}
	virtual int save(Stream &strm, int version)
	{
		return 0;
	}

	virtual ~m3g_base_type() {}


	std::string name;
	int version_support;
};


#endif//__M3GTYPES_H__
