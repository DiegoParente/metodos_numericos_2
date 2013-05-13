#ifndef INTEGRATION_H
#define INTEGRATION_H
#include <float.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//Open Newton-Cotes, Closed Newton-Cotes, Gauss-Legendre

typedef enum{
ONC, CNC, GL; 
}method_type;

double closed_newton_cotes[20];
	newton_cotes[0] = 1.0/2; newton_cotes[1] =1.0/2; 
	newton_cotes[2] = 1.0/3; newton_cotes[3] = 4.0/3; newton_cotes[4] = 1.0/3;
	newton_cotes[5] = 3.0/8; newton_cotes[6] = 9.0/8; newton_cotes[7] = 9.0/8; newton_cotes[8] = 3.0/8; 
	newton_cotes[9] = 14.0/45; newton_cotes[10] = 64.0/45; newton_cotes[11] = 24.0/45; newton_cotes[12] = 64.0/45; newton_cotes[13] = 14.0/45; 
	newton_cotes[14] = 65.0/288; newton_cotes[15] = 375.0/288; newton_cotes[16] = 250.0/288; newton_cotes[17] = 250.0/288; newton_cotes[18] = 375.0/288; newton_cotes[19] = 65.0/288;

double open_newton_cotes[20];
	newton_cotes[0] = 3.0/2; newton_cotes[1] =3.0/2; 
	newton_cotes[2] = 8.0/3; newton_cotes[3] = -4.0/3; newton_cotes[4] = 8.0/3;
	newton_cotes[5] = 55.0/24; newton_cotes[6] = 5.0/24; newton_cotes[7] = 5.0/24; newton_cotes[8] = 55.0/24; 
	newton_cotes[9] = 66.0/20; newton_cotes[10] = -84.0/20; newton_cotes[11] = 156.0/20; newton_cotes[12] = -84.0/20; newton_cotes[13] = 66.0/20; 
	newton_cotes[14] = 7.0*611.0/1440; newton_cotes[15] = 7.0*(-453.0)/1440; newton_cotes[16] = 7.0*562.0/1440; newton_cotes[17] = 7.0*562.0/1440; newton_cotes[18] = 7.0*(-453.0)/1440; newton_cotes[19] = 7.0*611.0/1440;

double **newton_cotes;
newton_cotes =	(double **)calloc(2, sizeof(double*));
newton_cotes[0] = closed_newton_cotes;
newton_cotes[1] = open_newton_cotes 

double integrate(double a, double b, double tolerance, double (*f)(double), method_type method, int points);
double newton_cotes_method(double a, double b, double tolerance, double (*f)(double), method_type method, int points);
double gauss_legendre_method(double a, double b, double tolerance, double (*f)(double), method_type method, int points);

#endif