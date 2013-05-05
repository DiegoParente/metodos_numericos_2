#include <stdio.h>
#include <math.h>

double	constant_sub(double a, double b, double (*f)(double)){
	return (a+b)/2;
}

double closed_fifth_order(double a, double b, double (*f)(double)){
	//six-point closed formula (Abramowitz and Stegun 1972, p. 886)
	double h = (b-a)/5;
	return (5.0/288.0)*(b-a)*(19.0*f(a) + 75*f(a+h) + 50*f(a+2*h) + 50*f(a+3*h) + 75*(a+4*h) + 19*f(b));
}

double openned_fifth_order(double a, double b, double (*f)(double)){
	double h = (b-a)/7;
	return (7/1440)*(b-a)*(611*f(a+h) - 453*f(a+2*h) + 652*f(a+3*h) + 652*f(a+4*h) - 453*f(a+5*h) + 611*f(a+6*h));
}

double fifth_order_area(double a, double b, double tolerance, double (*f)(double), int op){
	double (*g)(double, double, double (*)(double)) = op? closed_fifth_order : openned_fifth_order;
	double h;
	int counter = 0;
	int it = 2;
	double area = (g(a, b, f))*(b-a);
	double var = area;
	do{
		counter++;
		double aux = area;
		area = 0.0;
		h = (b-a)/it;
		double step;
		for(step = a; step < b; step += h){
			area += g(step, step+h, f);	
		}
		it*=2;
		printf("area: %f, var: %f\n", area, var);
		var = fabs(aux - area);
	}while(var > tolerance);
	printf("fifth_order_area took %d\n iterations\n", counter);
	return area;
}

double linear_area(double a, double b, double tolerance, double (*f)(double)){
	int counter = 0;
	double h;
	int it = 2;
	double area = ((f(a) + f(b))/2.0)*(b-a);
	double var = area;
	do{
		counter++;
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
	printf("trapezoidal took %d\n iterations\n", counter);
	return area;
}

double func(double x){
	return x*x;
}

main(){
	double la =  linear_area(0.0, 1.0, 0.0001, func);
	double fa = fifth_order_area(0.0, 1.0, 0.0001, func, 1);
	printf("%lf\n%lf\n", la, fa);
	return 0;
}