#include <stdio.h>

// Global variable
// Extern to anything outside of this file
int num_init = 123;

// Global variable
// Extern to anything outside of this file
int num_uninit;	// not initialized, so initialized to zero

void fun1()
{
	num_init++;
	printf("num_init is now %d\n", num_init);
}

void fun2()
{
	extern int num_not_here;
	num_not_here++;
	printf("num_not_here is now %d\n", num_not_here);
}

void fun3();
void fun4();

int main()		// I can only have one main()
{
	fun1();
	fun2();
	fun3();		// not defined in this file
	fun4();		// not defined in this file
}
