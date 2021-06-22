// This shows examples for method overloading and Default parameters, and multifile compilation
#include<iostream>

using namespace std;

struct Rectangle{
	double length;
	double width;
};

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

double pow(double num, int power = 2){
	double ans=1;

	for (int i=0; i<power; i++){
		ans*=num;
	}
	return ans;
}

int main(){
	cout << pow(3,3) << endl;
}
