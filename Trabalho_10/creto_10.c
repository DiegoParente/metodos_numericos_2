#include <stdio.h>
#include <math.h>

//type 0 for forward, 1 for backward and 2 for central
//dom 0 to diff dy and dom 1 to diff dx
double seven_points_diff(int dom ,int type, double x, double y ,double h, double (*f)(double, double)){
if(type == 1){	
	if(dom == 1) return (137.0*f(x+6.0*h, y) - 972.0*f(x+5.0*h, y) + 2970.0*f(x+4.0*h, y) -5080.0*f(x+3*h, y) + 5265.0*f(x+2*h, y) - 3132.0*f(x+h, y) + 812.0*f(x, y))/(180.0*pow(h,2.0)); 
	if(dom == 0) return (137.0*f(x, y+6.0*h) - 972.0*f(x, y+5.0*h) + 2970.0*f(x, y+4.0*h) -5080.0*f(x, y+3*h) + 5265.0*f(x, y+2*h) - 3132.0*f(x, y+h) + 812.0*f(x, y))/(180.0*pow(h,2.0));
}
if(type == 2){
	if(dom == 1) return (137.0*f(x-6.0*h, y) - 972.0*f(x-5.0*h, y) + 2970.0*f(x-4.0*h, y) -5080.0*f(x-3*h, y) + 5265.0*f(x-2*h, y) - 3132.0*f(x-h, y) + 812.0*f(x, y))/(180.0*pow(h,2.0));	
	if(dom == 0) return (137.0*f(x, y-6.0*h) - 972.0*f(x, y-5.0*h) + 2970.0*f(x, y-4.0*h) -5080.0*f(x, y-3*h) + 5265.0*f(x, y-2*h) - 3132.0*f(x, y-h) + 812.0*f(x, y))/(180.0*pow(h,2.0));
}	
if(type == 3)
	if(dom == 1) return (2.0*f(x+3.0*h, y) - 27.0*f(x+2.0*h, y) + 270.0*f(x+h, y) - 490*f(x, y) + 270.0*f(x-h, y) - 27.0*f(x-2.0*h, y) + 2.0*f(x-3.0*h, y))/(180.0*pow(h,2.0));
	if(dom == 0) return (2.0*f(x,y+3.0*h) - 27.0*f(x,y+2.0*h) + 270.0*f(x,y+h) - 490*f(x,y) + 270.0*f(x,y-h) - 27.0*f(x,y-2.0*h) + 2.0*f(x,y-3.0*h))/(180.0*pow(h,2.0));

}

double upper_right_filter(double x, double y, double h, double (*f)(double, double)){
	return seven_points_diff(0, 1, x, y, h, f) + seven_points_diff(1, 1, x, y, h, f);
}

double central_filter(double x, double y, double h, double (*f)(double, double)){
	return seven_points_diff(0, 2, x, y, h, f) + seven_points_diff(1, 2, x, y, h, f);
}