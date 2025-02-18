#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: ./btc <filename>" << std::endl;
		return 1;
	}

	BitcoinExchange btc(argv[1]);
	if (!btc.getFileOpened()) {
		std::cout << "Error: could not open file" << std::endl; // can we use cerr?
		return 1;
	}

	
	
	return 0;
}
