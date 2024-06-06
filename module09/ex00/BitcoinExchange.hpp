#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cctype>

class BitcoinExchange {
    private:
        std::map<std::string, float> database; // Database to store Bitcoin exchange rates
        
        // Private copy constructor and assignment operator to prevent copying
        BitcoinExchange(BitcoinExchange const& other);
        BitcoinExchange& operator=(BitcoinExchange const& other);
        
        // Private helper functions
        int validateDate(std::string date); // Validates the format of a date string
        void clearUtilVars(std::string& line, std::string& date, std::string& value_str); // Clears utility variables
        std::map<std::string, float>::iterator findClosestKey(std::string date); // Finds the closest key in the database for a given date
        std::string parseNewKey(int year, int month, int day); // Parses a new key in the format "YYYY-MM-DD"

        // Custom exception classes
        class FileException : public std::exception {
            public:
                const char* what() const throw();
        };
        class StrToFloatException : public std::exception {
            public:
                const char* what() const throw();
        };
        class FormatException : public std::exception {
            public:
                const char* what() const throw();
        };
        
    public:
        BitcoinExchange(void); // Constructor
        ~BitcoinExchange(void); // Destructor

        void checkArgument(int ac); // Checks the number of command-line arguments
        void extractCsv(void); // Extracts data from a CSV file and populates the database
        void processInput(const char* input); // Processes user input and performs operations on the database
};

#endif