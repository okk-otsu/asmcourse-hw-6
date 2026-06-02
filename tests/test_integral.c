#include <assert.h>
#include <math.h>

#include "funcs.h"

/* Maximum allowed absolute error in tests. */
#define EPS 1e-6

/* Test function: f(x) = 0. */
static double zero(double x)
{
    (void)x;
    return 0.0;
}

/* Test function: f(x) = 1. */
static double one(double x)
{
    (void)x;
    return 1.0;
}

/* Test function: f(x) = x. */
static double line(double x)
{
    return x;
}

/* Test function: f(x) = x^2. */
static double square(double x)
{
    return x * x;
}

/* Test function: f(x) = x^3. */
static double cube(double x)
{
    return x * x * x;
}

int main(void)
{
    assert(fabs(integral(zero, 0.0, 1.0, EPS) - 0.0) < EPS);
    assert(fabs(integral(one, 0.0, 2.0, EPS) - 2.0) < EPS);
    assert(fabs(integral(line, 0.0, 1.0, EPS) - 0.5) < EPS);
    assert(fabs(integral(square, 0.0, 1.0, EPS) - 1.0 / 3.0) < EPS);
    assert(fabs(integral(cube, 0.0, 1.0, EPS) - 0.25) < EPS);

    return 0;
}