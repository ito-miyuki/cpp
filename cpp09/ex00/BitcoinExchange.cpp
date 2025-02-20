#include "BitcoinExchange.hpp"
#include <iostream> // temp

BitcoinExchange::BitcoinExchange(std::string fileName){
	const std::string priceDatabase = "data.csv";
	_fileOpened = true; // default
	_fileName = fileName;

	std::ifstream dataBase(priceDatabase);
	if (!dataBase.is_open()) {
		_fileOpened = false;
		std::cerr << "Error: could not open data base file" << std::endl; // can we use cerr? should this be cout?
		return ;
	}

	processData(dataBase);

}

void BitcoinExchange::processData(std::ifstream& file) {
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

void BitcoinExchange::readInput() {
	std::string line;

	std::ifstream inputFile(_fileName);
	if (!inputFile.is_open()) {
		_fileOpened = false;
		std::cerr << "Error: could not open the provided file" << std::endl; // can we use cerr? should this be cout?
		return ;
	}

	while (std::getline(inputFile, line)) {
		size_t pipePos = line.find('|');

		std::string year = "";
		std::string month = "";
		std::string date = "";
		std::string priceStr = "";
		double price = 0;

		if (pipePos == std::string::npos) {
			std::cerr << "Invalid formart in provided file" << std::endl;
		} else {
			size_t dashPos = line.find('-');
			if (dashPos != std::string::npos) {
				// "yyyy-mm-dd |"
				year = line.substr(0,4); //yyyy
				month = line.substr(dashPos + 1, 2); // "-mm-dd |"
				date = line.substr(dashPos + 4, 2); // "-mm-dd |"
				priceStr = line.substr(pipePos + 2); // "| value"

				try {
					price = stod(priceStr);
					if (price < 0 || price > 1000) {
						price = 0;
						std::cerr << "Provided value must be between 0 - 1000" << std::endl;
					}
				} catch (const std::exception& e) {
					std::cerr << "Error: " << e.what() << std::endl;
				}
			}
			//delete it
			std::cout << year << "-" << month << "-" << date << " => " << price << " = calculatedPrice here" << std::endl;
		}
	}
}


// void BitcoinExchange::calculateExchange() {

// }

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

