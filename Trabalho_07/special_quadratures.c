#include "special_quadratures.h"

double integrate(int opc, int points, double(*f)(double)){
	//opc == 0 stands for gauss-hermite, opc == 1 stands for gauss-laguerre, and opc == 2 stands for gauss 
	if(opc==0){
		switch(points){
			case 2:
				return two_points_gauss_hermite(f);
			case 3:
				return three_points_gauss_hermite(f);
			case 4:
				return four_points_gauss_hermite(f);
			case 5:
				return five_points_gauss_hermite(f);
		}
	}
	if(opc==1){
		switch(points){
			case 2:
				return two_points_gauss_laguerre(f);
			case 3:
				return three_points_gauss_laguerre(f);
			case 4:
				return four_points_gauss_laguerre(f);
		}
	}
	if(opc==2){
		return gauss_chebyshev(points, f);
	}
}

double two_points_gauss_hermite(double(*f)(double)){return 0.88622692*f(-0.70710678) + 0.88622692*f(0.70710678);}
double three_points_gauss_hermite(double(*f)(double)){return  0.29540897*f(-1.22474487) +  1.18163590*f(0.0) + 0.29540897*f(1.22474487);}
double four_points_gauss_hermite(double(*f)(double)){return 0.08131283*f(-1.65068012) + 0.80491409*f(-0.52464762) + 0.80491409*f(0.52464762) + 0.08131283*f(1.65068012);}
double five_points_gauss_hermite(double(*f)(double)){return 0.01995324*f(-2.02018287) + 0.01995324*f(2.02018287) + 0.39361932*f(-0.95857246) + 0.39361932*f(0.95857246) + 0.94530872*f(0.0);}

double two_points_gauss_laguerre(double(*f)(double)){return 0.85355339*f(0.58578643) + 0.14644660*f(3.41421356);}
double three_points_gauss_laguerre(double(*f)(double)){	return 0.71109300*f(0.41577455) + 0.27851773*f(2.29428036) + 0.010389256*f(6.28994508);}
double four_points_gauss_laguerre(double(*f)(double)){return  0.60315410*f(0.32254768) + 0.35741869*f(1.74576110) + 0.038887908*f(4.53662029) + 0.00053929470*f(9.39507091);}


double gauss_chebyshev(int points, double(*f)(double)){
	double w =  (double)M_PI/points;
	int it;
	double area = 0.0;
	for(it = 1; it<=points; it++){
		double x =  cos(((double)it - 0.5)*w);
		area+=w*f(x);
	}
	return area;
}
