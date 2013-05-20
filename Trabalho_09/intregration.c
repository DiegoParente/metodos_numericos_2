#include "integration.h"


double integral(int points, double a, double b, double (*f)(double), double tolerance, int opt){
	if(opt==0){//closed newton-cotes
		if(points == 2)	return integrate(tolerance, a, b, f, two_points_cnc);
		if(points == 3)	return integrate(tolerance, a, b, f, three_points_cnc);
		if(points == 4)	return integrate(tolerance, a, b, f, four_points_cnc);
		if(points == 5)	return integrate(tolerance, a, b, f, five_points_cnc);
		if(points == 6)	return integrate(tolerance, a, b, f, six_points_cnc);
	}
	if(opt==1){//open newton-cotes
		if(points == 2)	return integrate(tolerance, a, b, f, two_points_onc);
		if(points == 3)	return integrate(tolerance, a, b, f, three_points_onc);
		if(points == 4)	return integrate(tolerance, a, b, f, four_points_onc);
		if(points == 5)	return integrate(tolerance, a, b, f, five_points_onc);
		if(points == 6)	return integrate(tolerance, a, b, f, six_points_onc);
	}
	if(opt==2){//gauss-legendre
		if(points == 2)	return integrate(tolerance, a, b, f, two_points_gl);
		if(points == 3)	return integrate(tolerance, a, b, f, three_points_gl);
		if(points == 4)	return integrate(tolerance, a, b, f, four_points_gl);
		if(points == 5)	return integrate(tolerance, a, b, f, five_points_gl);
	}

}

double integrate(double tolerance, double a, double b, double (*f)(double), double (*method)(double, double, double(*)(double))){
	int it = 0;
	double area = method(a, b, f);
	double stoppage = area;
	do{
		it++;
		double iteration_area = 0.0;
		int partitions =  pow(2.0, it);
		double step = (b-a)/partitions;
		int aux;
		for(aux=0; aux<partitions; aux++) iteration_area+=method(a+aux*step, a+(aux+1)*step, f);
		stoppage = area - iteration_area;
		area = iteration_area;
	}while(stoppage>tolerance);
	return area;
}

double two_points_cnc(double a, double b, double(*f)(double)){ return (b-a)*(f(a)+f(b))/2;	}
double three_points_cnc(double a, double b, double(*f)(double)){ double step = (b-a)/2;	 return (b-a)*(f(a)+ 4*f(a+step) +f(b))/6;}
double four_points_cnc(double a, double b, double(*f)(double)){	double step = (b-a)/3;	return (b-a)*(f(a)+ 3*f(a+step) + 3*f(a+2*step) + f(b))/8;}
double five_points_cnc(double a, double b, double(*f)(double)){	double step = (b-a)/4;	return (b-a)*(7*f(a)+ 32*f(a+step) + 12*f(a+2*step) + 32*f(a+3*step) + 7*f(b))/90;}
double six_points_cnc(double a, double b, double(*f)(double)){ double step = (b-a)/5; return 5*(b-a)*(19*f(a) + 75*f(a+step) + 50*f(a+2*step) + 19*f(a+3*step) + 75*f(a+4*step) + 50*f(b))/288;}
double two_points_onc(double a, double b, double(*f)(double)){ double step = (b-a)/3; return (b-a)*1.5*(f(a+step)+f(a+2*step));}
double three_points_onc(double a, double b, double(*f)(double)){ double step = (b-a)/4;	return (b-a)*(4.0/3)*(2*f(a+step)- f(a + 2*step) + 2*f(a+3*step));}
double four_points_onc(double a, double b, double(*f)(double)){ double step = (b-a)/5; return (b-a)*(5.0/24)*(11*f(a+step)+ f(a + 2*step) + f(a + 3*step) +11*f(a+4*step));}
double five_points_onc(double a, double b, double(*f)(double)){	double step = (b-a)/6; return (b-a)*(6.0/20)*(11*f(a+step)- 14*f(a + 2*step) + 26*f(a + 3*step) - 14*f(a + 4*step) + 11*f(a+5*step));}
double six_points_onc(double a, double b, double(*f)(double)){ double step = (b-a)/7; return (b-a)*(7.0/1440)*(611*f(a+step) - 453*f(a + 2*step) + 562*f(a + 3*step) + 562*f(a + 4*step) - 453*f(a + 5*step) + 611*f(a+6*step));}
double two_points_gl(double a, double b, double(*f)(double)){ double k = (b-a)/2; double t = (b+a)/2; return k*(f(k*0.57735+t) + f(-0.57735*k + t));}
double three_points_gl(double a, double b, double(*f)(double)){	double k = (b-a)/2; double t = (b+a)/2;	return k*(0.888889*f(t) + 0.555556*f(0.774597*k+t) + 0.555556*f(-0.774597*k+t));}
double four_points_gl(double a, double b, double(*f)(double)){ double k = (b-a)/2; double t = (b+a)/2; return k*( 0.652145*f(0.339981*k+t) +  0.652145*f(-0.339981*k+t) + 0.347855*f(0.861136*k+t) + 0.347855*f(-0.861136*k+t));}
double five_points_gl(double a, double b, double(*f)(double)){ double k = (b-a)/2; double t = (b+a)/2; return k*( 0.568889*f(t) + 0.478629*f(0.538469*k+t) + 0.478629*f(-0.538469*k+t) + 0.236927*f(0.90618*k+t) + 0.236927*f(-0.90618*k+t));}
