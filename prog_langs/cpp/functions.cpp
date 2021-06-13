#include<iostream>

using namespace std;

void pass_by_value(int x){
	x++;
	std::cout << x << std::endl;
}

void pass_by_reference(int &x){
	x++;
	std::cout << x << std::endl;
}

void func_test(){
	int x = 12;
	pass_by_value(x);
	std::cout << x << std::endl;
	
	std::cout << "---" << std::endl;
	
	pass_by_reference(x);
	std::cout << x << std::endl;
}

void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swap(string &a, string &b){
	string temp;
	temp = a;
	a = b;
	b = temp;
}

void swap_int_test(){
	int a = 12;
	int b = 13;
	
	swap(a, b);
	
	cout << a << " " << b << endl;
}

void swap_str_test(){
	string a = " Hello ";
	string b = " World ";
	
	swap(a, b);
	
	cout << a << " " << b << endl;
}

void func_overloading(int x){
	std::cout << x << std::endl;
}

void func_overloading(std::string x){
	std::cout << x << std::endl;
}

int main(){
	swap_str_test();
}
