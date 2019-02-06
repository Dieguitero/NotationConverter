//this is a temporary main file to test the deque

#include "NotationConverter.hpp"

#include <iostream>

int main() {

    const std::string infix1 = "(A + B) ";
    const std::string infix2 = "(A *     b)";
    NotationConverter nc, nc2, nc3;

    nc.decodeInput(infix1);
    nc2.decodeInput(infix1);
    nc3.decodeInput(infix2);
    auto deque = nc.getDeque();
    auto deque2 = nc2.getDeque();
    auto deque3 = nc3.getDeque();
    
    std::cout << nc.infixToPostfix(infix1) << std::endl;


    return 0;
}