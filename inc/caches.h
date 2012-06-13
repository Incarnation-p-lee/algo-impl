/*
* created at:		2012/Apr/27
* last modify:		2012/Apr/27
* description:		external function or control variables
*/
#ifndef CACHE_H
#define CACHE_H
#include <stdlib.h>


#define DUMBCOPY for(i=0;i<65536;i++) \
	dest[i] = sou[i]

#define SMARTCOPY memcpy(dest,sou,65535)

int cache_affect(void) __attribute__((pure));

#endif
