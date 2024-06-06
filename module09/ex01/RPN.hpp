#ifndef RPN_HPP
# define RPN_HPP

#include <stack>       // For std::stack
#include <string>      // For std::string
#include <iostream>    // For std::cout
#include <sstream>     // For std::stringstream
#include <stdexcept>   // For std::exception
#include <list>        // For std::list

class RPN {
    private:
        std::stack<float, std::list<float>> numstack;  // Stack to store numbers
        RPN(RPN const& other);                         // Copy constructor (private)
        RPN& operator=(RPN const& other);               // Assignment operator (private)
        
        // Custom exception classes
        class SyntaxException : public std::exception {
            public:
                const char* what() const throw();  // Exception message
        };
        class DivisionException : public std::exception {
            public:
                const char* what() const throw();  // Exception message
        };
        class OperandException : public std::exception {
            public:
                const char* what() const throw();  // Exception message
        };
        class TokenException : public std::exception {
            public:
                const char* what() const throw();  // Exception message
        };
        
    public:
        RPN(void);        // Constructor
        ~RPN(void);       // Destructor
        
        void calculate(std::string input);  // Function to perform RPN calculation
};

# endif