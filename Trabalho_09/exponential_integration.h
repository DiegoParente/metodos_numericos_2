#ifndef EXPONENTIAL_INTEGRATION_H
#define EXPONENTIAL_INTEGRATION_H
#include <math.h>
#include <limits.h>


double extended_trapezoidal_rule(double(*f)(double));
double simp_exp(double a, double b, double x, double(*f)(double));
double dbl_exp(double a, double b, double x, double (*f)(double));

#endif