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
    static int detectType(std::string);
    static void castOthers(void);
    static void printVariables(void);
    static int isChar(std::string);
    static int isInt(std::string);
    static int isFloat(std::string);
    static int isDouble(std::string);

    // Private constructors and destructor
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter(void);

public:
    // Public function
    static int convert(std::string str);
};

#endif