#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "funcs.h"

/* Value of pi used as the right endpoint in the sin(x) test. */
#define PI 3.1415926535

/* Maximum allowed absolute error in tests. */
#define EPS 1e-5

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

static double constant_5(double x)
{
    return 5.0;
}

static double line(double x)
{
    return x;
}

static double square(double x)
{
    return x * x;
}

static double cube(double x)
{
    return x * x * x;
}

int main(void)
{
    check("constant 5", integral(constant_5, 0.0, 2.0, 1e-7), 10.0);
    check("line", integral(line, 0.0, 4.0, 1e-7), 8.0);
    check("square", integral(square, 0.0, 3.0, 1e-7), 9.0);
    check("cube", integral(cube, 0.0, 2.0, 1e-7), 4.0);
    check("sin", integral(sin, 0.0, PI, 1e-7), 2.0);

    return 0;
}