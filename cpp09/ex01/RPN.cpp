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
	for(size_t i = 0; i < str.length(); i++) {
		if (!isdigit(str[i]) && str[i] != ' ' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/') {
			return false;
		}
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
	std::cout << "Input doesn't contain any invalid chars" << std::endl; // delete it
}