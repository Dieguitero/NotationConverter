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

bool isStringInvalid(std::string str) {
    std::cout << "inside isStringInvalid" << std::endl;
    for(char c : str) {
        std::cout << "inside the for loop of isStringInvalid" << std::endl;
        bool isValid = (isCharLetter(c) || isCharOp(c) || c == ' ');
        if(!isValid) {
            std::cout << "inside the if, we should be about to return true" << std::endl;
            return true;
        }
    }
    std::cout << "outside of the for loop, about to return false" << std::endl;
    return false;
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
    return "";
}

std::string NotationConverter::infixToPrefix(std::string inStr) {

    return "";
}
//End of Postfix Converters

//Prefix Converters
std::string NotationConverter::prefixToInfix(std::string inStr) {
    std::cout << "about to check if this string is invalid: " << inStr << std::endl;
    // bool isNotValid = isStringInvalid(inStr);
    if(isStringInvalid(inStr))
        throw("Invalid String");
    std::string ret;
    reverse(inStr.begin(), inStr.end());
    for(auto c : inStr) {
        if(c == ' ') {
            continue;
        }
        else if(isCharLetter(c)) {
            std::string temp = "";
            temp += c;
            notation_deque.insertBack(temp);
        }
        else if (isCharOp(c)) {
            std::string temp = "";
            temp += '(';
            temp += notation_deque.back();
            notation_deque.removeBack();
            temp += ' ';
            temp += c;
            temp += ' ';
            temp += notation_deque.back();
            notation_deque.removeBack();
            temp += ')';
            notation_deque.insertBack(temp);
        }
    }
    while(!notation_deque.emptyDeque()) {
        ret += notation_deque.back();
        notation_deque.removeBack();
    }

    return ret;
}

std::string NotationConverter::prefixToPostfix(std::string inStr) {

    return "";
}
//End of Prefix  Converters