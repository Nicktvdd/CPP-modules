#include "iter.hpp"
#include <string>
#include <iostream>

// Define a class called Awesome
class Awesome
{
public:
    Awesome( void ) : _n( 42 ) { return; } // Constructor that initializes _n to 42
    int get( void ) const { return this->_n; } // Getter function for _n
private:
    int _n; // Private member variable _n
};

// Overload the << operator for the Awesome class
std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
    o << rhs.get(); // Output the value of _n
    return o;
}

// Template function to print the value of any type
template< typename T >
void print( T& x )
{
    std::cout << x << std::endl; // Output the value followed by a newline
    return;
}

int main() {
    int tab[] = { 0, 1, 2, 3, 4 }; // Array of integers
    Awesome tab2[5]; // Array of Awesome objects

    iter( tab, 5, print<const int> ); // Call iter function with array of integers
    iter( tab2, 5, print<Awesome> ); // Call iter function with array of Awesome objects

    return 0;
}