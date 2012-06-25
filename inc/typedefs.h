/*
* created at:		2012/Apr/27
* last modify:		2012/Apr/27
* description:		external function or control variables
*/
#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <sys/types.h>
#include <string.h>

#include "externals.h"

#ifndef __GNUC__
#define __attribut__(x)
#define __builtin_expect(X)
#endif

typedef struct inpdata
{
	int elm_0;
	int elm_1;
	int elm_2;
	int elm_3;
	int elm_4;
	int elm_5;
	int elm_6;
	int elm_7;
	int elm_8;
	int elm_9;
}S_inpdata,*Sp_inpdata;


#endif
