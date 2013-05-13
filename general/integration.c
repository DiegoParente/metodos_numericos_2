#include "integration.h"


double integrate(double a, double b, double tolerance, double (*f)(double), method_name type, int points){
	double (*method)(double, double, int, double(*)(double));
	if(type==closed_newton_cotes) method = single_interval_closed_newton_cotes_estimative;
	else if(type==open_newton_cotes) method = single_interval_open_newton_cotes_estimative;
	else if(type==gauss_legendre) method = single_interval_gauss_legendre_estimative;
	double area = method(a, b, points, f);
	double var = area;
	printf("%lf\n", area);
	int partitions = 1;
	do{
		double iter_area = 0.0;
		partitions *=2;
		int it;
		double step = (b-a)/partitions;
		for(it=0; it<partitions; it++)	iter_area+=method(a+it*step, a+(it+1)*step, points, f);
		var = fabs(iter_area - area);
		area = iter_area;	
	}while(var>tolerance);  
 	return area;
}

double single_interval_closed_newton_cotes_estimative(double a, double b, int points,double (*f)(double)){
	double step = (b-a)/points;	
	if(points==2) return (b-a)*(f(a)+f(b))/2;
	else if(points==3) return (b-a)*(f(a)+ 4*f(a+step) +f(b))/6;
	else if(points==4) return (b-a)*(f(a)+ 3*f(a+step) + 3*f(a+2*step) + f(b))/8;
	else if(points==5) return (b-a)*(7*f(a)+ 32*f(a+step) + 12*f(a+2*step) + 32*f(a+3*step) + 7*f(b))/90;	
	else if(points==6) return 5*(b-a)*(19*f(a) + 75*f(a+step) + 50*f(a+2*step) + 19*f(a+3*step) + 75*f(a+4*step) + 50*f(b))/288;	
}

double single_interval_open_newton_cotes_estimative(double a, double b, int points,double (*f)(double)){
	double step = (b-a)/(points+2);
	double aux_a = a+step;
	double aux_b = b-step;
	if(points==2) return (b-a)*1.5*(f(aux_a)+f(aux_b));
	else if(points==3) return (b-a)*(4.0/3)*(2*f(aux_a)- f(aux_a + step) + 2*f(aux_b));
	else if(points==4) return (b-a)*(5.0/24)*(11*f(aux_a)+ f(aux_a + step) + f(aux_a + 2*step) +11*f(aux_b));
	else if(points==5) return (b-a)*(6.0/20)*(11*f(aux_a)- 14*f(aux_a + step) + 26*f(aux_a + 2*step) - 14*f(aux_a + 3*step) + 11*f(aux_b));	
	else if(points==6) return (b-a)*(7.0/1440)*(611*f(aux_a) - 453*f(aux_a + step) + 562*f(aux_a + 2*step) + 562*f(aux_a + 3*step) - 453*f(aux_a + 4*step) + 611*f(aux_b));	
}

double single_interval_gauss_legendre_estimative(double a, double b, int points, double(*f)(double)){
	if(points==2) return f(0.57735) + f(-0.57735);
	else if(points==3) return 0.888889*f(0.0) + 0.555556*f(0.774597) + 0.555556*f(-0.774597);
	else if(points==4) return (18.0+sqrt(30))/36*f((sqrt(525.0 - 70.0*sqrt(30)))/35.0) + (18.0+sqrt(30))/36*f(-(sqrt(525.0 - 70.0*sqrt(30)))/35.0) +  (18.0-sqrt(30))/36*f((sqrt(525.0 + 70.0*sqrt(30)))/35.0) + (18.0-sqrt(30))/36*f(-(sqrt(525.0 + 70.0*sqrt(30)))/35.0);
	else if(points==5) return (128.0/225)*f(0.0) + ((322 + 13*sqrt(70))/900.0)*f(sqrt(245.0 - 14*sqrt(70.0))/21) +  ((322 + 13*sqrt(70))/900.0)*f(-sqrt(245.0 - 14*sqrt(70.0))/21) + ((322 - 13*sqrt(70))/900.0)*f(sqrt(245.0 + 14*sqrt(70.0))/21) + ((322 - 13*sqrt(70))/900.0)*f(-sqrt(245.0 + 14*sqrt(70.0))/21);
}





