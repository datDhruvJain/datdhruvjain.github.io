// This shows examples for method overloading and Default parameters, and multifile compilation
#include <iostream>
#include "shapes_util.h"
using namespace std;



int main(){
	double base;
	int power;
	cout << "Enter base";
	cin >> base;
	cout << "Enter power ";
	cin >> power;
	cout << utilz::pow(base,power) << endl;
}
