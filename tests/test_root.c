#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"

/* Maximum allowed absolute error in tests. */
#define EPS 1e-6

/* Check that actual and expected values differ by less than EPS. */
static void check(const char *name, double actual, double expected)
{
    double error = fabs(actual - expected);

    if (error >= EPS) {
        printf("FAILED: %s\n", name);
        printf("actual   = %.10f\n", actual);
        printf("expected = %.10f\n", expected);
        printf("error    = %.10e\n", error);
        exit(1);
    }

    printf("PASSED: %s\n", name);
}

/* Test function: f(x) = x. */
static double line(double x) { return x; }

/* Test function: f(x) = -x. */
static double minus_line(double x) { return -x; }

/* Test function: f(x) = x^2. */
static double square(double x) { return x * x; }

/* Test function: f(x) = x^3. */
static double cube(double x) { return x * x * x; }

/* Test function: f(x) = sin(x). */
static double my_sin(double x) { return sin(x); }

/* Constant test function: f(x) = 0. */
static double const_0(double x)
{
    return 0.0;
}

/* Constant test function: f(x) = 2. */
static double const_2(double x)
{
    return 2.0;
}

/* Constant test function: f(x) = 4. */
static double const_4(double x)
{
    return 4.0;
}

/* Constant test function: f(x) = 5. */
static double const_5(double x)
{
    return 5.0;
}

int main(void)
{
    check("line = 4",
          root(line, const_4, 3.0, 5.0, 1e-7),
          4.0);

    check("x^2 = 2",
          root(square, const_2, 1.0, 2.0, 1e-7),
          sqrt(2.0));

    check("x = -x",
          root(line, minus_line, -1.0, 1.0, 1e-7),
          0.0);

    check("left border root",
          root(line, const_0, 0.0, 10.0, 1e-7),
          0.0);

    check("right border root",
          root(line, const_4, 0.0, 4.0, 1e-7),
          4.0);

    check("small segment",
          root(line, const_4, 3.999999, 4.000001, 1e-12),
          4.0);

    check("x^3 = 5",
          root(cube, const_5, 1.0, 2.0, 1e-7),
          cbrt(5.0));

    check("sin(x) = 0",
          root(my_sin, const_0, -1.0, 1.0, 1e-7),
          0.0);

    return 0;
}