#ifndef INTEGRATION_H
#define INTEGRATION_H
#include <float.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	double area;
	int iterations;
	clock_t timer;
}report;

double integrate(double a, double b, double error, double (*f)(double), double (*method_function)(double, double, double (*)(double)));
double trapezoidal_closed_rule(double a, double b, double(*f)(double));
double fifth_order_closed(double a, double b, double (*f)(double));
double fifth_order_openned(double a, double b, double (*f)(double));
double romberg_integration(double a, double b, double error, double(*f)(double));
#endif