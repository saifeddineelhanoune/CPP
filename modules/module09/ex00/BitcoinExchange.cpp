#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    loadDatabase(dbFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        this->database = other.database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }
    
    std::string line;
    // Skip header line
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        size_t delimiterPos = line.find(',');
        if (delimiterPos != std::string::npos) {
            std::string date = line.substr(0, delimiterPos);
            std::string valueStr = line.substr(delimiterPos + 1);
            
            // Convert value to double
            double value = std::atof(valueStr.c_str());
            database[date] = value;
        }
    }
    
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& date) {
    // Basic format check: YYYY-MM-DD
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    
    // Extract year, month, day
    int year, month, day;
    std::istringstream iss(date);
    char dash1, dash2;
    iss >> year >> dash1 >> month >> dash2 >> day;
    
    // Check valid ranges
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    
    // Check month-specific day limits
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }
    
    // February special case
    if (month == 2) {
        // Leap year check
        bool isLeapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if ((isLeapYear && day > 29) || (!isLeapYear && day > 28)) {
            return false;
        }
    }
    
    return true;
}

bool BitcoinExchange::isValidValue(const double value) {
    return value >= 0 && value <= 1000;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) {
    std::map<std::string, double>::iterator it = database.lower_bound(date);
    
    // If exact match or nothing smaller
    if (it != database.end() && it->first == date) {
        return date;
    }
    
    // If no date is smaller than the input date, return empty string
    if (it == database.begin() && it->first > date) {
        return "";
    }
    
    // If we need to go back to find the closest lower date
    if (it == database.end() || it->first > date) {
        --it;
    }
    
    return it->first;
}

void BitcoinExchange::processInputFile(const std::string& inputFile) {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    // Skip header line
    std::getline(file, line);
    
    while (std::getline(file, line)) {
        size_t delimiterPos = line.find('|');
        if (delimiterPos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string dateStr = line.substr(0, delimiterPos);
        std::string valueStr = line.substr(delimiterPos + 1);
        
        // Trim whitespace
        dateStr.erase(0, dateStr.find_first_not_of(" \t"));
        dateStr.erase(dateStr.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
        
        // Validate date
        if (!isValidDate(dateStr)) {
            std::cerr << "Error: bad input => " << dateStr << std::endl;
            continue;
        }
        
        // Convert and validate value
        char* endptr;
        double value = std::strtod(valueStr.c_str(), &endptr);
        
        if (valueStr.empty() || *endptr != '\0') {
            std::cerr << "Error: not a valid number." << std::endl;
            continue;
        }
        
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        
        // Find exchange rate
        std::string closestDate = findClosestDate(dateStr);
        if (closestDate.empty()) {
            std::cerr << "Error: no data available for this date." << std::endl;
            continue;
        }
        
        double exchangeRate = database[closestDate];
        double result = value * exchangeRate;
        
        // Display result
        std::cout << dateStr << " => " << value << " = " << result << std::endl;
    }
    
    file.close();
} 