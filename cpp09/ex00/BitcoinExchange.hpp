#pragma once
#include <map>
#include <string>
#include <fstream>

class BitcoinExchange {
	private:
		std::map<std::string, double> btcPrices;
		std::string _fileName;
		bool _fileOpened;

	public:
		BitcoinExchange(std::string filename);
		// BitcoinExchange(); // without params?
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		void processFileData(std::ifstream& file);

		bool getFileOpened();
};
