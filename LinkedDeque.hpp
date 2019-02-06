#include "DequeList.hpp"

class LinkedDeque {
public:
    LinkedDeque();
    ~LinkedDeque() = default;
    
    int getSize() const { return size; }
    bool emptyDeque() { return list.emptyList(); }
    char front();
    char back();
    DequeListNode* getCursor() const { return list.getCursor(); }
    DequeList getList() const { return list; }
    void insertFront(const char& part);
    void insertBack(const char& part);
    void removeFront();
    void removeBack();
    void iterateCursor();
private:
    int size; //num of elements in the deque
    DequeListNode* cursor;
    DequeList list;
friend class DequeList;
};