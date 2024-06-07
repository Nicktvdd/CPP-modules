#include "PmergeMe.hpp"

int main(int ac, char** av) {
    // Check if there are command line arguments
    if (ac == 1) {
        // Print usage instructions if no arguments are provided
        std::cout << "usage: " << av[0] << " 3 5 9 7 4" << std::endl;
        std::cout << "replace nums w positive ints" << std::endl;
        return 1;
    }

    // Create an instance of PmergeMe class for input validation
    PmergeMe inputCheck;
    try {
        // Fill the vector with command line arguments
        inputCheck.fillVec(av);
        // Print the vector
        inputCheck.printVector(3);
    } catch (std::exception& e) {
        // Catch and handle any exceptions that occur during input validation
        std::cout << "Caught an error: " << e.what() << std::endl;
        return 1;
    }

    // Create an instance of PmergeMe class for sorting
    PmergeMe sorter;
    try {
        // Process the vector
        sorter.processVec(av);
        // Process the deque
        sorter.processDeq(av);
    } catch (std::exception& e) {
        // Catch and handle any exceptions that occur during sorting
        std::cout << "Caught an error: " << e.what() << std::endl;
    }

    // Print the sorted vector
    sorter.printVector(2);
    // Print the sorted deque
    sorter.printDeque(2);
    // Print the processing times
    sorter.printTimes();

    return 0;
}