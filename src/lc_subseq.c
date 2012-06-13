/*
* FILENAME:		lc_subseq.c/lc_subseq.h
* CREATED AT:		2012/Jun/12
* DECRITION:		Longest Common Subsequence
* 
* MODULE:		pro-pearl
* PLATFORM:		ubuntu-12.04/gcc-4.6.3
* AUTHOR:		incarnation-lee
* 
* ----------------------REVISION HISTROY------------------------
* No.	Date	Revised by	Function	Descrition
* 1	12/6/12	incar-lee	
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
#include "lc_subseq.h"


const char cp_a[] = "BDCABA";	
const char cp_b[] = "ABCBDAB";
static unsigned short lcs_len[sizeof(cp_a)/sizeof(char)][sizeof(cp_b)/sizeof(char)];
/*
* record the direction,
* 1 2
* 3 loc
*/
static unsigned short direct[sizeof(cp_a)/sizeof(char)][sizeof(cp_b)/sizeof(char)];


/*
* longest common subsequence 
*/
void lcseq()
{
	int i,j;

	fprintf(stdout,"%s & %s: ",cp_a,cp_b);
	/* init the nested table of lcs */
	for(i=1;i<sizeof(cp_a)/sizeof(char);i++)
	{
		for(j=1;j<sizeof(cp_b)/sizeof(char);j++)
		{
			if(cp_a[i-1]==cp_b[j-1])
			{
				lcs_len[i][j] = 1 + lcs_len[i-1][j-1];	
				direct[i][j] = 1;
			}
			else if(lcs_len[i][j-1]>lcs_len[i-1][j])
			{
				lcs_len[i][j] = lcs_len[i][j-1];
				direct[i][j] = 3;
			}
			else
			{
				lcs_len[i][j] = lcs_len[i-1][j];
				direct[i][j] = 2;
			}
		}
	}	
	
	/* display the result */
	direct_path(i-1,j-1);
	
	fprintf(stdout,"\n");
	return;
}

/*
* direct the path
*/
void direct_path(int i,int j)
{
	int n,m;
	
	if(__builtin_expect(!!(0==i || 0==j),0))		/* until the first element */
		return;
	n = PREX(i,direct[i][j]);
	m = PREY(j,direct[i][j]);
	if(lcs_len[i][j]>lcs_len[n][m])
	{
		fprintf(stdout,"%c<",cp_a[i-1]);
	}
	direct_path(n,m);
	return;
}
