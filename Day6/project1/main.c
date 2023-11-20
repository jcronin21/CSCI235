// main.c
// gcc main.c helper.c
// This compiles both main.c and helper.c and links them in a.out
#include <stdio.h>

// We need to declare double_it() because it is in helper.c, not here
int double_it(int);

int main()
{
   int x = 100;
   printf("x is %d\n", x);
   x = double_it(x);
   printf("x is %d\n", x);
}
