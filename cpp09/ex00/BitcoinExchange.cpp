#include "BitcoinExchange.hpp"
#include <iostream> // temp

BitcoinExchange::BitcoinExchange(std::string filename){
	std::ifstream file(filename);
	if (!file.is_open()) {
		_fileOpened = false;
		return ;
	}

	_fileOpened = true;
	_fileName = filename;
}

// BitcoinExchange::BitcoinExchange(){} // without params?
BitcoinExchange::~BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	if (this != &other) {} // change it
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {} // change it
	return *this;
}

// void BitcoinExchange::exchanger(std::string fileName){
// 	std::cout << "test. fileName is: " << fileName << std::endl;
// }

bool BitcoinExchange::getFileOpened() {
	return _fileOpened;
}

