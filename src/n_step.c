/*
* FILENAME:		n_step.c/n_step.h
* CREATED AT:		2012/Jun/25
* DECRITION:		how many ways of n step
* 
* MODULE:		pro-pearl
* PLATFORM:		ubuntu-12.04/gcc-4.6.3
* AUTHOR:		incarnation-lee
* 
* ----------------------REVISION HISTROY------------------------
* No.	Date	Revised by	Function	Descrition
* 1	12/6/26	incar-lee			created
*
*/

/* C Stardard */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* linux related */
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

/* usr defined */
#include "externals.h"
#include "typedefs.h"
#include "n_step.h"


void nstep_way(void)
{
	int i = 0;
	int qa_nstep[] = {1,2,10,12,0,-1,};
	for(i=0;i<sizeof(qa_nstep)/sizeof(int);i++)
		fprintf(stdout,"[%d]step:%d\n",qa_nstep[i],n_step(qa_nstep[i]));
}

unsigned int n_step(int N)
{
	if(1>N)
		return 0;
	if(1==N)
		return 1;
	if(2==N)
		return 2;
	return n_step(N-1)+n_step(N-2);	
}

