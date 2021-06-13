#ifndef SHAPES_UTIL
#define SHAPES_UTIL
struct Rectangle{
	double length;
	double width;
};

namespace utilz
{
double area(double len, double wid);

double area(double side);

double area(int radius);

void area_tester();

double pow(double num, int power = 2);
}
#endif