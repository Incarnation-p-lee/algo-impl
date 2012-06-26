/*
* FILENAME:		n_step.c/n_step.h
* CREATED AT:		2012/Jun/26
* DECRITION:		
* 
* MODULE:		pro-pearl
* PLATFORM:		ubuntu-12.04/gcc-4.6.3
* AUTHOR:		incarnation-lee
* 
* ----------------------REVISION HISTROY------------------------
* No.	Date	Revised by	Function	Descrition
* 1	12/6/26	incar-lee			created
*
*/


#ifndef N_STEP_H
#define N_STEP_H

#include <sys/types.h>
#include <stddef.h>
#include <fcntl.h>

#include "typedefs.h"


void nstep_way(void);
unsigned int n_step(int N)__attribute__((pure));


#endif
