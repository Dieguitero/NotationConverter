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
    
    std::cout << "Forwards: " << std::endl;
    while (!deque.emptyDeque()){
        std::cout << deque.front() << std::endl;
        deque.removeFront();
    }
    if(deque.emptyDeque())
        std::cout << "properly emptied deque" << std::endl;

    std::cout << "Backwards: " << std::endl;

    while(!deque2.emptyDeque()) {
        std::cout << deque2.back() << std::endl;
        deque2.removeBack();
    }
    if(deque2.emptyDeque()){
        std::cout << "properly emptied deque2" << std::endl;
    }

    return 0;
}