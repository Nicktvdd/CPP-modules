#include "RPN.hpp"

RPN::RPN() {
    // Default constructor
}

RPN::~RPN() {
    // Destructor
}

RPN::RPN(const RPN& other) {
    // Copy constructor
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    // Assignment operator
    if (this != &other) {
        // Clear the current stack
        while (!numstack.empty())
            numstack.pop();

        // Copy the stack from the other object
        numstack = other.numstack;
    }
    return *this;
}

void RPN::calculate(std::string input) {
    std::string token;
    std::istringstream iss(input);
    float num1, num2, res;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Operator encountered
            if (numstack.size() < 2)
                throw RPN::SyntaxException();

            // Pop the top two numbers from the stack
            num2 = numstack.top();
            numstack.pop();
            num1 = numstack.top();
            numstack.pop();

            // Perform the operation based on the operator token
            if (token == "+") {
                res = num1 + num2;
            } else if (token == "-") {
                res = num1 - num2;
            } else if (token == "*") {
                res = num1 * num2;
            } else if (token == "/") {
                if (num2 == 0)
                    throw RPN::DivisionException();
                res = num1 / num2;
            }

            // Push the result back to the stack
            numstack.push(res);
        } else if (std::istringstream(token) >> res) {
            // Operand encountered
            if (res < -9 || res > 9)
                throw RPN::OperandException();

            // Push the operand to the stack
            numstack.push(res);
        } else {
            // Invalid token encountered
            throw RPN::TokenException();
        }
    }

    if (numstack.size() != 1)
        throw RPN::SyntaxException();

    // Print the final result
    std::cout << numstack.top() << std::endl;
}

const char* RPN::SyntaxException::what() const throw() {
    return "Syntax error.";
}

const char* RPN::DivisionException::what() const throw() {
    return "Trying to divide by zero.";
}

const char* RPN::OperandException::what() const throw() {
    return "Operand too big/small.";
}

const char* RPN::TokenException::what() const throw() {
    return "Invalid token.";
}