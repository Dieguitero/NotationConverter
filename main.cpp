//this is a temporary main file to test the deque

#include "NotationConverter.hpp"

#include <iostream>

int main() {

    const std::string infix1 = "(A + B) ";
    NotationConverter nc, nc2;

    nc.decodeInput(infix1);
    nc2.decodeInput(infix1);
    auto deque = nc.getDeque();
    auto deque2 = nc2.getDeque();
    auto size = deque.getSize();
    auto size2 = size;
    std::cout << "size = " << size2 << std::endl;
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