/*
* FILENAME:		nosymbol_add.c/nosymbol_add.h
* CREATED AT:		2012/Jun/19
* DECRITION:		implement add without any predefine symbol
* 
* MODULE:		pro-pearl
* PLATFORM:		ubuntu-12.04/gcc-4.6.3
* AUTHOR:		incarnation-lee
* 
* ----------------------REVISION HISTROY------------------------
* No.	Date	Revised by	Function	Descrition
  1	12/6/19	incar-lee			created
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
#include "nosymbol_add.h"



void ns_add_ver(void)
{
	int result,op1,op2;

	op1 = 21;
	op2 = 34;
	result = no_symbol_add(op1,op2);
	fprintf(stdout,"%d + %d = %d\n",op1,op2,result);
	op1 = 7;
	op2 = 721;
	result = no_symbol_add(op1,op2);
	fprintf(stdout,"%d + %d = %d\n",op1,op2,result);
	op1 = 65535;
	op2 = 4095;
	result = no_symbol_add(op1,op2);
	fprintf(stdout,"%d + %d = %d\n",op1,op2,result);
	return;
}


/*
* implement add without any predefine symbol
*/
int no_symbol_add(int op1,int op2)
{
	int xor = 0;
	int and = 0;
	
	if(0==(op2&0xFFFFFFFF))			/* unsigned by default */
		return op1;
	
	xor = op1 ^ op2;
	and = op1 & op2;	
	return no_symbol_add(xor,and<<1);
}
