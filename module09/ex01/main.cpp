#include "RPN.hpp"

int main(int ac, char** av) {
    // Create an instance of the RPN calculator
    RPN calculator;

    // Check if the correct number of command-line arguments is provided
    if (ac != 2) {
        std::cout << "usage: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
        return 1;
    }

    // Get the input expression from the command-line argument
    std::string input = av[1];

    try {
        // Calculate the result of the input expression using the RPN calculator
        calculator.calculate(input);
    } catch (std::exception& e) {
        // Handle any exceptions that occur during the calculation
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}