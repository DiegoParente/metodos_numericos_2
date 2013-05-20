#ifndef INTEGRATION_H
#define INTEGRATION_H
#include <math.h>

double integral(int points, double a, double b, double (*f)(double), double tolerance, int opt);
double integrate(double tolerance, double a, double b, double (*f)(double), double (*method)(double, double, double(*)(double)));

double two_points_cnc(double a, double b, double(*f)(double));
double three_points_cnc(double a, double b, double(*f)(double));
double four_points_cnc(double a, double b, double(*f)(double));
double five_points_cnc(double a, double b, double(*f)(double));
double six_points_cnc(double a, double b, double(*f)(double));

double two_points_onc(double a, double b, double(*f)(double));
double three_points_onc(double a, double b, double(*f)(double));
double four_points_onc(double a, double b, double(*f)(double));
double five_points_onc(double a, double b, double(*f)(double));
double six_points_onc(double a, double b, double(*f)(double));

double two_points_gl(double a, double b, double(*f)(double));
double three_points_gl(double a, double b, double(*f)(double));
double four_points_gl(double a, double b, double(*f)(double));
double five_points_gl(double a, double b, double(*f)(double));

#endif