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
* 1	12/6/12	incar-lee			created
*
*/

#ifndef LCS_H
#define LCS_H

#include <stddef.h>
#include <fcntl.h>

#include "typedefs.h"


#define PREX(x,d) (d)==1?((x)-1):((d)==2?(x)-1:((d)==3?(x):0))
#define PREY(y,d) (d)==1?((y)-1):((d)==2?y:((d)==3?(y-1):0))


void lcseq(void);			/* longest common subsequence */
void direct_path(int,int);		/* detect the lcs path */

#endif
