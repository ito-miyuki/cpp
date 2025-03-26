#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string fileName){
	const std::string priceDatabase = "data.csv";
	_fileOpened = true;
	_fileName = fileName;

	std::ifstream dataBase(priceDatabase); // open the data file
	if (!dataBase.is_open()) {
		_fileOpened = false;
		std::cerr << "Error: could not open data base file" << std::endl;
		return ;
	}
	parseCSVData(dataBase);
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	exchangeRates = other.exchangeRates;
	_fileName = other._fileName;
	_fileOpened = other._fileOpened;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		exchangeRates = other.exchangeRates;
		_fileName = other._fileName;
		_fileOpened = other._fileOpened;
	}
	return *this;
}

void BitcoinExchange::parseCSVData(std::ifstream& file) {
	std::string line;

	std::getline(file, line); // skip the first line

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
			exchangeRates[date] = price;
		} catch (const std::exception& e) {
			std::cerr << "Error: invalid data format in file: " << e.what() << std::endl;
		}
	}
}

bool BitcoinExchange::isValidFormat(std::string line) {
	std::regex pattern(R"(^\d{4}-\d{2}-\d{2} \| (-?\d+(\.\d+)?)$)");
	return regex_match(line, pattern);

	/*
	R"() = syntax
	\d{n} n digits
	\| = pipe(|) symbol. do not parse as OR operator
	-? = allow negative(-) but not required
	\d+ = at least one digit
	(\.\d+)? = optional decimal part (.123)
	$ = Ensures the match extends to the end of the string
	*/
}

bool BitcoinExchange::isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		return true;
	}
	return false;
}

bool BitcoinExchange::isValidDate(int year, int month, int date) {
	if (month == 2) {
		if ((!isLeapYear(year) && date > 28) || (isLeapYear(year) && date > 29)) {
			return false;
		}
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (date > 30) {
			return false;
		}
	} else {
		if (date > 31) {
			return false;
		}
	}
	return true;
}

void BitcoinExchange::processUserInputFile() {
	std::string line;

	std::ifstream inputFile(_fileName);
	if (!inputFile.is_open()) {
		_fileOpened = false;
		std::cerr << "Error: could not open the provided file" << std::endl;
		return ;
	}
	if (std::filesystem::is_empty(_fileName)){
		std::cerr << "Error: file is empty" << std::endl;
		return ;
	}

	std::getline(inputFile, line); // skip the first line "date | value"

	while (std::getline(inputFile, line)) {
		if (!isValidFormat(line)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
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

			try {
				year = stoi(yearStr);
				month = stoi(monthStr);
				date = stoi(dateStr);
				price = stod(priceStr);

				if ((month < 1 || month > 12) || !isValidDate(year, month, date)) {
					// std::cerr << "Error: bad input => " << yearStr << "-" << monthStr << "-" << dateStr << std::endl;
					std::cerr << "Error: bad input => " << line << std::endl;
					continue ;
				} else if (price > 1000) {
					std::cerr << "Error: too large a number." << std::endl;
					continue ;
				} else if (price < 0) {
					std::cerr << "Error: not a positive number." << std::endl;
					continue ;
				}
			} catch (const std::exception& e) {
				std::cerr << "Error: " << e.what() << std::endl;
			}

			double result = calculateExchange(line, price);

			if (result == -1) {
				std::cout << "Matching data is not found." << std::endl; // for debugging
				continue;
			}
			std::cout << yearStr << "-" << monthStr << "-" << dateStr << " => " << price << " = " << result << std::endl;
		}
	}
}

std::string BitcoinExchange::findClosestDate(std::string date) {
	std::map<std::string, double>::iterator it = exchangeRates.lower_bound(date);

	if (it == exchangeRates.end()) {
		it--;
	} else if(it->first > date) {
		if (it == exchangeRates.begin()) {
			return "";
		}
		it--;
	}
	return it->first;
}

double BitcoinExchange::calculateExchange(std::string line, double value) {
	std::string inputDate = line.substr(0, 10); // yyyy-mm-dd

	std::string closestDate = findClosestDate(inputDate);
	if (closestDate.empty()) {
		return -1;
	}

	double btcPrice = exchangeRates[closestDate];
	return btcPrice * value;
}

bool BitcoinExchange::getFileOpened() {
	return _fileOpened;
}