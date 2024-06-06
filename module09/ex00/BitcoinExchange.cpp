#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    // Constructor
}

BitcoinExchange::~BitcoinExchange() {
    // Destructor
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    // Copy constructor
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    // Assignment operator
    if (this != &other) {
        this->database.clear();
        std::map<std::string, float>::const_iterator it;
        for (it = other.database.begin(); it != other.database.end(); it++) {
            this->database[it->first] = it->second;
        }
    }
    return *this;
}

void BitcoinExchange::checkArgument(int ac) {
    if (ac != 2)
        throw BitcoinExchange::FileException();
}

void BitcoinExchange::extractCsv() {
    std::ifstream inFile;
    inFile.open("data.csv");
    if (!inFile)
        throw BitcoinExchange::FileException();

    std::string line;
    std::string date;
    std::string value_str;
    float value;

    // Read the header line
    std::getline(inFile, line);
    if (line != "date,exchange_rate")
        throw BitcoinExchange::FormatException();

    // Read each line and extract date and value
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::getline(iss, date, ',');
        std::getline(iss, value_str, '\n');
        std::istringstream issvalue(value_str);
        if (!(issvalue >> value)) {
            std::cout << "Failed to convert price to number." << std::endl;
            throw BitcoinExchange::StrToFloatException();
        }
        database[date] = value;
    }

    inFile.close();
}

int BitcoinExchange::validateDate(std::string date) {
    std::string year, month, day;
    int month_int, day_int;

    // Split the date into year, month, and day
    std::istringstream iss(date);
    std::getline(iss, year, '-');
    std::getline(iss, month, '-');
    std::getline(iss, day, '\0');

    // Check the length of year, month, and day
    if (year.length() != 4 || month.length() != 2 || day.length() != 2)
        return 1;

    // Check if year, month, and day contain only digits
    for (int i = 0; i < 4; i++) {
        if (!isdigit(year[i]))
            return 1;
    }
    for (int i = 0; i < 2; i++) {
        if (!isdigit(month[i]))
            return 1;
    }
    for (int i = 0; i < 2; i++) {
        if (!isdigit(day[i]))
            return 1;
    }

    // Convert month and day to integers
    iss.clear();
    iss.str(month);
    iss >> month_int;
    iss.clear();
    iss.str(day);
    iss >> day_int;

    // Check if month and day are valid
    if (month_int > 12 || day_int > 31)
        return 1;
    return 0;
}

std::string BitcoinExchange::parseNewKey(int year, int month, int day) {
    std::string year_str, month_str, day_str;
    std::string newKey;
    std::stringstream ss;
    ss << year;
    year_str = ss.str();
    ss.str("");

    ss << month;
    month_str = ss.str();
    if (month < 10)
        month_str.insert(0, "0");
    ss.str("");

    ss << day;
    day_str = ss.str();
    if (day < 10)
        day_str.insert(0, "0");
    newKey = year_str + "-" + month_str + "-" + day_str;
    return newKey;
}

std::map<std::string, float>::iterator BitcoinExchange::findClosestKey(std::string date) {
    std::string newKey = date;
    std::string year, month, day;
    int year_int, month_int, day_int;
    std::istringstream iss(newKey);
    std::getline(iss, year, '-');
    std::getline(iss, month, '-');
    std::getline(iss, day);
    std::istringstream(year) >> year_int;
    std::istringstream(month) >> month_int;
    std::istringstream(day) >> day_int;
    std::map<std::string, float>::iterator it = database.begin();
    std::string oldestEntry = it->first;
    while (newKey >= oldestEntry) {
        if (day_int > 0)
            day_int--;
        else if (month_int > 0) {
            month_int--;
            day_int = 31;
        } else {
            year_int--;
            month_int = 12;
            day_int = 31;
        }
        newKey = parseNewKey(year_int, month_int, day_int);
        it = database.find(newKey);
        if (it != database.end())
            return it;
    }
    it = database.end();
    return it;
}

void BitcoinExchange::clearUtilVars(std::string& line, std::string& date, std::string& value_str) {
    line.clear();
    date.clear();
    value_str.clear();
}

void BitcoinExchange::processInput(const char* input) {
    std::string input_str(input);

    std::ifstream inFile;
    inFile.open(input_str);
    if (!inFile)
        throw BitcoinExchange::FileException();

    std::string line, date, value_str;
    float value;
    std::map<std::string, float>::iterator it;

    // Read the header line
    std::getline(inFile, line);
    if (line != "date | value")
        throw BitcoinExchange::FormatException();

    // Read each line and process the input
    while (std::getline(inFile, line)) {
        value = 0;
        std::istringstream iss(line);
        std::getline(iss, date, '|');
        if (date[date.length() - 1] == ' ')
            date.pop_back();
        std::getline(iss, value_str, '\n');
        std::istringstream issvalue(value_str);
        if (!(issvalue >> value)) {
            std::cout << "Error: bad input => " << line << std::endl;
            clearUtilVars(line, date, value_str);
            continue;
        }
        if (validateDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            clearUtilVars(line, date, value_str);
            continue;
        } else if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            clearUtilVars(line, date, value_str);
            continue;
        } else if (value > 1000) {
            std::cout << "Error: too large number." << std::endl;
            clearUtilVars(line, date, value_str);
            continue;
        }

        it = database.find(date);
        if (it == database.end()) {
            it = findClosestKey(date);
            if (it == database.end()) {
                std::cout << "Error: date too early, no reference data." << std::endl;
                continue;
            }
        }

        std::cout << date << " => " << value << " = ";
        std::cout << std::fixed << std::setprecision(2) << it->second * value << std::endl;
        clearUtilVars(line, date, value_str);
    }

    inFile.close();
}

const char* BitcoinExchange::FileException::what() const throw() {
    return "Could not open file.";
}

const char* BitcoinExchange::StrToFloatException::what() const throw() {
    return "Failed to convert value to float.";
}

const char* BitcoinExchange::FormatException::what() const throw() {
    return "Unexpected format.";
}