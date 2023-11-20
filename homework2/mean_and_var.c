#include <stdio.h>


double mean(double* values, unsigned size){
   double sum = 0.0;
   for (unsigned = 0; i < size;  i++){
     sum += values[i];

    }
  return sum/size;

}

double var(double* values, unsigned size){
   double m = mean(values, size);
   double variance = 0.0;
 for(unsigned = 0; i < size; i++){
    double differ =  values[i] - m;
    variance += differ * differ;
   }
 return variance/(size-1);


}
