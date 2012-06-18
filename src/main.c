/*
*
* FILENAME:		main.c/bitmap_sort.h,caches.h
* CREATED AT:		2012/Apr/27
* DECRITION:		main file for call kinds algorithm
* 
* MODULE:		interface for algorithm and pro-pearl
* PLATFORM:		ubuntu-12.04/gcc-4.6.3
* AUTHOR:		incarnation-lee
* 
* ----------------------REVISION HISTROY------------------------
* No.	Date	Revised by	Function	Descrition
* 1	12/4/27	incar-lee	main		add caches.c for the effect of cache
* 2	12/5/2	incar-lee	main		add bitmap_sort.c for bitmap sort algorithm
* 3	12/6/12	incar-lee	main		add lc_subseq.c for longest common subsequence
* 4	12/6/14	incar-lee	main		add longest common substring
*/

/* C Standard */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

/* linux related */
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

/* usr defined */
#include "externals.h"
#include "typedefs.h"


int main()
{
	/* cache affect */
	/*
	result = cache_affect();	
	if(__builtin_expect(!result,1));
	else
		goto fail;
	*/
		

	bitmap();				/* bit mapping sort */
	lcseq();				/* longest commmon subsequence */
	lcstr();				/* longest commmon substring */
	sub_m_ay();				/* the max sum sub array in O(n) */

	return 0;
}
