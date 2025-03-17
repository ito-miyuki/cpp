#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& other){
	*this = other;
}

RPN& RPN::operator=(const RPN& other){
	(void)other;
	return *this;
}

bool isValidInput(const std::string& str) {
	// for(size_t i = 0; i < str.length(); i++) {
	// 	if (!isdigit(str[i]) && str[i] != ' ' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/') {
	// 		return false;
	// 	}
	// }
	int numberCount = 0;
	int operatorCount = 0;

	for(size_t i = 0; i < str.length(); i++) {
		if (isdigit(str[i])) {
			numberCount++;
		} else if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/') {
			operatorCount++;
			if (numberCount < 2) { // operator needs at least 2 numbers
				return false;
			}
		} else if (str[i] != ' ') {
			continue;
		}
	}
	if (numberCount == 1 && operatorCount == numberCount - 1) {
		return false;
	}
	return true;
}

void RPN::calculator(const std::string& str) {
	std::cout << "You are in Calculator(). str is " << str << std::endl;
	// check if everything is digit or the symbols
	if (!isValidInput(str)) {
		std::cerr << "Error: it contains invalid charactor" << std::endl;
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
			stack.pop(); // delete it
			int n2 = stack.top();
			stack.pop();

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
			stack.push(result);
		}
	}
	std::cout << "Final result is: " << result << std::endl;
}
