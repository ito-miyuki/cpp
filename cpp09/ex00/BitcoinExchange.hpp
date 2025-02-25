#pragma once
#include <map>
#include <string>
#include <fstream>
#include <algorithm> // are we allowed to use?

class BitcoinExchange {
	private:
		std::map<std::string, double> btcPrices;
		std::string _fileName;
		bool _fileOpened;

	public:
		BitcoinExchange(std::string fileName);
		// BitcoinExchange(); // without params?
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		void processData(std::ifstream& file);

		bool getFileOpened();

		double calculateExchange(std::string line, double value);
		void readInput();
		bool isValidFormat(std::string& line);
};
