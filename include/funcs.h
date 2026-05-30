#ifndef FUNCS_H
#define FUNCS_H

typedef double afunc(double);

double f1(double x);
double f2(double x);
double f3(double x);

double root(
    afunc *f,
    afunc *g,
    double a,
    double b,
    double eps
);

double integral(
    afunc *f,
    double a,
    double b,
    double eps
);

#endif