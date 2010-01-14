/* vim:set ts=8 sts=8 sw=8 noet: */
/*
 * =============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/12/2010 07:17:57 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Valery Volgutov (valerii76), valerii76@gmail.com
 *        Company:  
 *
 * =============================================================================
 */
#include <stdio.h>
#include "m3gfile.h"

int main(int argc, char** argv)
{
	printf("m3gdecompile\n");
	if (m3g_check_file("data/texturedcar2n.m3g"))
		printf("file ok\n");
	else
		printf("file has error\n");
	return 0;
}

