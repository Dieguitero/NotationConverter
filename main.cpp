//this is a temporary main file to test the deque

#include "NotationConverter.hpp"

#include <iostream>

int main() {
    // const std::string prefix1 = "+ / * x y g h";
    const std::string prefix1 = "^ / x y * a b";
    const std::string postfix1 = "X Y + A B + *";
    const std::string postfix2 = "V C +";
    const std::string infix2 = "((X + B) * (Y - D))";
    const std::string infix1 = "(A + B)";
    NotationConverter n4;
    NotationConverter nc;
    
    // std::cout << n4.prefixToInfix(prefix1) << std::endl;
    std::cout << n4.postfixToInfix(postfix1) << std::endl;
    std::cout << nc.infixToPostfix(infix1) << std::endl;
    std::cout << nc.infixToPostfix(infix2) << std::endl;
    return 0;
}