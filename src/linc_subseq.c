/*
* FILENAME:		linc_subseq.c/linc_subseq.h
* CREATED AT:		2012/Jul/12
* DECRITION:		longest increment subsequence
* 
* MODULE:		pro-pearl
* PLATFORM:		ubuntu-12.04/gcc-4.6.3
* AUTHOR:		incarnation-lee
* 
* ----------------------REVISION HISTROY------------------------
* No.	Date	Revised by	Function	Descrition
* 1	12/6/25	incar-lee	lsym+sstr	created
*
*/

/* C Stardard */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

/* linux related */
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

/* usr defined */
#include "externals.h"
#include "typedefs.h"
#include "linc_subseq.h"



void linc_subseq()
{
	signed int input[] = {1,-1,2,-3,4,-5,6,-7};
	unsigned int i,j;
	unsigned int lis[sizeof(input)/sizeof(signed int)];
	signed int max = INT_MIN;

	memset(lis,0,sizeof(lis));
	lis[0] = 1;

	for(i=1;i<sizeof(input)/sizeof(signed int);i++)
	{
		fprintf(stdout,"%d ",input[i]);
		max = max>input[i-1]?max:input[i-1];
		if(input[i]>max)
			lis[i] = lis[i-1] + 1;
		else
			lis[i] = lis[i-1];
	}
	
	j = 0;
	for(i=0;i<sizeof(input)/sizeof(signed int);i++)
		j = j>lis[i]?j:lis[i];
	fprintf(stdout,"[%d]\n",j);
	return;
}
