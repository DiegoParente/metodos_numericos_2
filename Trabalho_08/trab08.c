#include "exponential_integration.h"
#include <math.h>
#include <stdio.h>


//f(x) = 1/( (x-2) (1-x)^(1/4) (1+x)^(3/4) )
double f1(double x){
	return pow((x-2)*(pow(1-x, 0.25))*pow(1+x, 0.75) ,-1);
}
double f1_a = -1.0;
double f1_b = 1.0;
//cos(Pi x)/( Sqrt(1 -x) )
double f2(double x){
	return cos(M_PI*x)/sqrt(1.0 -x);
}


double exp_f1(double x){
	double k = (0.5)*(f1_a + f1_b + (f1_b - f1_a)*tanh(x));
	double dkdx = (f1_b - f1_a)/2 	/ pow(cosh(x), 2);
	return f1(k)*dkdx;
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

double exp_f2(double x){
	return dbl_exp(-1, 1, x, f2);
}

double dex_f1(double x){
	return dbl_exp(-1, 1, x, f1);
}

double extended_trapezoidal_rule_test_function(double x){
	return exp(-x*x);
}

int main(){
	printf("%lf\n", extended_trapezoidal_rule(extended_trapezoidal_rule_test_function));
	printf("%lf\n", extended_trapezoidal_rule(exp_f1));
	printf("%lf\n", extended_trapezoidal_rule(exp_f2));
	printf("%lf\n", extended_trapezoidal_rule(dex_f1));

	return 0;
}