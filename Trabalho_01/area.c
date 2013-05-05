#include "area.h"

double area(double a, double b, double tolerance, double (*f)(double)){
	double h;
	int it = 2;
	double area = ((f(a) + f(b))/2.0)*(b-a);
	double var = area;
	do{
		double aux = area;
		area = 0.0;
		h = (b-a)/it;
		double step;
		for(step = a; step < b; step += h){
			area += ((f(step)+f(step+h))/2.0)*h;	
		}
		it*=2;
		printf("area: %f, var: %f\n", area, var);
		var = fabs(aux - area);
	}while(var > tolerance);
	return area;
}

