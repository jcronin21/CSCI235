#include <stdio.h>
int main() {
    char inputchar;
    int count = 0;

    printf("Enter characters, one at a time,\n");
    printf("use ctrl-d to quit:\n");
    while ((inputchar = getchar()) != EOF) {
        if (inputchar == 'X') {
            count++;
        }
}

    printf("You entered X %d times\n", count);

    return 0;
}
