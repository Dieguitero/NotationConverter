#include "NotationConverter.hpp"

bool isPrefix(std::string str) {
    return ((str.at(0) == '+') || (str.at(0) == '-') || (str.at(0) == '/') || (str.at(0) == '*'));
}
bool isCharLetter(const char& c) {
    bool islower = (c >= 'a' && c <= 'z');
    bool isupper= (c >= 'A' && c <= 'Z');
    bool isLetter = (islower || isupper);

    return isLetter;
}

bool isCharOp(const char& c) {
    bool isTimes = (c == '*');
    bool isAdd = (c == '+');
    bool isSub = (c == '-');
    bool isDivide = (c == '/');

    bool isOP = (isTimes || isAdd || isSub || isDivide);
    return isOP;
}
bool isCharInvalid(const char& c) {
    bool isLetter = isCharLetter(c);
    bool isOp = isCharOp(c);

    bool isValid = (isLetter || isOp);

    if(isValid) {
        return false; //char is valid
    }
    return true; //char is invalid
}
void NotationConverter::decodeInput(std::string inStr) {
    for(auto part : inStr) {
        if(part != ' ') { //ignoring all white space from string
            notation_deque.insertBack(part); //inserting each character into the deque
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
    decodeInput(inStr); //inserting the strings into the deque
    std::ostringstream oSS;
    while(!notation_deque.emptyDeque()) {
        if(notation_deque.front() == '(' || notation_deque.front() == ')'){
            notation_deque.removeFront();
        }
        if(isCharInvalid(notation_deque.front())) {
            notation_deque.clear();
            throw("Invalid Character In String");
        }
        if(isCharLetter(notation_deque.front())) {
            oSS << notation_deque.front();
            oSS << ' ';
            notation_deque.removeFront();
        }
        else {
            oSS << notation_deque.back();
            oSS << ' ';
            notation_deque.removeBack();
        }
        
    }
    return oSS.str();
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