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
