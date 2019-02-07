#ifndef DEQUELIST_HPP
#define DEQUELIST_HPP

#include <string>

class DequeListNode {
public:
    DequeListNode() = default;
    ~DequeListNode() = default;
private:
    std::string part;
    DequeListNode* prev;
    DequeListNode* next;
friend class DequeList;
};

class DequeList {
public:
    DequeList();
    ~DequeList();
    std::string front() const { return header->next->part; }
    std::string back() const { return trailer->prev->part; }
    void emptyAdd(DequeListNode* new_part); //Helper function to add a new element to an empty list
    bool emptyList() { return (header->next == trailer); }


    void addFront(const std::string& part);
    void addBack(const std::string& part);
    void removeFront();
    void removeBack();
private:
    unsigned int size;
    DequeListNode* header;
    DequeListNode* trailer;
};

#endif /* DEQUELIST_HPP */