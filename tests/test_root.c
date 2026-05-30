#include <assert.h>
#include <math.h>

#include "funcs.h"

#define EPS 1e-6

static void check(double actual, double expected)
{
    assert(fabs(actual - expected) < EPS);
}

static double line(double x) { return x; }
static double minus_line(double x) { return -x; }
static double square(double x) { return x * x; }

static double const_0(double x)
{
    (void)x;
    return 0.0;
}

static double const_2(double x)
{
    (void)x;
    return 2.0;
}

static double const_4(double x)
{
    (void)x;
    return 4.0;
}

int main(void)
{
    /* обычный случай */
    check(root(line, const_4, 3.0, 5.0, 1e-7), 4.0);

    /* иррациональный корень */
    check(root(square, const_2, 1.0, 2.0, 1e-7), sqrt(2.0));

    /* корень в нуле */
    check(root(line, minus_line, -1.0, 1.0, 1e-7), 0.0);

    /* корень совпадает с левой границей */
    check(root(line, const_0, 0.0, 10.0, 1e-7), 0.0);

    /* корень совпадает с правой границей */
    check(root(line, const_4, 0.0, 4.0, 1e-7), 4.0);

    /* очень маленький отрезок */
    check(root(line, const_4, 3.999999, 4.000001, 1e-12), 4.0);

    return 0;
}