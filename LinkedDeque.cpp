#include "LinkedDeque.hpp"

LinkedDeque::LinkedDeque() {
    size = 0;
}

std::string LinkedDeque::front() {
    if(emptyDeque())
        throw("EmptyDeque");  
    return list.front();
}

std::string LinkedDeque::back() {
    if(emptyDeque())
        throw("EmptyDeque");
    return list.back();
}
void LinkedDeque::insertFront(const std::string& part) {
    list.addFront(part);
    size++;
}

void LinkedDeque::insertBack(const std::string& part) {
    list.addBack(part);
    size++;
}

void LinkedDeque::removeFront() {
    if(emptyDeque())
        throw("EmptyDeque");
    list.removeFront();
    size--;
}

void LinkedDeque::removeBack() {
    if(emptyDeque())
        throw("EmptyDeque");
    list.removeBack();
    size--;
}

void LinkedDeque::clear() {
    while(!emptyDeque()) {
        removeBack();
    }
}