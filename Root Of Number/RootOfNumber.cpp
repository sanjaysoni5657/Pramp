#include <iostream>
#include <math.h>

using namespace std;

double root(double x, unsigned int n) 
{
  // your code goes here
   double start = 0, end = x;
   double out = 0;

   while(start + 0.001 < end) {
      double mid = start + (end - start) / 2.0;
      
      if(x == pow(mid,n)) {
          return mid;
      } else if (x < pow(mid,n)) {
          end = mid;
      } else {
          start = mid;
      }
      out = mid;
   }

  return out;
}

int main() {
  return 0;
}











