#include "BitcoinExchange.hpp"
#include <iostream> // temp

BitcoinExchange::BitcoinExchange(std::string filename){
	const std::string priceDatabase = "data.csv";
	_fileOpened = true; // default


	std::ifstream dataBase(priceDatabase);
	if (!dataBase.is_open()) {
		_fileOpened = false;
		std::cerr << "Error: could not open data base file" << std::endl; // can we use cerr? should this be cout?
		return ;
	}

	processData(dataBase);

	std::ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		_fileOpened = false;
		std::cerr << "Error: could not open the provided file" << std::endl; // can we use cerr? should this be cout?
		return ;
	}

	_fileName = filename;
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

