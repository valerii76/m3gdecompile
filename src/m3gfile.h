/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  m3gfile.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2010 08:42:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#if !defined(__M3GFILE_H__)
#define __M3GFILE_H__

#include <string>

typedef unsigned char	Byte;
typedef char		SByte;
typedef short		Int16;
typedef unsigned short	UInt16;
typedef long		Int32;
typedef unsigned long	UInt32;
typedef float		Float32;
typedef short		Float16;	//FIXME: NEED TO HALF-PERCISION FLOAT
typedef unsigned char	Boolean;
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

#define M3G_TRUE	1
#define M3G_FALSE	0


enum
{
	M3G_SUCCESS			= 0,
	M3G_INVALID_FILE_IDENTIFIER,

	M3G_MAX = 0x7fff,
};

int m3g_last_error();
char* m3g_error_string(int error);

int m3g_check_file(char const* file_name);
int m3g_check_data(char const* data);

#endif//__M3GFILE_H__
