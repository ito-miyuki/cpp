#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: invalid input." << std::endl;
		std::cerr << "Usage example: ./RPN \"7 7 * 7 -\"" << std::endl;
		return 1;
	}
	RPN::calculator(argv[1]);
	return 0;
}
