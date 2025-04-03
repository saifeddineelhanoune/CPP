#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        this->operandStack = other.operandStack;
    }
    return *this;
}

RPN::~RPN() {
}

bool RPN::isOperator(const char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void RPN::performOperation(const char op) {
    if (operandStack.size() < 2) {
        throw std::runtime_error("Error: insufficient operands");
    }
    
    int b = operandStack.top();
    operandStack.pop();
    int a = operandStack.top();
    operandStack.pop();
    
    switch (op) {
        case '+':
            operandStack.push(a + b);
            break;
        case '-':
            operandStack.push(a - b);
            break;
        case '*':
            operandStack.push(a * b);
            break;
        case '/':
            if (b == 0) {
                throw std::runtime_error("Error: division by zero");
            }
            operandStack.push(a / b);
            break;
    }
}

int RPN::calculate(const std::string& expression) {
    // Clear stack for new calculation
    while (!operandStack.empty()) {
        operandStack.pop();
    }
    
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        // Check if token is an operator
        if (token.length() == 1 && isOperator(token[0])) {
            performOperation(token[0]);
        }
        // Check if token is a digit (0-9)
        else if (token.length() == 1 && std::isdigit(token[0])) {
            operandStack.push(token[0] - '0');
        }
        else {
            throw std::runtime_error("Error: invalid token");
        }
    }
    
    if (operandStack.size() != 1) {
        throw std::runtime_error("Error: invalid expression format");
    }
    
    return operandStack.top();
} 