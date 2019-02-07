//this is a temporary main file to test the deque

#include "NotationConverter.hpp"

#include <iostream>

int main() {
    const std::string prefix1 = "+ / * x y g h";
    // const std::string prefix1 = "^ / x y * a b";
    NotationConverter n4;
    
    std::cout << n4.prefixToInfix(prefix1) << std::endl;


    return 0;
}