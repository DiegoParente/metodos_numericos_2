#include <stdio.h>
#include "area.h"

double f(double x){
	return x*x;
}

int main(){
	double tolerance =  0.1;
	double a = 1.0, b = 5.0;
	double integral =  area(a, b, tolerance, f);
	printf("%f\n", integral);
	return 0;
}