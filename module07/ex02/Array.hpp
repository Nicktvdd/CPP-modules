#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
    private:
        unsigned int arrsize; // Size of the array
        T* arr; // Pointer to the array

    public:
        Array(void); // Default constructor
        Array(unsigned int n); // Parameterized constructor
        ~Array(void); // Destructor
        Array(Array const& other); // Copy constructor

        Array& operator=(Array const& other); // Copy assignment operator
        T& operator[](unsigned int n); // Indexing operator
        T const & operator[](unsigned int n) const; // Const indexing operator
        
        unsigned int size(void) const; // Get the size of the array

        class OutOfBoundsException : public std::exception { // Exception class for out of bounds access
            public:
                const char* what() const throw(); // Exception message
        };
};

template <typename T>
Array<T>::Array(void) {
    std::cout << "Array(void) constructor called" << std::endl;
    this->arrsize = 0;
    this->arr = nullptr; // Initialize the pointer to nullptr
    return ;
}

template <typename T>
Array<T>::Array(unsigned int n) {
    std::cout << "Array(unsigned int n) constructor called" << std::endl;
    this->arrsize = n;
    this->arr = new T[n]; // Allocate memory for the array
    return ;
}

template <typename T>
Array<T>::~Array(void) {
    std::cout << "Array destructor called" << std::endl;
    if (this->arr)
        delete[] this->arr; // Deallocate memory for the array
    return ;
}

template <typename T>
Array<T>::Array(Array const& other) {
    std::cout << "Array copy constructor called" << std::endl;
    this->arr = nullptr; // Initialize the pointer to nullptr
    *this = other; // Call the copy assignment operator
    return ;
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& other) {
    std::cout << "Array copy assignment constructor called" << std::endl;
    if (this != &other) {
        this->arrsize = other.size();
        if (this->arr != nullptr)
            delete[] arr; // Deallocate memory for the existing array
        this->arr = new T[arrsize]; // Allocate memory for the new array
        for (unsigned int i = 0; i < other.size(); i++)
            this->arr[i] = other.arr[i]; // Copy elements from the other array
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int n) {
    if (n >= this->arrsize || n < 0)
        throw Array<T>::OutOfBoundsException(); // Throw an exception for out of bounds access
    return (this->arr[n]);
}

template <typename T>
T const & Array<T>::operator[](unsigned int n) const{
    if (n >= this->arrsize || n < 0)
        throw Array<T>::OutOfBoundsException(); // Throw an exception for out of bounds access
    return (this->arr[n]);
}

template <typename T>
unsigned int Array<T>::size(void) const {
    return (this->arrsize);
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    return ("You are trying to access non-allocated memory! :(\0"); // Exception message
}

#endif