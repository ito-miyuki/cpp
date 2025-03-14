#pragma once
#include <stack>
#include <iostream>

class RPN {
	private:
		std::stack<int> _stack;
	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

		static void calculator(const std::string& str);
};
