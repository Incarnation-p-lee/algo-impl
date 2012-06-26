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
* 1	12/6/25	incar-lee	lsym+sstr	created
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
#include "lsym_substr.h"


static const char *lss = "defagoogedeaaedera";
/*
* find the longest symmetry substr of specified string
*/
void lsym_sstr(void)
{
	ptrdiff_t len = 0;
	size_t max = 0;
	char *beg,*cp,*end,*ms;

	fprintf(stdout,"%s:",lss);
	cp = (char*)lss;
	while('\0'!=*(cp+1))			/* when cp points the last element, exit the while */
	{
		if(*cp==*(cp+1))
		{
			beg = cp;
			end = cp + 1;
			while('\0'!=*end && beg+1!=lss)	/* overflow protected */
			{	
				if(*beg==*end)
				{
					len = end + 1 - beg;
					end++;
					beg--;
				}
				else
					break;
			}
			if(len>max)
			{
				max = (size_t)len;	
				ms = beg + 1;
			}
		}
		cp++;
	}
	
	cp = ms;
	while(ms!=cp-(ptrdiff_t)len)
		fprintf(stdout,"%c",*cp++);
	fprintf(stdout,"[%d]\n",max);
	return;
}
