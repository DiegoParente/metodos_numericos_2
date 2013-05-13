#include "integration.h"


double integrate(double a, double b, double tolerance, double (*f)(double), method_type method, int points){
	if(method < 2) return newton_cotes_method(a, b, tolerance, f, method, points);
	else return gauss_legendre_method(a, b, tolerance, f, method, points);
}
double newton_cotes_method(double a, double b, double tolerance, double (*f)(double), method_type method, int points){
	int it=0;
	double area  = 
	while(++it){
		int partitions = pow(2, it);
	}
}

double sub_newton_cotes(double a, double b, double (*f)(double), method_type method, int partitions){
	int it = 0;
	double step = (b-a)/partitions;
	double area = 0.0;
	for(it=0; it<partitions; it++) 
}
double gauss_legendre_method(double a, double b, double tolerance, double (*f)(double), method_type method, int points);