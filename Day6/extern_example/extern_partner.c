#include <stdio.h>

// Global variable
// Used in extern_example.c
int num_not_here = 456;

void fun3()
{
	extern int num_uninit;	// this is defined in extern_example
	num_uninit++;
	printf("num_uninit is now %d\n", num_uninit); 
}

void fun4()
{
	int num_uninit;			// BUG: this will be a new variable
							// ALSO: it is initialized; it could be ANYTHING
	num_uninit++;
	printf("num_uninit is now %d\n", num_uninit); 
}

// remember -- no main here
