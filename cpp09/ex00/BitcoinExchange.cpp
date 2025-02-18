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
	processFileData(file);
}

void BitcoinExchange::processFileData(std::ifstream& file) {
	std::string line;

	while (std::getline(file, line)) {
		size_t commaPos = line.find(',');

		std::string priceStr = "";
		std::string date = "";
		if (commaPos != std::string::npos) {
			date = line.substr(0, commaPos);
			priceStr = line.substr(commaPos + 1);
		}

		double price = 0;
		try {
			price = stod(priceStr);
			btcPrices[date] = price;
		} catch (const std::exception& e) {
			std::cerr << "Error: invalid data format in file" << e.what() << std::endl;
		}
	}
	// delete them below
	std::map<std::string, double>::iterator it;
	for (it = btcPrices.begin(); it != btcPrices.end(); ++it) {
			std::cout << "Date: " << it->first << ", Price: " << it->second << std::endl;
	}
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

bool BitcoinExchange::getFileOpened() {
	return _fileOpened;
}

