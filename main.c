#include <stdio.h>
#include <getopt.h>
#include "funcs.h"
#include "options.h"

#define EPS1 1e-6
#define EPS2 1e-6

#define X13_A 0.5
#define X13_B 1.0

#define X23_A 3.0
#define X23_B 3.5

#define X12_A 3.5
#define X12_B 4.0

static double f1_minus_f3(double x)
{
   return f1(x) - f3(x);
}

static double f1_minus_f2(double x)
{
   return f1(x) - f2(x);
}


static void compute_roots(
    double *x13, double *x23, double *x12,
    int *i13, int *i23, int *i12)

{
    *x13 = root_iterations(f1, f3, X13_A, X13_B, EPS1, i13);
    *x23 = root_iterations(f2, f3, X23_A, X23_B, EPS1, i23);
    *x12 = root_iterations(f1, f2, X12_A, X12_B, EPS1, i12);

}

int main(int argc, char **argv)
{
    static const struct option long_options[] = {
        {"help",       no_argument, 0, 'h'},
        {"root",       no_argument, 0, 'r'},
        {"iterations", no_argument, 0, 'i'},
        {"test-root", required_argument, 0, 'R'},
        {"test-integral", required_argument, 0, 'I'},
        {0, 0, 0, 0}
    };

    int show_roots = 0;
    int show_iterations = 0;

    int opt;
    while ((opt = getopt_long(argc, argv, "hriR:I:", long_options, NULL)) != -1) {
        switch (opt) {
        case 'h':
            print_help(argv[0]);
            return 0;
        case 'r':
            show_roots = 1;
            break;
        case 'i':
            show_iterations = 1;
            break;
        case 'R':
            return test_root_option(optarg);
        case 'I':
            return test_integral_option(optarg);
        default:
            print_help(argv[0]);
            return 1;
        }
    }

    double x13, x23, x12;
    int i13, i23, i12;
    compute_roots(&x13, &x23, &x12, &i13, &i23, &i12);

    if (show_roots) {
        printf("x13 = %.10f\n", x13);
        printf("x23 = %.10f\n", x23);
        printf("x12 = %.10f\n", x12);
    }
    
    if (show_iterations) {
        printf("Intersection f1-f3: %d iterations\n", i13);
        printf("Intersection f2-f3: %d iterations\n", i23);
        printf("Intersection f1-f2: %d iterations\n", i12);
    }

    if (!show_roots && !show_iterations) {
        double area =
            integral(f1_minus_f3, x13, x23, EPS2) +
            integral(f1_minus_f2, x23, x12, EPS2);

        printf("%.6f\n", area);
    }

    return 0;
}