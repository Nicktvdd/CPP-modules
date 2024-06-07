#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <stdexcept>
#include <sstream>
#include <cctype>
#include <ctime>

class PmergeMe {
private:
    std::vector<int> vec; // Vector to store integers
    std::deque<int> deq; // Deque to store integers
    clock_t vecStart, vecEnd, deqStart, deqEnd; // Clock variables to measure time
    double vecTime, deqTime, ticks; // Time variables
    
    // Private copy constructor and assignment operator to prevent copying
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    
    // Helper functions for vector operations
    void mergeVec(std::vector<int>& myVec, std::vector<int>& left, std::vector<int>& right);
    void insertionSortVec(std::vector<int>& myVec, int vecsize);
    void mergeInsertionSortVec(std::vector<int>& myVec);
    
    // Helper functions for deque operations
    void mergeDeq(std::deque<int>& myDeq, std::deque<int>& left, std::deque<int>& right);
    void insertionSortDeq(std::deque<int>& myDeq, int deqsize);
    void mergeInsertionSortDeq(std::deque<int>& myDeq);
    
    // Custom exception classes
    class IntegerException : public std::exception {
    public:
        const char* what() const throw();
    };
    class DigitException : public std::exception {
    public:
        const char* what() const throw();
    };
    class ConversionException : public std::exception {
    public:
        const char* what() const throw();
    };
    
public:
    PmergeMe(void); // Constructor
    ~PmergeMe(void); // Destructor

    // Functions to fill the vector and deque with integers
    void fillVec(char** input);
    void fillDeq(char** input);
    
    // Functions to print the vector and deque
    void printVector(int flag);
    void printDeque(int flag);
    
    // Function to print the execution times
    void printTimes(void);
    
    // Functions to process the vector and deque
    void processVec(char** input);
    void processDeq(char** input);
};

#endif