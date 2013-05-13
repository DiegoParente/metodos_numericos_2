#ifndef INTEGRATION_H
#define INTEGRATION_H
#include <float.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//Open Newton-Cotes, Closed Newton-Cotes, Gauss-Legendre

typedef enum{
FALSE, TRUE
}bool;

typedef enum{
closed_newton_cotes, open_newton_cotes, gauss_legendre
}method_name;

double integrate(double a, double b, double tolerance, double (*f)(double), method_name type, int points);


double single_interval_closed_newton_cotes_estimative(double a, double b, int points,double (*f)(double));

double single_interval_open_newton_cotes_estimative(double a, double b, int points,double (*f)(double));

double single_interval_gauss_legendre_estimative(double a, double b, int points, double(*f)(double));

#endif