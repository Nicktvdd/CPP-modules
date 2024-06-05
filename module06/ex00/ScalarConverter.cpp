#include "ScalarConverter.hpp"

// Initialize static member variables
int ScalarConverter::scCharFlag = 0;
int ScalarConverter::scIntFlag = 0;
int ScalarConverter::scFloatFlag = 0;
int ScalarConverter::scDoubleFlag = 0;
char ScalarConverter::scChar = 0;
int ScalarConverter::scInt = 0;
float ScalarConverter::scFloat = 0;
double ScalarConverter::scDouble = 0;
int ScalarConverter::scType = 0;

// Constructor
ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter constructor called" << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    std::cout << "ScalarConverter copy assignment constructor called" << std::endl;
    if (this != &other) {
        // Copy member variables
        this->scCharFlag = other.scCharFlag;
        this->scIntFlag = other.scIntFlag;
        this->scFloatFlag = other.scFloatFlag;
        this->scDoubleFlag = other.scFloatFlag;
        this->scChar = other.scChar;
        this->scInt = other.scInt;
        this->scFloat = other.scFloat;
        this->scDouble = other.scDouble;
        this->scType = other.scType;
    }
    return *this;
}

// Destructor
ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter destructor called" << std::endl;
}

// Check if the string represents a char
int ScalarConverter::isChar(std::string str) {
    if (str.length() > 1)
        return 1;
    else if ((str[0] >= 0 && str[0] <= 31) || str[0] == 127) {
        std::cout << "a non displayable character: ";
        return 1;
    } else if (str[0] < '0' || str[0] > '9') {
        ScalarConverter::scChar = str[0];
        return 0;
    }
    return 1;
}

