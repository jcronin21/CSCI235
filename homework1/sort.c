#include <stdio.h>
   void swapper(int *a, int *b) {
      int tempo;
      tempo = *a;
      *a = *b; 
      *b = tempo;
}

   void selection_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
         for (int j = i +1; j < size; j++) {
            if(arr[i] > arr[j]) {
             swapper(&arr[i], &arr[j]);
         }
      }
    }
}

/*  int main() {
    int size = 6;
    int arr[] = {5, 2, 4, 7, 1, 3};
    selection_sort(arr, size);


   printf("your array: ");
    for (int i =0; i <size; i++) {
     printf(" %d ", arr[i]);
   }
    return 0;
}
*/
int main() {
    int size = 6;
    int arr1[] = {5, 2, 4, 7, 1, 3};
    int arr2[] = {9, 6, 8, 2, 5, 1};
    printf("array 1: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("array 2: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    selection_sort(arr1, size);
    selection_sort(arr2, size);

    printf("Sorted array 1: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("Sorted array 2: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}
