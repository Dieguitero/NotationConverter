//this is a temporary main file to test the deque

#include "NotationConverter.hpp"

#include <iostream>

int main() {

    const std::string infix1 = "(A + B) ";
    NotationConverter nc;

    nc.decodeInput(infix1);
    auto deque = nc.getDeque();
    auto deque2 = nc.getDeque();
    std::cout << "Forwards: " << std::endl;
    for(auto i = 0; i < deque.getSize(); i++){
        std::cout << deque.front() << std::endl;
    }
    while(!deque.emptyDeque()){
        deque.removeFront();
    }
    if(deque.emptyDeque())
        std::cout << "properly emptied deque" << std::endl;

    std::cout << "Backwards: " << std::endl;
    for(auto i = 0; i < deque2.getSize(); i++) {
        std::cout << deque2.back() << std::endl;
    }
    while(!deque.emptyDeque()) {
        deque2.removeBack();
    }
    if(deque2.emptyDeque()){
        std::cout << "properly emptied deque2" << std::endl;
    }
    return 0;
}