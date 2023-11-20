#include <stdio.h>

int main() {
    int vals[5];
    printf("Enter five digits, one at a time:\n");

    for (int i = 0; i < 5; i++) {
        char c;
        do {
            c = getchar();
        } while (c == '\n');
        if (c >= '1' && c <= '9') {
            vals[i] = c - '0';
        } else {
            vals[i] = 0;
            while (c != '\n' && c != EOF) {
                c = getchar();
            }
        }
    }
    printf("vals contains:\n");
    for (int i = 0; i < 5; i++) {
        printf("vals[%d]=%d, square=%d\n", i, vals[i], vals[i] * vals[i]);
    }

    return 0;
}





