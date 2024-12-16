/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:04:18 by mito              #+#    #+#             */
/*   Updated: 2024/12/16 14:23:00 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {};

Base* generate(void) {
	int result = std::rand() % 3;

	switch (result)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	case 2:
		return new C();
	default:
		return nullptr;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Type is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type is C" << std::endl;
	else
		std::cout << "Unknown Type" << std::endl;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "Type is A" << std::endl;
		(void)a;
		return ;
	} catch(std::bad_cast& ) {}; // no need error message so just & is fine (not &e)

	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "Type is B" << std::endl;
		(void)b;
		return ;
	} catch(std::bad_cast& ) {};

	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "Type is C" << std::endl;
		(void)c;
		return ;
	} catch(std::bad_cast& ) {};
}


