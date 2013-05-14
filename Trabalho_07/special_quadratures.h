#ifndef SPECIAL_QUADRATURES_H
#define SPECIAL_QUADRATURES_H
#include <math.h>
double integrate(int opc, int points, double(*f)(double));

double two_points_gauss_hermite(double(*f)(double));
double three_points_gauss_hermite(double(*f)(double));
double four_points_gauss_hermite(double(*f)(double));
double five_points_gauss_hermite(double(*f)(double));

double two_points_gauss_laguerre(double(*f)(double));
double three_points_gauss_laguerre(double(*f)(double));
double four_points_gauss_laguerre(double(*f)(double));

double gauss_chebyshev(int points, double(*f)(double));

#endif