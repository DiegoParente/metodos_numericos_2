#include "exponential_integration.h"
#include <math.h>
#include <stdio.h>


//f(x) = 1/( (x-2) (1-x)^(1/4) (1+x)^(3/4) )
double f1(double x){
	return pow((x-2)*(pow(1-x, 0.25))*pow(1+x, 0.75) ,-1);
}
double f1_a = -1.0;
double f1_b = 1.0;

double exp_f1(double x){
	return f1((1.0/2)*(f1_a+f1_b+(f1_b - f1_a)*tanh(x)))*(0.5)*(f1_b-f1_a)*(pow(cosh(x)*cosh(x), -1));
}

double extended_trapezoidal_rule_test_function(double x){
	return exp(-x*x);
}

int main(){
	printf("%lf\n", extended_trapezoidal_rule(extended_trapezoidal_rule_test_function));
	printf("%lf\n", extended_trapezoidal_rule(exp_f1));
	return 0;
}