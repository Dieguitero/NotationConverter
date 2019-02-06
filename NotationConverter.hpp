#ifndef NOTATIONCONVERTER_HPP
#define NOTATIONCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <algorithm> //To reverse a string

#include "NotationConverterInterface.hpp"
#include "DequeList.hpp"
#include "LinkedDeque.hpp"

class NotationConverter : public NotationConverterInterface {
public:
    NotationConverter() = default;
    ~NotationConverter() = default;

    virtual std::string postfixToInfix(std::string inStr);
    virtual std::string postfixToPrefix(std::string inStr);

    virtual std::string infixToPostfix(std::string inStr);
    virtual std::string infixToPrefix(std::string inStr);

    virtual std::string prefixToInfix(std::string inStr);
    virtual std::string prefixToPostfix(std::string inStr);

    void decodeInput(std::string inStr);

    LinkedDeque getDeque() const { return notation_deque; }
private:
    LinkedDeque notation_deque;
};

#endif /* NOTATIONCONVERTER_HPP */