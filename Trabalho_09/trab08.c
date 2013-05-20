#include "exponential_integration.h"
#include "integration.h"
#include <math.h>
#include <stdio.h>

//cos(Pi x)/( Sqrt(1 -x) )
double f2(double x){
	return cos(M_PI*x)/sqrt(1.0 -x);
}

double dbl_exp_f2(double x){
	return dbl_exp(-1, 1, x, f2);
}


int main(){
	printf("%lf\n", extended_trapezoidal_rule(dbl_exp_f2));
	printf("%lf\n", integral(5, -1, 1, f2, 0.01, 2));

	return 0;
}