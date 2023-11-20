#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "getint.h"

int main() {
    Node *p = NULL;
    int value;

    printf("Enter positive integers (enter a negative integer to quit):\n");

    while (1) {
        int result = getint(&value); 
        if (result == EOF || value < 0) {
            break;
        }
        p = insert(p, value);
    }
//    print_list(p);
    printf("Enter a value to be deleted:\n");
    int deleteValue;
    int deleteResult = getint(&deleteValue);
    if (deleteResult != EOF) {
        p = delete_node(p, deleteValue);
    }

    printf("\n");
    print_list(p);


    p = free_list(p);

//    printf("\n");

    return 0;
}
