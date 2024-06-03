#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

// Function to print the value of the argument
template <typename T>
void printer(T& arg) {
    std::cout << arg << std::endl;
}

// Function to increment the value of the argument by one
template <typename T>
void plusone(T& arg) {
    arg++;
}

// Function to iterate over an array and apply a function to each element
template <typename T>
void iter(T* arr, int arrlen, void (*func)(T& arg)) {
    for (int i = 0; i < arrlen; i++) {
        func(arr[i]);
    }
}

// Function to iterate over an array and apply a function to each element (const version)
template <typename T>
void iter(T* arr, int arrlen, void (*func)(T const& arg)) {
    for (int i = 0; i < arrlen; i++) {
        func(arr[i]);
    }
}

#endif
