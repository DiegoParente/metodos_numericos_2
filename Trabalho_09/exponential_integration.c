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