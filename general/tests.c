#include "integration.h"
#include <stdio.h>
#include <math.h>

double f(double x){

}

int main(){
	double cnc2, cnc3, cnc4, cnc5, cnc6;
	double onc2, onc3, onc4, onc5, onc6;
	double l2, l3, l4, l5;
	cnc2 = integrate(0.0, 1.0, 0.001, exp, 0, 2);
	cnc3 = integrate(0.0, 1.0, 0.001, exp, 0, 3);
	cnc4 = integrate(0.0, 1.0, 0.001, exp, 0, 4);
	cnc5 = integrate(0.0, 1.0, 0.001, exp, 0, 5);
	cnc6 = integrate(0.0, 1.0, 0.001, exp, 0, 6);

	onc2 = integrate(0.0, 1.0, 0.001, exp, 1, 2);
	onc3 = integrate(0.0, 1.0, 0.001, exp, 1, 3);
	onc4 = integrate(0.0, 1.0, 0.001, exp, 1, 4);
	onc5 = integrate(0.0, 1.0, 0.001, exp, 1, 5);
	onc6 = integrate(0.0, 1.0, 0.001, exp, 1, 6);

	l2 = integrate(0.0, 1.0, 0.01, exp, gauss_legendre, 2);
	l3 = integrate(0.0, 1.0, 0.01, exp, gauss_legendre, 3);
	l4 = integrate(0.0, 1.0, 0.01, exp, gauss_legendre, 4);
	l5 = integrate(0.0, 1.0, 0.01, exp, gauss_legendre, 5);

	printf("cnc2: %lf\n\n", cnc2); 
	printf("cnc3: %lf\n\n", cnc3); 
	printf("cnc4: %lf\n\n", cnc4); 
	printf("cnc5: %lf\n\n", cnc5); 
	printf("cnc6: %lf\n\n\n", cnc6); 

	printf("%lf\n\n", onc2);
	printf("%lf\n\n", onc3);
	printf("%lf\n\n", onc4);
	printf("%lf\n\n", onc5);
	printf("%lf\n\n\n", onc6);

	printf("%lf\n\n", l2);
	printf("%lf\n\n", l3);
	printf("%lf\n\n", l4);
	printf("%lf\n\n\n", l5);

	return 0;
}
