#include <stdio.h>
#include <stdlib.h>
#include "mean_and_var.h"

double getdouble(){
 // double a, b, c;
  double result = 0.0;
  double frac = 0.1;
  int isDec = 0;
  int isNegative = 0;

int temp;

  temp = getchar();
  if(temp == '='){
   isNegative = 1;
  temp = getchar();
}

while (temp >= '0' && temp <= '9'){
   result = result * 10.0 + (temp - '0');
  temp = getchar();
}


if (temp =='.'){

  hasDec =1;
  temp = getchar();
}

while (temp >= '0' && temp <= '9'){
 result = result + fraction *(temp - '0');
 fraction *= 0.1;
 temp = getchar();
}

if(isNegative){
  result = -1 * result;

}

 return result;
}
int main (){
  int storage = 2; 
   double  *array = (double *)malloc(storage * sizeof(double));
      if(array == NULL) {

        printf("mem alloc error\n");
        return 1;
      }
    int n = 0;//num of doubles

    printf("enter doubles one per line (ctrl-d to end)\n");



while(1){
   double num = getint();
   if(num !=EOF){
   if(n == storage){
     storage *= 2;
      double *array = (double *)malloc(storage * sizeof(double));
       if (array == NULL){
        printf("mem alloc error\n");
         free(array);
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
