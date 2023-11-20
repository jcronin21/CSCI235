#include <stdio.h>
#include "longest_streak.h"

int main(){
    int arr1 = {1, 2, 3, 2, 4, 4, 4, 2, 1, 1};
    unsigned length = sizeof(arr1) / sizeof(arr1[0]);

   printf("Longest streal: %u\n", longest_streak(arr1, length));
     


    return 0;
}

