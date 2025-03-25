#pragma once
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include <regex>
#include <filesystem>
#include <iostream>

class BitcoinExchange {
	private:
		std::map<std::string, double> exchangeRates;
		std::string _fileName;
		bool _fileOpened;

	public:
		BitcoinExchange(std::string fileName);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void parseCSVData(std::ifstream& file);
		bool getFileOpened();
		double calculateExchange(std::string line, double value);
		void processUserInputFile();

		bool isValidFormat(std::string line);
		std::string findClosestDate(std::string date);
		bool isLeapYear(int year);
		bool isValidDate(int year, int month, int date);
};
