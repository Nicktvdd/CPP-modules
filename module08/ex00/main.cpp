#include "Easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <stdexcept>

int main(void) {
    // Using std::vector
    std::cout << "* * * std::vector * * *" << std::endl;
    std::vector<int> intvector;
    for (int i = 0; i < 1000; i++) {
        intvector.push_back(i);
    }
    try {
        // Searching for elements in the vector
        easyfind(intvector, 42);
        easyfind(intvector, 999);
        easyfind(intvector, 1000);
        easyfind(intvector, -42);
    } catch (std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "* * * std::deque * * *" << std::endl;
    std::deque<int> intdeque;
    for (int i = 0; i < 1000; i++) {
        if (i % 2 == 0)
            intdeque.push_back(i);
        else
            intdeque.push_front(i);
    }
    try {
        // Searching for elements in the deque
        easyfind(intdeque, 42);
        easyfind(intdeque, 999);
        easyfind(intdeque, 1000);
        easyfind(intdeque, -42);
    } catch (std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    
    std::cout << std::endl << "* * * std::list * * *" << std::endl;
    std::list<int> intlist;
    for (int i = 0; i < 1000; i++) {
        if (i % 3 == 0)
            intlist.insert(intlist.end(), i);
        else
            intlist.insert(intlist.begin(), i);
    }
    try {
        // Searching for elements in the list
        easyfind(intlist, 42);
        easyfind(intlist, 999);
        easyfind(intlist, 1000);
        easyfind(intlist, -42);
    } catch (std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    return (0);
}