#include <stdio.h>
#include "not_static_stuff.h"

extern int global_var;

void not_static_global()
{
	printf("   In not_static_global() where global_var = %d\n", global_var);
	global_var++;
	printf("   Increasing global_var to %d\n", global_var);
}
