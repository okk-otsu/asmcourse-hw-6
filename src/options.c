#include <math.h>
#include <stdio.h>

#include "funcs.h"
#include "options.h"

static afunc *get_function(int number)
{
    switch (number) {
    case 1:
        return f1;
    case 2:
        return f2;
    case 3:
        return f3;
    default:
        return NULL;
    }
}

void print_help(const char *program)
{
    printf("Usage: %s [OPTION]\n", program);
    printf("\n");
    printf("Options:\n");
    printf("  %-20s %s\n", "-h, --help", "print this help message");
    printf("  %-20s %s\n", "-r, --root", "print intersection points");
    printf("  %-20s %s\n", "-i, --iterations", "print iteration counts");
    printf("  %-20s %s\n", "-R, --test-root", "test root function");
    printf("  %-20s %s\n", "-I, --test-integral", "test integral function");
}

int test_root_option(const char *arg)
{
    int f_number, g_number;
    double a, b, eps, expected;

    if (sscanf(arg, "%d:%d:%lf:%lf:%lf:%lf",
               &f_number, &g_number, &a, &b, &eps, &expected) != 6) {
        fprintf(stderr, "Invalid --test-root argument\n");
        return 1;
    }

    afunc *f = get_function(f_number);
    afunc *g = get_function(g_number);

    if (f == NULL || g == NULL) {
        fprintf(stderr, "Invalid function number\n");
        return 1;
    }

    double actual = root(f, g, a, b, eps);
    double abs_error = fabs(actual - expected);
    double rel_error = abs_error / fabs(expected);

    printf("%.10f %.10e %.10e\n",
        actual,
        abs_error,
        rel_error);

    return 0;
}

int test_integral_option(const char *arg)
{
    int f_number;
    double a, b, eps, expected;

    if (sscanf(arg, "%d:%lf:%lf:%lf:%lf",
               &f_number, &a, &b, &eps, &expected) != 5) {
        fprintf(stderr, "Invalid --test-integral argument\n");
        return 1;
    }

    afunc *f = get_function(f_number);

    if (f == NULL) {
        fprintf(stderr, "Invalid function number\n");
        return 1;
    }

    double actual = integral(f, a, b, eps);
    double abs_error = fabs(actual - expected);
    double rel_error = abs_error / fabs(expected);

    printf("%.10f %.10e %.10e\n",
        actual,
        abs_error,
        rel_error);

    return 0;
}