/*
* FILENAME:		lc_subsstr.c/lc_substr.h
* CREATED AT:		2012/Jun/14
* DECRITION:		Longest Common Subsequence
* 
* MODULE:		pro-pearl
* PLATFORM:		ubuntu-12.04/gcc-4.6.3
* AUTHOR:		incarnation-lee
* 
* ----------------------REVISION HISTROY------------------------
* No.	Date	Revised by	Function	Descrition
* 1	12/6/14	incar-lee	
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
#include "lc_substr.h"


static const char cp_a[] = "dertascadcbbcad";
static const char cp_b[] = "eftaderbcadcberseadc";
static unsigned short lcstr_matrix[sizeof(cp_a)/sizeof(char)][sizeof(cp_b)/sizeof(char)];


/*
* longest common string
*/
void lcstr()
{
	int i,j;					
	unsigned short max_len = 0;
	unsigned int x_lo,y_lo;
	
	for(i=1;i<sizeof(cp_a)/sizeof(char);i++)
	{
		for(j=1;j<sizeof(cp_b)/sizeof(char);j++)
		{
			if(cp_a[i]==cp_b[j])
				lcstr_matrix[i][j] = lcstr_matrix[i-1][j-1] + 1;	/* (i,j)=(i-1,j-1)+1 */	
			else
				lcstr_matrix[i][j] = 0;	
		}	
	}
	
	for(i=1;i<sizeof(cp_a)/sizeof(char);i++)			/* find longest location */
	{
		for(j=1;j<sizeof(cp_b)/sizeof(char);j++)
		{
			if(lcstr_matrix[i][j]>max_len)
			{
				max_len = lcstr_matrix[i][j];
				x_lo = i;				/* path need max end location */
				y_lo = j;
			}
		}	
	}
	
	fprintf(stdout,"%s & %s :%d: ",cp_a,cp_b,max_len);	
	for(i=1;i<=x_lo;i++)						/* anyway, use lo_y is the same */
	{
		fprintf(stdout,"%c<",cp_a[x_lo+1-i]);
		if(0==lcstr_matrix[x_lo-i][y_lo-i])
			break;
	}
	fprintf(stdout,"\n");
	return;
}
