#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& other){
	_stack = other._stack;
}

RPN& RPN::operator=(const RPN& other){
	if (this != &other) {
		_stack = other._stack;
	}
	return *this;
}

bool isValidInput(const std::string& str) {
	int numberCount = 0;
	int operatorCount = 0;
	int stackCount = 0;

	std::stringstream ss(str);
	std::string token;

	while (ss >> token) {
		if (std::all_of(token.begin(), token.end(), ::isdigit)) {
			numberCount++;
			stackCount++;
			if (token.length() != 1) {
				std::cerr << "Error: invalid input." << std::endl;
				return false;
			}
		} else if (token == "+" || token == "-" || token == "*" || token == "/") {
			operatorCount++;
			if (stackCount < 2) { // operator needs at least 2 numbers
				std::cerr << "Error: invalid input." << std::endl;
				return false;
			}
			stackCount--;
		} else {
			std::cerr << "Error: invalid input." << std::endl;
			return false; 
		}
	}

	if (stackCount != 1 || operatorCount != numberCount - 1) {
		std::cerr << "Error: invalid input. Too many numbers or operators." << std::endl; // for debugging
		return false;
	}
	return true;
}

void RPN::calculator(const std::string& str) {
	if (!isValidInput(str)) {
		return ;
	}

	long long result = 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (isdigit(str[i])){
			long long n = str[i] - '0';
			_stack.push(n);
		} else if (str[i] == ' ') {
			continue;
		} else {
			long long n1 = _stack.top(); // take out the top one
			_stack.pop();
			long long n2 = _stack.top();
			_stack.pop();

			if (str[i] == '/' && n1 == 0) {
				std::cerr << "Error: division by zero is not allowed." << std::endl;
    			return;
			}

			switch (str[i]) {
				case '+':
					result = n2 + n1;
					break;
				case '-':
					result = n2 - n1;
					break;
				case '*':
					result = n2 * n1;
					break;
				case '/':
					result = n2 / n1;
					break;
				default:
					std::cerr << "Invalid char detected" << std::endl;
					break;
			}

			if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min()) {
				std::cerr << "Error: result overflows int range." << std::endl;
				return ;
			}
			_stack.push(result);
		}
	}
	std::cout << result << std::endl;
}
