#include <iostream>

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "Usage: ./btc <filename>" << std::endl;
		return 1;
	}
	return 0;
}
