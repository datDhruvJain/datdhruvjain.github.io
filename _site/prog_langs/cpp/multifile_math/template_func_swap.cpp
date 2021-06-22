#include<iostream>

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a,b;
    a = 10;
    b = 12;
    
    std::cout << a << " " << b << std::endl;
    swap(a,b);
    std::cout << a << " " << b << std::endl;

    std::string c,d;
    c = " Hello ";
    d = " world ";
    std::cout << c << " " << d << std::endl;
    swap(c,d);
    std::cout << c << " " << d << std::endl;
}