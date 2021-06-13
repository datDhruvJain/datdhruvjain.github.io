#include<iostream>
#include<fstream>
#include<string>
#include<vector>
//#include<stdio.h>

void be_lol(const int[]);

int main(){
	int arr[] = {1,2,3};
	be_lol(arr);
	
}

void be_lol(const int arr[]){
	for(int i=0; i<3; i++){
		//arr[i] += i;

		std::cout << i << std::endl;
	}
}
