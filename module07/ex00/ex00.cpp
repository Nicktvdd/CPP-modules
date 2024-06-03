#include <iostream>
#include <string>
#include "Swap.hpp"
#include "Min.hpp"
#include "Max.hpp"

class Awesome {
public:
    Awesome(void) : _n(0) {} // Default constructor
    Awesome(int n) : _n(n) {} // Constructor with parameter
    Awesome& operator=(Awesome& a) { _n = a._n; return *this; } // Assignment operator
    bool operator==(Awesome const& rhs) const { return (_n == rhs._n); } // Equality operator
    bool operator!=(Awesome const& rhs) const { return (_n != rhs._n); } // Inequality operator
    bool operator>(Awesome const& rhs) const { return (_n > rhs._n); } // Greater than operator
    bool operator<(Awesome const& rhs) const { return (_n < rhs._n); } // Less than operator
    bool operator>=(Awesome const& rhs) const { return (_n >= rhs._n); } // Greater than or equal to operator
    bool operator<=(Awesome const& rhs) const { return (_n <= rhs._n); } // Less than or equal to operator
    int get_n() const { return _n; } // Getter function for _n

private:
    int _n; // Private member variable
};

std::ostream& operator<<(std::ostream& o, const Awesome& a) { o << a.get_n(); return o; } // Overloaded output stream operator

int main(void) {
    Awesome a(2), b(4);

    swap(a, b); // Swap the values of a and b
    std::cout << a << " " << b << std::endl; // Print the values of a and b
    std::cout << max(a, b) << std::endl; // Print the maximum value between a and b
    std::cout << min(a, b) << std::endl; // Print the minimum value between a and b

    return 0;
}