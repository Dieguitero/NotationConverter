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

int pemdas(char op) {
    switch(op) {
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        default:
            return 0;
    }
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
    std::string ret;
    for(auto c : inStr) {
        if(c == ' ') {
            continue;
        }
        else if(isCharLetter(c)) {
            std::string temp = "";
            temp += c;
            notation_deque.insertFront(temp);
        }
        else if (isCharOp(c)) {
            std::string temp = "";
            temp += ')';
            temp += notation_deque.front();
            notation_deque.removeFront();
            temp += ' ';
            temp += c;
            temp += ' ';
            temp += notation_deque.front();
            notation_deque.removeFront();
            temp += '(';
            notation_deque.insertFront(temp);
        }
        else {
            throw("InvalidString");
        }
    }
    while(!notation_deque.emptyDeque()) {
        ret += notation_deque.front();
        notation_deque.removeFront();
    }
    
    reverse(ret.begin(), ret.end());
    return ret;
}

std::string NotationConverter::postfixToPrefix(std::string inStr) {

    return "";
}
//End of Postfix Converters

//Infix Converters
std::string NotationConverter::infixToPostfix(std::string inStr) {
    std::string ret;
    std::string endFlag = "end";
    notation_deque.insertBack(endFlag);
    for(auto c : inStr) {
        if (c == ' ') {
            continue;
        }
        else if(isCharLetter(c)) {
            ret += c;
            ret += ' ';
        }
        else if (c == '(') {
            std::string temp = "";
            temp += c;
            notation_deque.insertFront(temp);
        }
        else if (c == ')') {
            while(notation_deque.front() != endFlag && notation_deque.front() != "(") {
                std::string temp = "";
                temp = notation_deque.front();
                notation_deque.removeFront();
                ret += temp;
                ret += ' ';
            }
            if(notation_deque.front() == "("){
                notation_deque.removeFront();
            }
        }
        else if(isCharOp(c)) { //else if(isCharOp(c))
            while(notation_deque.front() != endFlag && pemdas(c) <= pemdas(notation_deque.front().at(0))) {
                std::string temp = notation_deque.front();
                notation_deque.removeFront();
                ret += temp;
                ret += ' ';
            }
            std::string strToInsert = "";
            strToInsert += c;
            notation_deque.insertFront(strToInsert);
        }
    }

    while(notation_deque.front() != endFlag) {
        std::string temp = "";
        temp = notation_deque.front();
        notation_deque.removeFront();
        ret += temp;
        ret += ' ';
    }
    return ret;
}

std::string NotationConverter::infixToPrefix(std::string inStr) {
    std::string ret = "";
    std::string temp = "";

    for(auto c : inStr) {
        temp += c;
    }

    for (unsigned int i = 0; i < temp.length(); i++) {
        if(temp.at(i) == '(') {
            temp.at(i) = ')';
        }
        else if (temp.at(i) == ')') {
            temp.at(i) = '(';
        }
    }

    reverse(temp.begin(), temp.end());
    ret = infixToPostfix(temp);
    reverse(ret.begin(), ret.end());

    return ret;
}
//End of Postfix Converters

//Prefix Converters
std::string NotationConverter::prefixToInfix(std::string inStr) {
    std::cout << "about to check if this string is invalid: " << inStr << std::endl;
    
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
        else {
            throw("InvalidString");
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