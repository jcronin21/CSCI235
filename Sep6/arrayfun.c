#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void awful_print(int arr[], int size)
{
    for(int i=0; i<size; i++)
       printf("arr[%d] = %d\n", i , arr[i]);
}
void plus_one(int*arr, int size)
{
  for (int i =0; i<size; i++)
    arr[i] = arr[i] + 1;
}
void printarray(int arr[], int size)
{
   printf("[");
   for (int i = 0; i<size; i++)
   {
       printf("%d", arr[i]);
         if (i != size -1)
           printf(" ,");
   }
printf("]\n");
}

char* arrtostr(int arr[], int size)
{
    char* str =(char*) malloc(255  * sizeof(char)); 
}

int main() {
  //intialized to 10 values
  int arr1[] = {3, 1, 4, 5, 7, 2, 3, 8, 3, -1};
  
  //not intalized 
  int arr2[5];
  for (int i = 0; i < 5; i++)
     arr2[i] = (i +1) * (i + 2);

  printf("arr1 is %p\n", arr1);
  plus_one(arr1, 10);
  plus_one(arr1, 5);

 awful_print(arr1, 10);

 char *str = arrtostr(arr1, 10);
 printf("arr1 is %s\n", str):
}
