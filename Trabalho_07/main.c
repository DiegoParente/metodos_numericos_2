#include <math.h>
#include <stdio.h>
#include "special_quadratures.h"

double f1(double x){
	//normal distribuiton with mean = 0 and standard deviation =  variance = 1, domain [-infinity, infinity]
	return (1.0/sqrt(2.0*M_PI))*exp((x*x)/2.0);
}

double f2(double x){
	return exp(-x);
}

double f3(double x){
	return 1/sqrt(1-x*x);	
}


int main(){
	double standard_gaussian_area =  integrate(0, 5, f1);
	printf("%lf\n", standard_gaussian_area);
	double euler_area = integrate(1, 4, f2);
	printf("%lf\n", euler_area);
	double maybe_pi = integrate(2, 10, f3);
	printf("%lf\n", maybe_pi);
	return 0;
}