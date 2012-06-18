/*
* FILENAME:		sub_max_array.c/sub_max_array.h
* CREATED AT:		2012/Jun/18
* DECRITION:		the max sum sub array
* 
* MODULE:		pro-pearl
* PLATFORM:		ubuntu-12.04/gcc-4.6.3
* AUTHOR:		incarnation-lee
* 
* ----------------------REVISION HISTROY------------------------
* No.	Date	Revised by	Function	Descrition
* 1	12/6/18	incar-lee			created
*
*/


#ifndef SUB_MAX_ARRAY_H
#define SUB_MAX_ARRAY_H

#include <stddef.h>
#include <sys/types.h>


void sub_m_ay(void);			/* the max sum sub array in O(n) */
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

#endif

