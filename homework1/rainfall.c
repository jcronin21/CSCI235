#include <stdio.h>
#include <stdlib.h>


int main() {
    //printf("Enter daily rainfall totals, one per line, use 'T' for trace, use '-1' to quit:\n");

    double total_rainfall = 0.0;
    char ch;

    printf("Enter daily rainfall totals, one per line, use 'T' for trace, use '-1' to quit:\n");

    while (1) {
        char input[225];
        int i =0;

        while ((ch = getchar()) != '\n' && ch != EOF) {
          input[i++] =ch;
         }
         input[i] = '\0';
         if (input[0] == 'T' || atof(input) == 0.0) {
            total_rainfall += 0.0;
         } else if (atof(input) == -1.0) {
            break;
        } else {
            total_rainfall += atof(input);
      }
}
   printf("Total rainfall: %.2f\n", total_rainfall);

   return 0;
}



