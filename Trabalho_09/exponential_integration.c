#include "exponential_integration.h"

double extended_trapezoidal_rule(double(*f)(double)){
	//h e m são parametros arbitrários, de maneira que h*m->infinity, mas que métodos gambiarrento!
	long int i;
	//long int m = INT_MAX/2;
	long int m = 200;
	double area = 0.0;
	double h = 2.0/m;
	for(i=-m; i<=m; i++) area+= f(i*h);
	area*=h;
	return area;
}

double simp_exp(double a, double b, double x, double(*f)(double)){
	double k = (0.5)*(a + b + (b - a)*tanh(x));
	double dkdx = (b - a)/2 	/ pow(cosh(x), 2);
	return f(k)*dkdx;
}

double dbl_exp(double a, double b, double x, double (*f)(double)){
	double k = 0.5* (a + b + (b - a)*(tanh(M_PI/2 *sinh(x))));
	double dkdx = (b-a)*M_PI/4*cosh(x) /  pow(cosh(M_PI/2 * sinh(x)),2);
	return f(k)*dkdx;
}