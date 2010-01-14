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

enum
{
	M3G_SUCCESS			= 0,
	M3G_INVALID_FILE_IDENTIFIER,

	M3G_MAX = 0x7fff,
};

int m3g_last_error();
char* m3g_error_string(int error);

int m3g_check_file(char* file_name);
int m3g_check_data(char* data);

#endif//__M3GFILE_H__
