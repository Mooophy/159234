#include "A2P2.h"
#include <iostream>

int main()
{
    info();  
    VecT<double> v1(3);	
    std::cout << "\nEnter 3 double values, please\n";
    std::cin >> v1;
    
    std::cout << "\nThanks! Your values are:\n";
    std::cout << v1;

    VecT<std::string> v2(2);
    std::cout << "\nEnter 2 words, please\n";
    std::cin >> v2;
    
    std::cout << "\nThanks! Your words are:\n";
    std::cout << v2;
    std::cout << "\nBye\n"; 
}
