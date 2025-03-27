#pragma once
#include <stack>
#include <iostream>
#include <sstream> // for string stream
#include <algorithm> // for all_of
#include <limits> // for numeric_limits

class RPN {
	private:
		std::stack<long long> _stack;
	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

		void calculator(const std::string& str);
};
