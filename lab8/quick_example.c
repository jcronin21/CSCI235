#include <stdio.h>

void danger() {
  printf("DANGER!\n");
}

void echo() {
  char buffer[10];
  printf("enter some text:\n");
  scanf("%s",buffer);//reads until whitespace found
  printf("You entered: %s\n",buffer);
}

int main() {
  echo();
}
