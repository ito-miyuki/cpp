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

	for(size_t i = 0; i < str.length(); i++) {
		if (isdigit(str[i])) {
			numberCount++;
			stackCount++;
		} else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			operatorCount++;
			if (stackCount < 2) { // operator needs at least 2 numbers
				std::cerr << "Error: invalid format. Not enough numbers before operator." << std::endl; // for debugging
				return false;
			}
			stackCount--;
		} else if (str[i] == ' ') {
			continue;
		} else {
			std::cerr << "Error: it contains invalid charactor" << std::endl; // for debugging
			return false; 
		}
	}

	if (stackCount != 1 || operatorCount != numberCount - 1) {
		std::cerr << "Error: invalid format. Too many numbers or operators." << std::endl; // for debugging
		return false;
	}
	return true;
}

void RPN::calculator(const std::string& str) {
	if (!isValidInput(str)) {
		std::cerr << "Error" << std::endl;
		return ;
	}

	std::stack<int> stack;
	int result = 0;
	for (size_t i = 0; i < str.length(); i++) {
		if (isdigit(str[i])){
			int n = str[i] - '0';
			stack.push(n);
		} else if (str[i] == ' ') {
			continue;
		} else {
			int n1 = stack.top(); // take out the top one
			stack.pop();
			int n2 = stack.top();
			stack.pop();

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
					std::cerr << "Invalid char detected" << std::endl; // it might not be needed
					break;
			}
			stack.push(result);
		}
	}
	std::cout << result << std::endl;
}
