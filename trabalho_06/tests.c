#include "integration.h"
#include <stdio.h>

double f(double x){
	return x*x;//f(x) = x², If(x)dx = x³/3
}

int main(){
	double area = integrate(0, 1, 0.01, f, trapezoidal_closed_rule);
	printf("%lf\n", area);
	double newton_test = integrate(0, 1, 0.01, f, fifth_order_closed);
	printf("%lf\n", newton_test);
	double openned_newton_test = integrate(0, 1, 0.01, f, fifth_order_openned);
	printf("%lf\n", openned_newton_test);
	double romberg_area = romberg_integration(0, 1, 0.01, f);
	printf("%lf\n", romberg_area);
	return 0;
}