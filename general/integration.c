#include "integration.h"


double integrate(double a, double b, double error, double (*f)(double), double (*method_function)(double, double, double (*)(double))){
	int it;
	double area = DBL_MAX;
	int stop = 0;
	for(it = 1; !stop ; it*=2){
		double total_iteration_area = 0.0;
		double h = (b-a)/(double)it;
		double aux;
		for(aux = a; aux<b; aux+=h) total_iteration_area+=method_function(aux, aux+h, f);
		stop = (fabs(area - total_iteration_area))<error? 1 : 0;
		area = total_iteration_area;
	}
	return area;
}

double trapezoidal_closed_rule(double a, double b, double(*f)(double)){
	return (b-a)*(f(b)+f(a))/2;
}

//fifth order newton-cotes formula
double fifth_order_closed(double a, double b, double (*f)(double)){
	double h = (b-a)/5.0;
	return	h*(5.0/288.0)*(19*f(a) + 75*f(a+h) + 50*f(a+2*h) + 50*f(a+3*h) + 75*f(a+4*h) + 19*f(b));
}

double fifth_order_openned(double a, double b, double (*f)(double)){
	double h = (b-a)/7.0;
	return h*(7.0/1440.0)*(611*f(a+h) - 453*f(a+2*h) + 562*f(a+3*h) + 562*f(a+4*h) - 453*f(a+5*h) + 611*f(a+6*h));
}

double sub_romberg(double a, double b, int partitions, double(*f)(double)){
	double step = (b-a)/partitions;
	double area = 0.0;
	for(a; a<b; a+=step) area+=trapezoidal_closed_rule(a, a+step, f);
	return area;
}

double romberg_integration(double a, double b, double error, double(*f)(double)){
	double trapezoidal_area = sub_romberg(a, b, 2, f);
	double romberg_area = (4.0*trapezoidal_area - sub_romberg(a, b, 1, f))/3.0;
	int stop = 0;
	int it;
	for(it = 2; !stop; it++){
		double iteration_trapezoidal_area = sub_romberg(a, b, pow(2, it), f);
		double iteration_romberg_area = (4*iteration_trapezoidal_area - trapezoidal_area)/3;
		if (iteration_romberg_area - romberg_area < error) return iteration_romberg_area;
		romberg_area = iteration_romberg_area;
		trapezoidal_area = iteration_trapezoidal_area;
	}
	return romberg_area;
}
