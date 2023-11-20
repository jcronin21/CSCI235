
#include <stdio.h>

int above(int nums[], int size, int n) {
      int count = 0;
      for (int i = 0; i < size; i++) {
          if (nums[i] > n){
              count++;
            }
         }
        return count;
}
int main() {
   int nums01[] = {10, 20, 30, 40, 50};
   int size01 = sizeof(nums01) / sizeof(nums01[0]);
   int n1 = 25;

  int nums02[] = {5, 10, 15, 20, 25};
  int size02 = sizeof(nums02) / sizeof(nums02[0]);
  int n2 = 12;

  int nums03[] = {2, 4, 6, 8, 10};
  int size03 = sizeof(nums03) / sizeof(nums03[0]);
  int n3 = 7; 
  printf("the values above %d in numexamp1: %d\n", n1, above(nums01, size01, n1));
  printf("the values above %d in numexamp2: %d\n", n2, above(nums02, size02, n2));
  printf("the values above %d in numexamp3: %d\n", n3, above(nums03, size03, n3));
 return 0;

}
