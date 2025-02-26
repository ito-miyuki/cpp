#pragma once
#include <stack>
#include <iostream>

class RPN {
	public:
		RPN();
		~RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
};
