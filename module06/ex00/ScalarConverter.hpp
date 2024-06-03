#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <complex>

class ScalarConverter {
private:
    // Flags
    static int scCharFlag; // 0 == okay, 1 == impossible, 2 == non disp.
    static int scIntFlag; // 0 == okay, 1 == impossible
    static int scFloatFlag; // 0 == okay, 1 == impossible
    static int scDoubleFlag; // 0 == okay, 1 == impossible

    // Variables
    static char scChar;
    static int scInt;
    static float scFloat;
    static double scDouble;
    static int scType; //1 == char, 2 == int, 3 == float, 4 == double, 5 == TROUBLE :(

    // Private functions
    static int detectType(std::string); // Detects the type of the input string
    static void castOthers(void); // Casts the input string to other types
    static void printVariables(void); // Prints the converted variables
    static int isChar(std::string); // Checks if the input string can be converted to char
    static int isInt(std::string); // Checks if the input string can be converted to int
    static int isFloat(std::string); // Checks if the input string can be converted to float
    static int isDouble(std::string); // Checks if the input string can be converted to double

    // Private constructors and destructor
    ScalarConverter(void); // Default constructor
    ScalarConverter(const ScalarConverter& other); // Copy constructor
    ScalarConverter& operator=(const ScalarConverter& other); // Assignment operator
    ~ScalarConverter(void); // Destructor

public:
    // Public function
    static int convert(std::string str); // Converts the input string to different types
};

#endif