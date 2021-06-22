#include <iostream>
#include "shapes_util.h"
using namespace std;

// showing how to use namespaces
namespace utilz
{
double area(double len, double wid){
	return len*wid;
}

double area(double side){
	return side*side;
}

double area(int radius){
	return 3.14*radius*radius;
}

void area_tester(){
	Rectangle rectangle;
	rectangle.length = 10;
	rectangle.width = 12;
	
	double ar = area(rectangle.length, rectangle.width);
	cout << ar << endl;
}

double pow(double num, int power){
	double ans=1;

	for (int i=0; i<power; i++){
		ans*=num;
	}
	return ans;
}
}