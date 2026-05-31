#include <assert.h>
#include <math.h>

#include "funcs.h"

#define EPS 1e-5

static void check(double actual, double expected)
{
    assert(fabs(actual - expected) < EPS);
}

/* Тестовые функции НЕ из варианта */
static double constant_5(double x)
{
    (void)x;
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

int main(void)
{
    check(integral(constant_5, 0.0, 2.0, 1e-7), 10.0);
    check(integral(line, 0.0, 4.0, 1e-7), 8.0);
    check(integral(square, 0.0, 3.0, 1e-7), 9.0);

    return 0;
}