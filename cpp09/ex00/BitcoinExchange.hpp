#pragma once
#include <map>
#include <string>

class BitcoinExchange {
	private:
		std::map<std::string, double> data;

	public:
		BitcoinExchange();
		// BitcoinExchange(); // with params?
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void exchanger(std::string fileName);
};
