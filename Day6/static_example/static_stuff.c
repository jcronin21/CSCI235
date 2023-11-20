#include <stdio.h>
#include "static_stuff.h"

static int global_var = 456;

void this_function_remembers()
{
	static int i_remember = 0;
	int i_forget = 0;

    i_remember++;
	i_forget++;
    printf("The static number I am remembering is %d\n", i_remember);
	printf("The non-static number I recreate every time is %d\n", i_forget);
	this_function_isnt_visible();
}

static void this_function_isnt_visible()
{
	// This function can't be called outside of static_stuff.c
	printf("   I am a helper function. Please ignore me.\n");
}

void static_global()
{
	printf("   In static_global(), where global_var = %d\n", global_var);
	global_var++;	
	printf("   Increasing global_var to %d\n", global_var);
}
