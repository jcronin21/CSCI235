#include <stdio.h>
int is_palindrome(char str[]) {
    int size = 0;
    while (str[size] != '\0') {
     size++;
  }
for (int i = 0; i<= size /2; i++) {
    if (str[i] != str[size - i -1]){
        return 0;
  }
}
return 1;
}
int main() {
 char test1[] = "racecar";
 char test2[] = "abba";
 char test3[] = "jazz";
 char test4[] = "testing";
 is_palindrome(test1);
 is_palindrome(test2);
 is_palindrome(test3);
 is_palindrome(test4);
}
