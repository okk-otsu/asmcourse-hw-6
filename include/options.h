#ifndef OPTIONS_H
#define OPTIONS_H

/* Print command line usage information. */
void print_help(const char *program);

/* Run root-finding test specified by command line argument. */
int test_root_option(const char *arg);

/* Run integration test specified by command line argument. */
int test_integral_option(const char *arg);

#endif