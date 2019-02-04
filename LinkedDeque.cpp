#include "LinkedDeque.hpp"

LinkedDeque::LinkedDeque() {
    size = 0;
}

char LinkedDeque::front() {
    if(emptyDeque())
        throw("EmptyDeque");  
    return list.front();
}

char LinkedDeque::back() {
    if(emptyDeque())
        throw("EmptyDeque");
    return list.back();
}
void LinkedDeque::insertFront(const char& part) {
    list.addFront(part);
    size++;
}

void LinkedDeque::insertBack(const char& part) {
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