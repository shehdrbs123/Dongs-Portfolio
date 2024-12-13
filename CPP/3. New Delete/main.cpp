#include <iostream>

int main()
{
    int* a = new int;
    *a= 10;
    int& b =*a;
    
    std::cout << b << std::endl;
    *a = 20;
    std::cout << b << std::endl;
    b = 30;
    std::cout << *a << std::endl;
}