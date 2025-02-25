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
			std::cerr << "Error: invalid data format in file: " << e.what() << std::endl;
		}
	}
	// delete them below
	// std::map<std::string, double>::iterator it;
	// for (it = btcPrices.begin(); it != btcPrices.end(); ++it) {
	// 		std::cout << "Date: " << it->first << ", Price: " << it->second << std::endl;
	// }
}

bool BitcoinExchange::isValidFormat(std::string& line) {
	int countPipe = 0;
	int countDash = 0;
	for (size_t i = 0; i < line.length(); i++) {
		if (line[i] == '|') {
			countPipe++;
		} else if (line[i] == '-') {
			countDash++;
		}
	}
	if (countPipe != 1 || countDash != 2) {
		return false;
	}
	// yyyy-mm-dd | value
	if (line.length() < 13 || line[4] != '-' || line[7] != '-' 
		|| line[11] != '|' || line[10] != ' ' || line[12] != ' ') {
		return false;
	}
	return true;
}

// does this have to belong to Class??
bool isValidData(std::string year, std::string month, std::string date, std::string price) {
	for (size_t i = 0; i < year.length(); i++) {
		if (!isdigit(year[i])) {
			std::cerr << "Data contains non digit char" << std::endl; // for testing, delete it
			return false;
		}
	}
	for (size_t i = 0; i < month.length(); i++) {
		if (!isdigit(month[i])) {
			std::cerr << "Data contains non digit char" << std::endl; // for testing, delete it
			return false;
		}
	}
	for (size_t i = 0; i < date.length(); i++) {
		if (!isdigit(date[i])) {
			std::cerr << "Data contains non digit char" << std::endl; // for testing, delete it
			return false;
		}
	}
	for (size_t i = 0; i < price.length(); i++) {
		if (!isdigit(price[i]) && price[i] != '.') {
			std::cerr << "Data contains non digit char" << std::endl; // for testing, delete it
			return false;
		}
	}
	return true;
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
		if (!isValidFormat(line)) {
			std::cerr << "Invalid formart in provided file" << std::endl;
		} else {

			std::string yearStr = "";
			std::string monthStr = "";
			std::string dateStr = "";
			std::string priceStr = "";
			int year = 0;
			int month = 0;
			int date = 0;
			double price = 0;
			// yyyy-mm-dd | value
			yearStr = line.substr(0,4); //yyyy
			monthStr = line.substr(5, 2); // "-mm-dd |"
			dateStr = line.substr(8, 2); // "-mm-dd |"
			priceStr = line.substr(13); // "| value"

			if (isValidData(yearStr, monthStr, dateStr, priceStr)) {
				try {
				year = stoi(yearStr);
				month = stoi(monthStr);
				date = stoi(dateStr);
				price = stod(priceStr);

				// add correct error handlings
				if ((month < 1 || month > 12) || (date < 1 || date > 31)) {
					std::cerr << "Error: bad input " << yearStr << "-" << monthStr << "-" << dateStr << std::endl;
					continue ;
				} else if ((price < 0 || price > 1000)) {
					std::cerr << "Error: too large a number. " << std::endl;
					continue ;
				}
				} catch (const std::exception& e) {
				std::cerr << "Error: " << e.what() << std::endl;
				}
				double result = calculateExchange(line, price);
				// for testing. //delete it
				std::cout << "for testing: " << year << std::endl;
				std::cout << yearStr << "-" << monthStr << "-" << dateStr << " => " << price << " = " << result << std::endl;
			}
		}
	}
}

std::string BitcoinExchange::findClosestDate(std::string date) {
	auto it = btcPrices.lower_bound(date);

	if (it == btcPrices.end()) {
		it--;
	} else if(it->first > date) {
		if (it == btcPrices.begin()) {
			std::cerr << "There is no smaller date than you provided" << std::endl; // delet it
			return "";
		}
		it--; 
	}
	return it->first;
}

double BitcoinExchange::calculateExchange(std::string line, double value) {
	std::string inputDate = line.substr(0, 10); // yyyy-mm-dd
	std::cout << "input date is: " << inputDate << std::endl;

	std::string closestDate = findClosestDate(inputDate);
	std::cout << "closest date is: " << closestDate << std::endl;
	if (closestDate.empty()) {
		std::cout << "Matching data is not found." << std::endl; // delete it 
	}

	double btcPrice = btcPrices[closestDate];
	std::cout << "btcPrice is: $" << btcPrice << std::endl; // delete it
	std::cout << "value is: $" << value << std::endl; // delete it
	return btcPrice * value;	
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

