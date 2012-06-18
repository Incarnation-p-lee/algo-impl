/*
*
* FILENAME:		bitmap_sort.c/bitmap_sort.h
* CREATED AT:		2012/Apr/27
* DECRITION:		implement the bitmap sort algorithm
* 
* MODULE:		pro-pearl
* PLATFORM:		ubuntu-12.04/gcc-4.6.3
* AUTHOR:		incarnation-lee
* 
* ----------------------REVISION HISTROY------------------------
* No.	Date	Revised by	Function	Descrition
* 1	12/5/4	incar-lee	bitmap		replace tab by \t	
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "externals.h"
#include "typedefs.h"
#include "bitmap_sort.h"



void bitmap(void)
{
	int res[] = {2,89,26,12,1,13,7,65,76,45,32,9,10,41,132,};
	char bitmaps[20];
	int i = 0,seg = 0,eff = 0;
	unsigned char local = 0x01;
	
	/* ergodic the source data for map the element on bitmaps, 20*8 width */
	memset(bitmaps,0,sizeof(bitmaps));	
	for(i=0;i<sizeof(res)/sizeof(int);i++)
	{
		fprintf(stdout,"%d ",res[i]);
		if(__builtin_expect(!res[i],0))
			continue;
		else
		{
			seg = res[i]>>3;			/* index in bitmap, like segment addr */
			eff = res[i]%8;				/* bits in index, like effective addr */
			bitmaps[seg] |= local<<eff;
		}
	}
	
	fprintf(stdout,"\n");

	/* display the result by bitmaps */
	for(i=0;i<sizeof(bitmaps)/sizeof(char);i++)
	{
		seg = i;
		eff = 0;
		while(eff<8)
		{
			if(__builtin_expect(!!(bitmaps[i]>>eff&local),1))
				fprintf(stdout,"%d ",(seg<<3)+eff);
			eff++;	
		}	
	}

	fprintf(stdout,"\n");
	return;
}
