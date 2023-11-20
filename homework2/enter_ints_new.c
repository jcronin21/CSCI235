#include <stdio.h>
#include <stdlib.h>

int getint(){
   int a, b, c;

   while ((a = getchar()) == ' ' || a == '\t');
   if(a == '-'){
     b = -1;
     a = getchar();
  }else{
    b = 1;
  }
   for (c = 0; a>= '0' && a <= '9'; a = getchar()){
    c = 10 * c + (a - '0');
  }
   return b * c;
}

int main (){
  int storage = 2; 
   int *array = (int *)malloc(storage * sizeof(int));
      if(array == NULL) {

        printf("mem alloc error\n");
        return 1;
      }
    int n = 0;//num of ints

    printf("enter ints one per line (ctrl-d to end)\n");

   while(1){
   int num = getint();
   if(num !=EOF){
   if(n == storage){
     storage *= 2;
      int *array = (int *)malloc(storage * sizeof(int));
       if (array == NULL){
        printf("mem alloc error\n");
         return 1;
        }
         for (int i = 0; i < n; i++){
          tempArray[i] = array[i];
      }
       free(array);
     array = tempArray;
      }    
     array[n] = num;
     n++;
   }else {
    break;
  }
}
 printf("capacity=%d\n",storage);
 printf("n=%d\n",n);
  for(int i = 0; i < n; i++){
    printf("array[%d]=%d\n", i, array[i]);
} 
free(array);

return 0;
}
 /*  int counter;

   printf("> How many numbers will you enter?\n");
   counter = getint();

   if (counter <= 0) {
    printf("that is invalid, please type a positive number.\n");
    return 1;
   }
  }
   int *array = (int *)malloc(counter * sizeof(int));
   if(array == NULL) {
     printf("mem alloc error\n");
     return 1;
   }

   printf("> array[0]=%d\n", getint());

   for(int i = 1; i < counter; i++){
     array[i] = getint();
     printf("> array[%d]=%d\n", i, array[i]);
    }

   printf("done with enter_ints.c...\n");
   free(array);
   return 0;
}*/


