#include <stdio.h>
#include "point.h"


 int main(){
   struct point {
    double x;
    double y;
   };

   struct point p1;
   Point p2 = {3.1, 4.2};
  p1.x = -2;
  p1.y = -1001;


  printf("p1 is (%f, %f)\n",p1.x,p1.y);
  printf("p2 is (%f, %f)\n",p2.x, p2.y);
  
   struct triangle {
   double side1;
   double side2; 
   double side3;
   };
 
   typedef struct triangle Triangle;
   Triangle t1 = {3, ,4, 5};
