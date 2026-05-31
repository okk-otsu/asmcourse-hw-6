#include <stdio.h>

#include "funcs.h"

#define EPS1 1e-6
#define EPS2 1e-6

#define X13_A 0.5
#define X13_B 1.0

#define X23_A 3.0
#define X23_B 3.5

#define X12_A 3.5
#define X12_B 4.0

static double f1_minus_f3(double x)
{
   return f1(x) - f3(x);
}

static double f1_minus_f2(double x)
{
   return f1(x) - f2(x);
}

int main(void)
{
   double x13 = root(f1, f3, X13_A, X13_B, EPS1);
   double x23 = root(f2, f3, X23_A, X23_B, EPS1);
   double x12 = root(f1, f2, X12_A, X12_B, EPS1);

   double area = integral(f1_minus_f3, x13, x23, EPS2) 
               + integral(f1_minus_f2, x23, x12, EPS2);

   printf("%.6f\n", area);

   return 0;
}