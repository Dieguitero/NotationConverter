#include "DequeList.hpp"

class LinkedDeque {
public:
    LinkedDeque();
    ~LinkedDeque() = default;
    
    int getSize() const { return size; }
    bool emptyDeque() { return list.emptyList(); }
    std::string front();
    std::string back();

    void insertFront(const std::string& part);
    void insertBack(const std::string& part);
    void removeFront();
    void removeBack();
    void clear();
private:
    int size; //num of elements in the deque
    DequeList list;
friend class DequeList;
};