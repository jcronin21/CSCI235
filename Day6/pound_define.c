// pound_define.c

#include <stdio.h>

#define X		// for #define, if it is not initialized, it is 0
				// This is DIFFERENT from uninitialized variables
#define Y 1

int main()
{
	// This wouldn't work with X
	if (Y)
		printf("Y is 1\n");
	else
		printf("Y is not 1\n");

#ifdef X
	printf("X is defined\n");
#endif

#ifndef X
	printf("X is not defined\n");
#endif

#ifdef Y
	printf("Y is defined\n");
#endif

#ifndef Y
	printf("Y is not defined\n");
#endif
}
