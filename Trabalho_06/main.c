#include "integration.h"
#include <math.h>
#include <stdio.h>

int main(){

	double cnc2, cnc3, cnc4, cnc5, cnc6;
	cnc2 = integral(2, 0, 1, exp, 0.001, 0);
	cnc3 = integral(3, 0, 1, exp, 0.001, 0);
	cnc4 = integral(4, 0, 1, exp, 0.001, 0);
	cnc5 = integral(5, 0, 1, exp, 0.001, 0);
	cnc6 = integral(6, 0, 1, exp, 0.001, 0);
	printf("cnc2: %lf\n", cnc2);
	printf("cnc3: %lf\n", cnc3);
	printf("cnc4: %lf\n", cnc4);
	printf("cnc5: %lf\n", cnc5);
	printf("cnc6: %lf\n", cnc6);

	double onc2, onc3, onc4, onc5, onc6;
	onc2 = integral(2, 0, 1, exp, 0.001, 1);
	onc3 = integral(3, 0, 1, exp, 0.001, 1);
	onc4 = integral(4, 0, 1, exp, 0.001, 1);
	onc5 = integral(5, 0, 1, exp, 0.001, 1);
	onc6 = integral(6, 0, 1, exp, 0.001, 1);
	printf("onc2: %lf\n", onc2);
	printf("onc3: %lf\n", onc3);
	printf("onc4: %lf\n", onc4);
	printf("onc5: %lf\n", onc5);
	printf("onc6: %lf\n", onc6);

	double gl2, gl3, gl4, gl5;
	gl2 = integral(2, 0, 1, exp, 0.001, 2);
	gl3 = integral(3, 0, 1, exp, 0.001, 2);
	gl4 = integral(4, 0, 1, exp, 0.001, 2);
	gl5 = integral(5, 0, 1, exp, 0.001, 2);

	printf("gl2: %lf\n", gl2);
	printf("gl3: %lf\n", gl3);
	printf("gl4: %lf\n", gl4);
	printf("gl5: %lf\n", gl5);


	return 0;
}