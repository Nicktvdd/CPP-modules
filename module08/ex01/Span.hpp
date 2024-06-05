#ifndef SPAN_HPP
# define SPAN_HPP

#include <stdexcept>   // For exception classes
#include <vector>      // For vector container
#include <iostream>    // For input/output streams
#include <limits>      // For numeric limits
#include <algorithm>   // For algorithms
#include <climits>     // For integer limits

class Span {
    private:
        unsigned int size;          // Size of the container
        std::vector<int> container; // Container to store numbers

    public:
        Span(void);                 // Default constructor
        Span(unsigned int N);       // Parameterized constructor
        ~Span(void);                // Destructor
        Span(Span const& other);    // Copy constructor
        Span& operator=(Span const& other); // Assignment operator

        void addNumber(int number);  // Add a single number to the container
        void addManyNumbers(unsigned int amount, int number); // Add multiple numbers to the container
        int shortestSpan();          // Calculate the shortest span between two numbers
        int longestSpan();           // Calculate the longest span between two numbers
        
        // Custom exception class for when there is no span available
        class NoSpanException : public std::exception {
            public:
                const char* what() const throw(); // Override the what() method to provide error message
        };
        
        // Custom exception class for when the container is full
        class ContainerFullException : public std::exception {
            public:
                const char* what() const throw(); // Override the what() method to provide error message
        };
};

#endif