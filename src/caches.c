/*
* created at:		2012/Apr/27
* last modify:		2012/Apr/27
* decrition:		the effecttion to program running of caches
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>


#include <sys/time.h>

#include "externals.h"
#include "typedefs.h"
#include "caches.h"



struct timeval start,end;

int cache_affect()
{
	int time_cost;
	char sou[65535];
	char dest[65535];
	int i = 0,j = 0;

	gettimeofday(&start,0);
	for(j=0;j<100;j++)
		SMARTCOPY;
	gettimeofday(&end,0);
	time_cost = end.tv_usec - start.tv_usec;
	fprintf(stdout," SMART time cost : %d us. \n",time_cost);

	for(j=0;j<100;j++)
		DUMBCOPY;
	gettimeofday(&start,0);
	time_cost = start.tv_usec - end.tv_usec;
	fprintf(stdout," DUMB time cost : %d us. \n",time_cost);

	return 0;
}
