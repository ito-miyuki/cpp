#include "BitcoinExchange.hpp"
#include <iostream> // temp

BitcoinExchange::BitcoinExchange(){}
// BitcoinExchange::BitcoinExchange(){} // with params?
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	if (this != &other) {} // change it
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {} // change it
	return *this;
}

void BitcoinExchange::exchanger(std::string fileName){
	std::cout << "test. fileName is: " << fileName << std::endl;
}

