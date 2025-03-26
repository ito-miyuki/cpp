#pragma once
#include <stack>
#include <iostream>

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
