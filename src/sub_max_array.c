/*
* FILENAME:		sub_max_array.c/sub_max_array.h
* CREATED AT:		2012/Jun/18
* DECRITION:		the max sum sub array.
* 
* MODULE:		pro-pearl
* PLATFORM:		ubuntu-12.04/gcc-4.6.3
* AUTHOR:		incarnation-lee
* 
* ----------------------REVISION HISTROY------------------------
* No.	Date	Revised by	Function	Descrition
* 1	12/6/18	incar-lee	sub_m_ay
*
*/

/* C standard */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>

/* linux related */
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

/* usr defined */
#include "externals.h"
#include "typedefs.h"
#include "sub_max_array.h"


/* static const signed short input_ay[] = {-1,-2,3,-10,-4,-7,-9,-5,};*/
static const signed short input_ay[] = {1,-2,3,10,-4,7,2,-5,};
/* static const signed short input_ay[] = {3,-3,-3,3,-4,4,-5,5,}; test cast */
/* static const signed short input_ay[] = {-3,2,-4,3,-5,4,-6,5,}; */


void sub_m_ay()
{
	short i;
	int max = -0xffff,tmp = 0;	
	short rst_b = 0,rst_e = 0,begin = 0;		/* begin is necessary for update begin index */

	for(i=0;i<sizeof(input_ay)/sizeof(signed short);i++)
	{
		tmp += input_ay[i];	
		if(tmp>max)				/* update the begin and end index */
		{
			rst_b = begin;			/* begin used for some specific case, all ele <0 or single >0 */
			rst_e = i;
			max = tmp;
		}	
		if(tmp<0)
		{
			begin = i + 1;
			tmp = 0;
		}
	}
	
	for(i=rst_b;i<=rst_e;i++)
	{
		fprintf(stdout,"%d ",input_ay[i]);	
	}
	fprintf(stdout,"[%d]\n",max);
	return;
}
