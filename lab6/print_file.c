#include <stdio.h>

main(){
  FILE *file;
  char ch;

//fp = fopen(name, mode);  the mode would be 'r' 'a' or 'w' aka
//read, append, write
  file = fopen("lab6.txt", "r");


   if (file == NULL){
    printf("error...ahhhh...\n");
   return 1;

  // while(ch = getch(file != EOF)){//while ch equals getch file DOES NOT = EOF
    // printf("%c",ch);
    }
    while(ch = getch(file != EOF)){//while ch equals getch file DOES NOT = EOF
     printf("%c",ch);
  }
  fclose(file);//always close the file!!!
  return 0;
}

