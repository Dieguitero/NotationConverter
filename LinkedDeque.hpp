#include "DequeList.hpp"

class LinkedDeque {
public:
    LinkedDeque();
    ~LinkedDeque() = default;
    
    int getSize() const { return size; }
    bool emptyDeque() { return list.emptyList(); }
    char front();
    char back();

    void insertFront(const char& part);
    void insertBack(const char& part);
    void removeFront();
    void removeBack();
    void clear();
private:
    int size; //num of elements in the deque
    DequeList list;
friend class DequeList;
};