// Check if the string represents an int
int ScalarConverter::isInt(std::string str) {
    int j = 0;
    if (str[j] == '-' || str[j] == '+')
        j = 1;
    for (int i = j; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    std::istringstream iss(str);
    if (iss >> ScalarConverter::scInt)
        return 0;
    return 1;
}

// Check if the string represents a float
int ScalarConverter::isFloat(std::string str) {
    if (str[str.length() - 1] != 'f')
        return 1;
    if (str == "-inff") {
        ScalarConverter::scFloat = -INFINITY;
        return 0;
    } else if (str == "+inff") {
        ScalarConverter::scFloat = +INFINITY;
        return 0;
    } else if (str == "nanf") {
        ScalarConverter::scFloat = 0.0f / 0.0f;
        return 0;
    }
    int sign = 0;
    int dot = 0;
    int ecount = 0;
    if (str[sign] == '-' || str[sign] == '+')
        sign = 1;
    for (int i = sign; i < (int)str.length() - 1; i++) {
        if (str[i] == '.') {
            if ((sign == 0 && i == 0) || (sign == 1 && i == 1))
                return 1;
            dot++;
            continue;
        } else if (str[i] == 'e' && dot == 1) {
            if (str[i - 1] < '0' || str[i - 1] > '9' || str[i + 1] < '0' || str[i + 1] > '9') {
                if (str[i + 1] == '-' || str[i + 1] == '+') {
                    i = i + 2;
                    ecount++;
                    continue;
                }
                return 1;
            }
            ecount++;
            continue;
        }
        if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    if (dot != 1 || ecount > 1 || str[str.length() - 2] == '.')
        return 1;
    str[str.length() - 1] = '\0';
    std::istringstream iss(str);
    if (iss >> ScalarConverter::scFloat) {
        return 0;
    }
    return 1;
}

// Check if the string represents a double
int ScalarConverter::isDouble(std::string str) {
    if (str == "-inf") {
        ScalarConverter::scDouble = -INFINITY;
        return 0;
    } else if (str == "+inf") {
        ScalarConverter::scDouble = +INFINITY;
        return 0;
    } else if (str == "nan") {
        ScalarConverter::scDouble = 0.0 / 0.0;
        return 0;
    }
    int sign = 0;
    int dot = 0;
    int ecount = 0;
    if (str[sign] == '-' || str[sign] == '+')
        sign = 1;
    for (int i = sign; str[i]; i++) {
        if (str[i] == '.') {
            if ((sign == 0 && i == 0) || (sign == 1 && i == 1))
                return 1;
            dot++;
            continue;
        } else if (str[i] == 'e' && dot == 1) {
            if (str[i - 1] < '0' || str[i - 1] > '9' || str[i + 1] < '0' || str[i + 1] > '9') {
                if (str[i + 1] == '-' || str[i + 1] == '+') {
                    i = i + 2;
                    ecount++;
                    continue;
                }
                return 1;
            }
            ecount++;
            continue;
        }
        if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    if (dot != 1 || ecount > 1 || str[str.length() - 1] == '.')
        return 1;
    std::istringstream iss(str);
    if (iss >> ScalarConverter::scDouble)
        return 0;
    return 1;
}

// Detect the type of the string and return an integer representing the type
int ScalarConverter::detectType(std::string str) {
    std::cout << "Converting \"" << str << "\"" << ", which is ";
    if (!ScalarConverter::isChar(str)) {
        std::cout << "a char." << std::endl;
        return 1;
    } else if (!ScalarConverter::isInt(str)) {
        std::cout << "an int." << std::endl;
        return 2;
    } else if (!ScalarConverter::isFloat(str)) {
        std::cout << "a float." << std::endl;
        return 3;
    } else if (!ScalarConverter::isDouble(str)) {
        std::cout << "a double." << std::endl;
        return 4;
    }
    std::cout << "not a valid input. Forget about it!" << std::endl;
    return 0;
}

// Cast the other types based on the detected type
void ScalarConverter::castOthers() {
    if (scType == 1) { // from char
        ScalarConverter::scInt = static_cast<int>(ScalarConverter::scChar);
        ScalarConverter::scFloat = static_cast<float>(ScalarConverter::scChar);
        ScalarConverter::scDouble = static_cast<double>(ScalarConverter::scChar);
    } else if (scType == 2) { // from int
        if (ScalarConverter::scInt >= std::numeric_limits<char>::min() && ScalarConverter::scInt <= std::numeric_limits<char>::max())
            ScalarConverter::scChar = static_cast<char>(ScalarConverter::scInt);
        else
            ScalarConverter::scCharFlag = 1;
        if ((ScalarConverter::scChar <= 31 || ScalarConverter::scChar == 127) && ScalarConverter::scCharFlag == 0)
            ScalarConverter::scCharFlag = 2;
        ScalarConverter::scFloat = static_cast<float>(ScalarConverter::scInt);
        ScalarConverter::scDouble = static_cast<double>(ScalarConverter::scInt);
    } else if (scType == 3) { // from float
        if (ScalarConverter::scFloat >= std::numeric_limits<char>::min() && ScalarConverter::scFloat <= std::numeric_limits<char>::max())
            ScalarConverter::scChar = static_cast<char>(ScalarConverter::scFloat);
        else
            ScalarConverter::scCharFlag = 1;
        if ((ScalarConverter::scChar <= 31 || ScalarConverter::scChar == 127) && ScalarConverter::scCharFlag == 0)
            ScalarConverter::scCharFlag = 2;
        if (ScalarConverter::scFloat >= std::numeric_limits<int>::min() && ScalarConverter::scFloat <= std::numeric_limits<int>::max())
            ScalarConverter::scInt = static_cast<int>(ScalarConverter::scFloat);
        else
            ScalarConverter::scIntFlag = 1;
        ScalarConverter::scDouble = static_cast<double>(ScalarConverter::scFloat);
    } else { // from double
        if (ScalarConverter::scDouble >= std::numeric_limits<char>::min() && ScalarConverter::scDouble <= std::numeric_limits<char>::max())
            ScalarConverter::scChar = static_cast<char>(ScalarConverter::scDouble);
        else
            ScalarConverter::scCharFlag = 1;
        if ((ScalarConverter::scChar <= 31 || ScalarConverter::scChar == 127) && ScalarConverter::scCharFlag == 0)
            ScalarConverter::scCharFlag = 2;
        if (ScalarConverter::scDouble >= std::numeric_limits<int>::min() && ScalarConverter::scDouble <= std::numeric_limits<int>::max())
            ScalarConverter::scInt = static_cast<int>(ScalarConverter::scDouble);
        else
            ScalarConverter::scIntFlag = 1;
        if ((ScalarConverter::scDouble >= std::numeric_limits<float>::min() && ScalarConverter::scDouble <= std::numeric_limits<float>::max()) || std::isnan(ScalarConverter::scDouble))
            ScalarConverter::scFloat = static_cast<float>(ScalarConverter::scDouble);
        else
            ScalarConverter::scFloatFlag = 1;
    }
}

// Print the converted variables
void ScalarConverter::printVariables() {
    // PRINTING CHAR
    std::cout << "char: ";
    if (ScalarConverter::scCharFlag == 1)
        std::cout << "impossible" << std::endl;
    else if (ScalarConverter::scCharFlag == 2)
        std::cout << "non displayable" << std::endl;
    else
        std::cout << ScalarConverter::scChar << std::endl;

    // PRINTING INT
    std::cout << "int: ";
    if (ScalarConverter::scIntFlag == 1)
        std::cout << "impossible" << std::endl;
    else
        std::cout << ScalarConverter::scInt << std::endl;

    // PRINTING FLOAT
    std::cout << "float: ";
    if (ScalarConverter::scFloatFlag == 1)
        std::cout << "impossible" << std::endl;
    else {
        std::cout << ScalarConverter::scFloat;
        if (ScalarConverter::scFloat - (int)ScalarConverter::scFloat == 0)
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }

    // PRINTING DOUBLE
    std::cout << "double: " << ScalarConverter::scDouble;
    if (ScalarConverter::scDouble - (int)ScalarConverter::scDouble == 0)
        std::cout << ".0";
    std::cout << std::endl;
}

// Convert the string to different types and print the result
int ScalarConverter::convert(std::string str) {
    ScalarConverter::scType = detectType(str);
    if (ScalarConverter::scType == 0)
        return 1;
    castOthers();
    printVariables();
    return 0;
}
