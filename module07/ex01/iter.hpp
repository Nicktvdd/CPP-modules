#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void printer(T& arg) {
    std::cout << arg << std::endl;
}

template <typename T>
void plusone(T& arg) {
    arg++;
}

template <typename T>
void iter(T* arr, int arrlen, void (*func)(T& arg)) {
    for (int i = 0; i < arrlen; i++) {
        func(arr[i]);
    }
}

template <typename T>
void iter(T* arr, int arrlen, void (*func)(T const& arg)) {
    for (int i = 0; i < arrlen; i++) {
        func(arr[i]);
    }
}

#endif
