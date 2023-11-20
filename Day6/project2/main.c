// main.c
// compile with gcc main.c helper.c helper2.c

#include <stdio.h>
#include "helper.h"
#include "helper2.h"

#include "empty.h"
#define HELLO 5
#define MSG "Hello, World"

// put empty.h into some_dir
// to compile this, you would need
// gcc main.c helper.c helper2.c -Isome_dir

int main()
{
	int x = 4;
	int y = double_it(x);
	printf("y = %d\n", y);
	
	int z = quadruple_it(x);
	printf("z = %d\n", z);

	printf("I would like to say %s\n", MSG);
}
