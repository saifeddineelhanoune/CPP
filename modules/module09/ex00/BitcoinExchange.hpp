#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <limits>

class BitcoinExchange {
private:
    std::map<std::string, double> database;
    
    bool isValidDate(const std::string& date);
    bool isValidValue(const double value);
    std::string findClosestDate(const std::string& date);
    void loadDatabase(const std::string& filename);
    
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& dbFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    void processInputFile(const std::string& inputFile);
};

#endif 