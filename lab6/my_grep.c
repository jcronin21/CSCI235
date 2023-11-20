#include <stdio.h>
#include <stdlib.h>
//main(char *string1,FILE *file ){
  //if(char != str){
  // fprintf(stderr,"error",string1); 
 // }


//}

int main(int arg1, char *argv[]) {
if (arg1 != 3) {
        fprintf(stderr, "error: %s\n", argv[0]);
        exit(1);
    }
 char *string_to_find = argv[1];
    char *filename = argv[2];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    char ch;
    int string_index = 0;

    while ((ch = getc(file)) != EOF) {
        if (ch == string_to_find[string_index]) {
            string_index++;
            if (string_to_find[string_index] == '\0') {
                printf("%s", string_to_find); 
                string_index = 0; // Reset 
            }
        } else {
            string_index = 0; // Reset
        }
    }

    fclose(file);
    return 0;
}
