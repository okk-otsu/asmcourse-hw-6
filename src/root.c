#include "funcs.h"

double root(
    afunc *f,
    afunc *g,
    double a,
    double b,
    double eps)
{
    double fa = f(a) - g(a);

    while (b - a > eps) {
        double c = (a + b) / 2.0;
        double fc = f(c) - g(c);

        if (fa * fc <= 0.0) {
            b = c;
        } else {
            a = c;
            fa = fc;
        }
    }

    return (a + b) / 2.0;
}

double root_iterations(
    afunc *f,
    afunc *g,
    double a,
    double b,
    double eps,
    int *iterations)
{
    double fa = f(a) - g(a);
    int count = 0;

    while (b - a > eps) {
        double c = (a + b) / 2.0;
        double fc = f(c) - g(c);

        ++count;

        if (fa * fc <= 0.0) {
            b = c;
        } else {
            a = c;
            fa = fc;
        }
    }

    *iterations = count;

    return (a + b) / 2.0;
}