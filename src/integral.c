#include <stdio.h>

#include <math.h>

#include "funcs.h"

/* Compute the integral approximation using the midpoint rectangle rule. */
static double rectangle_sum(afunc *f, double a, double b, int n)
{
    double width = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        double x = a + (i + 0.5) * width;
        sum += f(x) * width;
    }

    return sum;
}

double integral(afunc *f, double a, double b, double eps)
{
    int n = 10;

    double prev = rectangle_sum(f, a, b, n);

    while (1) {
        n *= 2;

        double cur = rectangle_sum(f, a, b, n);

        if (fabs(cur - prev) / 3.0 < eps) {
            return cur;
        }

        prev = cur;
    }
}


