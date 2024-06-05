#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>

// Custom exception class for no match found
class NoMatchException : public std::exception {
public:
    const char* what() const throw(){
        return "No match!\0";
    }
};

// Function to find the needle in the haystack
template <typename T>
void easyfind(T haystack, int needle) {
    // Use typename to specify that it is a dependent type
    typename T::iterator it = std::find(haystack.begin(), haystack.end(), needle);
    
    // Check if needle is found
    if (it != haystack.end()) {
        // Print the position of the needle if found
        std::cout << "Found " << needle << " in position " << std::distance(haystack.begin(), it) << "!" << std::endl;
    } else {
        // Throw custom exception if no match found
        throw NoMatchException();
    }
    
    return ;
}

#endif