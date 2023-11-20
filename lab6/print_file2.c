#include <stdio.h>

main(int numArgu,char *point2argu[] ){
  if(numArgu != 2){
 fprintf(stderr,"error\n",point2argu[0]);
 exit(1);
}
  FILE *file;
  char ch;

  file = fopen(pointer2argu[1], "r");


   if (file == NULL){
   fprintf(stderr,"error...ahhhh...%s\n",point2argu[1]);
   exit(1);

    }
    while((ch = getch(file)!= EOF){
     printf("%c",ch);
  }
  fclose(file);//always close the file!!!
  return 0;
}

