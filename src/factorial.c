/*
* FILENAME:		factorial.c/factorial.h
* CREATED AT:		2012/Jun/19
* DECRITION:		how many zeros in factorial
* 
* MODULE:		pro-pearl
* PLATFORM:		ubuntu-12.04/gcc-4.6.3
* AUTHOR:		incarnation-lee
* 
* ----------------------REVISION HISTROY------------------------
* No.	Date	Revised by	Function	Descrition
  1	12/6/19	incar-lee	
*
*/

/* C Standard */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/* linux related */
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

/* usr defined */
#include "externals.h"
#include "typedefs.h"
#include "factorial.h"



/*
* how many zeros a factorial has
*/
void factorial_zero(void)
{
	unsigned int N = 20,tmp;
	unsigned short sum = 0;	
	int i;
	for(i=5;i<N+1;i++)
	{
		tmp = i;
		while(0==tmp%5)
		{
			tmp /= 5;	
			sum++;
		}	
	}
	fprintf(stdout,"%d! zeros=%d\n",N,sum);
	return;
}
