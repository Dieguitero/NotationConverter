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

bool isStringInvalid(const std::string& str) {
    for(auto c : str) {
        if(!(isCharLetter(c) || isCharOp(c))) {
            return true;
        }
    }
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
    std::string ret;
    reverse(inStr.begin(), inStr.end());
    for(auto c : inStr) {
        if(c == ' ') {
            continue;
        }
        else if(isCharLetter(c)) {
            std::string str = "";
            str += c;
            notation_deque.insertBack(str);
        }
        else if (isCharOp(c)) {
            std::string temp = "";
            temp += notation_deque.back();
            notation_deque.removeBack();
            temp += c;
            temp += notation_deque.back();
            notation_deque.removeBack();
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