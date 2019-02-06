#include "NotationConverter.hpp"

bool isPrefix(std::string str) {
    return ((str.at(0) == '+') || (str.at(0) == '-') || (str.at(0) == '/') || (str.at(0) == '*'));
}

void NotationConverter::decodeInput(std::string inStr) {
    for(auto part : inStr) {
        if(part != ' ') {
            notation_deque.insertBack(part);
        }
    }
}

//Postfix Converters
std::string NotationConverter::postfixToInfix(std::string inStr) {
    
    return "";
}

std::string NotationConverter::postfixToPrefix(std::string inStr) {

    return "";
}
//End of Postfix Converters

//Infix Converters
std::string NotationConverter::infixToPostfix(std::string inStr) {
    decodeInput(inStr);
    while(!notation_deque.emptyDeque()) {
        
    }
    return "";
}

std::string NotationConverter::infixToPrefix(std::string inStr) {

    return "";
}
//End of Postfix Converters

//Prefix Converters
std::string NotationConverter::prefixToInfix(std::string inStr) {

    return "";
}

std::string NotationConverter::prefixToPostfix(std::string inStr) {

    return "";
}
//End of Prefix  Converters