/*
 * main.c
 *
 *  Created on: 22 Feb 2017
 *      Author: Conor Beenham
 *		Student #: 16350851
 */

#include <stdio.h>

#include  "linker.h"

int main(void)
{
	setvbuf(stdout, NULL, _IOLBF, 0);
	get_Players();

	return 0;
}

