#include "DequeList.hpp"

DequeList::DequeList() {
    header = new DequeListNode;
    trailer = new DequeListNode;
    header->next = trailer;
    trailer->prev = header;
    size = 0;
}

DequeList::~DequeList() {
    while(!emptyList()) {
        removeFront();
    }
    delete trailer;
    delete header;
}

void DequeList::emptyAdd(DequeListNode* new_part) {
    header->next = new_part;
    new_part->prev = header;
    new_part->next = trailer;
    trailer->prev = new_part;
}

void DequeList::addFront(const char& part) {
    DequeListNode* new_part = new DequeListNode;
    new_part->part = part;

    if(emptyList()) {
        emptyAdd(new_part);
    }
    else {
        auto next_node = header->next;
        header->next = new_part;
        new_part->prev = header;
        new_part->next = next_node;
        next_node->prev = new_part;
    }
}

void DequeList::addBack(const char& part) {
    DequeListNode* new_part = new DequeListNode;
    new_part->part = part;
    if(emptyList()) {
        emptyAdd(new_part);
    }
    else {
        auto prev_node = trailer->prev;
        trailer->prev = new_part;
        new_part->next = trailer;
        new_part->prev = prev_node;
        prev_node->next = new_part;
    }
}

void DequeList::removeFront() {
    if(emptyList())
        throw("EmptyList");
    
    auto node_to_remove = header->next;
    auto next_node = node_to_remove->next;
    header->next = next_node;
    next_node->prev = header;

    delete node_to_remove;
    size--;
}

void DequeList::removeBack() {
    if(emptyList())
        throw("EmptyList");
    
    auto node_to_remove = trailer->prev;
    auto prev_node = node_to_remove->prev;
    trailer->prev = prev_node;
    prev_node->next = trailer;

    delete node_to_remove;
    size--;
}