//this is a temporary main file to test the deque

#include "NotationConverter.hpp"

#include <iostream>

int main() {
    // const std::string prefix1 = "+ / * x y g h";
    const std::string prefix1 = "^ / x y * a b";
    const std::string postfix1 = "X Y + A B + *";
    const std::string postfix2 = "V C +";
    const std::string infix2 = "((X + B) * (Y - D))";
    NotationConverter n4;
    
    // std::cout << n4.prefixToInfix(prefix1) << std::endl;
    std::cout << n4.postfixToInfix(postfix1) << std::endl;
    std::cout << n4.infixToPostfix(infix2) << std::endl;
    return 0;
}