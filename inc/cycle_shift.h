/*
* FILENAME:		cycle_shift.c/cycle_shift.h
* CREATED AT:		2012/Jun/27
* DECRITION:		
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

#ifndef CYCLE_SHIFT_H
#define CYCLE_SHIFT_H

#include <stddef.h>
#include <sys/types.h>

#include "typedefs.h"

void right_cs(void)__attribute__((__pure__));
void right_cshift(char*,int)__attribute__((__nonnull__(1)));
void reverse(char*,int,int)__attribute__((__nonnull__(1)));

#endif
