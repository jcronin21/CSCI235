// helper.c
#include "types.h"		// We need this for enum size
#include <stdio.h>

void print_size(enum size sz) 
{
	printf("size is stored as %d\n", sz);
}
