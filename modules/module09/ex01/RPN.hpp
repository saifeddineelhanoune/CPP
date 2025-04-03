#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cctype>

class RPN {
private:
    std::stack<int> operandStack;
    
    bool isOperator(const char c);
    void performOperation(const char op);
    
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();
    
    int calculate(const std::string& expression);
};

#endif 