/*
* FILENAME:		cycle_shift.c/cycle_shift.h
* CREATED AT:		2012/Jun/27
* DECRITION:		implement cycle shift with 2 tmp variable
* 
* MODULE:		pro-pearl
* PLATFORM:		ubuntu-12.04/gcc-4.6.3
* AUTHOR:		incarnation-lee
* 
* ----------------------REVISION HISTROY------------------------
* No.	Date	Revised by	Function	Descrition
* 1	12/6/27	incar-lee			created
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
#include "cycle_shift.h"


/*
* QA the right cs algorihtm
* destination can be slipted into D=(A)(B) 2 substrings
* difine ~ means revert the char[]
* D1=(~A)(B)
* D2=(~A)(~B)
* D3=~(D2)
* and D3 is the result of cycle right shift
* ->=>
* <-=>
* <-<=
* =>-> just switch location of -> and =>
*/
void right_cs(void)
{
	char qa_rcs[] = "1234abcd4321(*&^!@#$dcba"; 	/* test case data sample resource */
	int i,ct[] = {
		0,
		8,
		3,
		4,
		9,
		76,
	};						/* crs shift count */
	qa_rcs[3] = 't';
	for(i=0;i<sizeof(ct)/sizeof(int);i++)
	{
		fprintf(stdout,"%s cycle right shift %d: ",qa_rcs,ct[i]);
		right_cshift(qa_rcs,ct[i]);
		fprintf(stdout,"%s\n",qa_rcs);
	}	
	return;	
}
	
/*
* the right directive cycle shift, 2 template within O(n)
*/
void right_cshift(char *str,int N)
{
	size_t len = strlen(str);
	assert(NULL!=str);
	
	N %= len;
	reverse(str,0,len-N-1);
	reverse(str,len-N,len-1);
	reverse(str,0,len-1);
	return;
}

/*
* reverse the sequence of specified scole
*/
void reverse(char *str,int beg,int end)
{
	assert(NULL!=str);
	if(0>beg || end >=strlen(str) || beg>end)	/* for invalid index */
		return;

	while(beg<end)
	{
		str[beg] ^= str[end];
		str[end] = str[beg]^str[end];
		str[beg] = str[end]^str[beg];
		beg++;
		end--;
	}
	return;
}
