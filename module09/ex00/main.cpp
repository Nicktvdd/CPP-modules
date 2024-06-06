#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
    // Create an instance of the BitcoinExchange class
    BitcoinExchange BtcEx;
    
    try {
        // Check the command line argument count
        BtcEx.checkArgument(ac); 
        
        // Extract data from a CSV file
        BtcEx.extractCsv();
        
        // Process the input using the provided argument
        BtcEx.processInput(av[1]);
    } catch (std::exception& e) {
        // Catch any exceptions and display the error message
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}