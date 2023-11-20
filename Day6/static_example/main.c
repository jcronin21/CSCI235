#include <stdio.h>
#include "static_stuff.h"
#include "not_static_stuff.h"

// This is global, but static_stuff has its own static version
int global_var = 123;

int main()
{
	// We can call this_function_remembers()
	this_function_remembers();
	this_function_remembers();
	this_function_remembers();

	// We cannot call this_function_isnt_visible()
	//this_function_isnt_visible();

	// Call a function in not_static_stuff.c to change global_var
	printf("In main, where global_var = %d\n", global_var);
	static_global();
	static_global();
	printf("Back in main, where global_var = %d\n", global_var);
	not_static_global();
	not_static_global();
	printf("In main, where global_var = %d\n", global_var);
}
