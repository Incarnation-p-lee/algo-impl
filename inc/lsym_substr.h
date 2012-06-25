/*
* FILENAME:		lsym_substr.c/lsym_substr.h
* CREATED AT:		2012/Jun/25
* DECRITION:		Longest symmetry substring
* 
* MODULE:		pro-pearl
* PLATFORM:		ubuntu-12.04/gcc-4.6.3
* AUTHOR:		incarnation-lee
* 
* ----------------------REVISION HISTROY------------------------
* No.	Date	Revised by	Function	Descrition
* 1	12/6/25	incar-lee			created
*
*/


#ifndef LSYM_SUBSTR_H
#define LSYM_SUBSTR_H

#include <sys/types.h>
#include <stddef.h>
#include <fcntl.h>


#include "typedefs.h"


#ifdef __GNUC__

#define max(x,y) ({\
		typeof (x) _x = (x);\
		typeof (y) _y = (y);\
		_x > _y?_x:_y;	})

#else
#define max(x,y) ((x)>(y)?(x):(y))
#endif


void lsym_sstr(void)__attribute__((pure));

#endif
