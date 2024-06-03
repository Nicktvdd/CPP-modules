#include <iostream>
#include <string>
#include "Swap.hpp"
#include "Min.hpp"
#include "Max.hpp"

int main(void) {
    // Initialize variables
    int a = 42;
    int b = 666;
    std::string c = "ccc";
    std::string d = "ddd";

    // Swap integers
    std::cout << "********** swap(); **********" << std::endl;
    std::cout << "INT..." << std::endl;
    std::cout << "BEFORE SWAP: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "AFTER SWAP: a = " << a << ", b = " << b << std::endl << std::endl;

    // Swap strings
    std::cout << "STRING..." << std::endl;
    std::cout << "BEFORE SWAP: c = " << c << ", d = " << d << std::endl;
    swap(c, d);
    std::cout << "AFTER SWAP: c = " << c << ", d = " << d << std::endl;

    // Find minimum value
    std::cout << std::endl << "********** min(); **********" << std::endl;
    std::cout << "INT..." << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) return value: " << min(a, b) << std::endl;

    std::cout << std::endl << "STRING..." << std::endl;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) return value: " << min(c, d) << std::endl;

    // Find maximum value
    std::cout << std::endl << "********** max(); **********" << std::endl;
    std::cout << "INT..." << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "max(a, b) return value: " << max(a, b) << std::endl;

    std::cout << std::endl << "STRING..." << std::endl;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "max(c, d) return value: " << max(c, d) << std::endl;

    return 0;
}