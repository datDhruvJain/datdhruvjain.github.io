#include<iostream>
#include<fstream>
#include<vector>

void ofstream_demo(){
    // Need to create an object of the file first
    std::ofstream file;
    file.open("hello.txt");
    
    file << "Hello world" << std::endl;

    file.close();
}

void vector_filestream_demo(){
    std::ofstream file;
    file.open("hello.txt");

    std::vector <std::string> names = {"Dhruv", "mamma", "shriyas","satvik"};

    for (std::string a : names){
        file << a << std::endl;
    }
}

int main(){
    vector_filestream_demo();
}