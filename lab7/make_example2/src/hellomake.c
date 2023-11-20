#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc!=2) {
    printf("pass an int as an argument!\n");
  }
  // call a function in another file
  myPrintHelloMake(atoi(argv[1]));

  return(0);
}

