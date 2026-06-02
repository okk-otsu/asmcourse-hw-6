#ifndef FUNCS_H
#define FUNCS_H

/* Function of one double argument returning double. */
typedef double afunc(double);

/* Compute f1(x) = 0.6 * x + 3. */
double f1(double x);

/* Compute f2(x) = (x - 2)^3 - 1. */
double f2(double x);

/* Compute f3(x) = 3 / x. */
double f3(double x);

/* Find intersection of two functions and compute iteration count. */
double root_iterations(
    afunc *f,
    afunc *g,
    double a,
    double b,
    double eps,
    int *iterations);

/* Find intersection of two functions. */
double root(
    afunc *f,
    afunc *g,
    double a,
    double b,
    double eps);

/* Compute definite integral of a function. */
double integral(
    afunc *f,
    double a,
    double b,
    double eps);

#endif