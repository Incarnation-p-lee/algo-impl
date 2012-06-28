/*
* FILENAME:		second_big.c/second_big.h
* CREATED AT:		2012/Jun/28
* DECRITION:		find the second biggest number of array in O(N)
* 
* MODULE:		pro-pearl
* PLATFORM:		ubuntu-12.04/gcc-4.6.3
* AUTHOR:		incarnation-lee
* 
* ----------------------REVISION HISTROY------------------------
* No.	Date	Revised by	Function	Descrition
* 1	12/6/28	incar-lee			created
*
*/


/* C Standard */
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/* linux related */
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

/* usr defined */
#include "typedefs.h"
#include "externals.h"
#include "second_big.h"


/*
* some test case of second biggest number in O(n)
*/
void second_big(void)
{
	int sed_bg[][10] = {
		{-45,-3,-74,87,-1,-34,-4,-61,-14,-2},
		{1,2,4,-2,59,38,23,12,84,98,},
		{2,2,2,2,2,2,2,2,2,2,},
		{81,81,74,8,0,-34,-4,-61,-14,-2},
	};
	int i,j;
	signed int sdb = 0;

	for(i=0;i<sizeof(sed_bg)/sizeof(sed_bg[0]);i++)
	{
		sdb = sed_bgst(sed_bg[i],sizeof(sed_bg[0])/sizeof(int));
		for(j=0;j<sizeof(sed_bg[0])/sizeof(int);j++)
			fprintf(stdout,"%d ",*(*(sed_bg+i)+j));
		fprintf(stdout,":[%d]\n",sdb);
	}	
	return;
}

/*
* implement the second biggest number of array within O(N)
*/
static inline signed int sed_bgst(int* sdb,size_t len)
{
	size_t sbe = 0;
	signed int demax,max = -0x7FFFFFFF;

	assert(NULL!=sdb);
	demax = max;
	while(len!=sbe)						/* take care of some specific situation */
	{
		if(sdb[sbe]>max)				/* ensure demax is always < max */
		{
			demax = max;
			max = sdb[sbe];
		}
		else if(sdb[sbe]>demax && sdb[sbe]<max)		/* if the same to max at later */	
			demax = sdb[sbe];
		sbe++;
	}
	if(demax==max)						/* if there is no second biggest number */
		return -0x7FFFFFF;	
	return demax;
}
