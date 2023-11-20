// main.c
#include <stdio.h>
#include "helper.h"		// declares print_size
#include "types.h"		// declares enum size

int main()
{
	enum size tshirt = MEDIUM;
	print_size(tshirt);
#ifdef DEBUG
	printf("This is a debugging statement\n");
#endif

}
