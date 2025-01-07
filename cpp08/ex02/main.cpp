/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:48:33 by mito              #+#    #+#             */
/*   Updated: 2025/01/07 14:32:13 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void testList() {
	std::list<int> mlist;
	mlist.push_back(5); // add an element to the top
	mlist.push_back(17);
	std::cout << mlist.back() << std::endl; // print out the top element by using back(17)
	mlist.pop_back(); // remove an element from the top (17)
	std::cout << mlist.size() << std::endl; // print out the size (1)
	mlist.push_back(3); // add 3
	mlist.push_back(5); // add 5
	mlist.push_back(737); // add 737

	mlist.push_back(0); // add 0

	// current stack is [0, 737, 5, 3, 5]

	std::list<int>::iterator it = mlist.begin(); // it = 5 because his->c.begin() point the first added element
	std::list<int>::iterator ite = mlist.end(); // ite points next to 0(last element)

	++it; // it became 3
	--it; // it became 5 again

	while (it != ite)
	{
	std::cout << *it << std::endl; // print out from 5
	++it;
	}
}

int main()
{
	MutantStack<int> mstack;
	mstack.push(5); // add an element to the top
	mstack.push(17);
	std::cout << mstack.top() << std::endl; // print out the top element (17)
	mstack.pop(); // remove an element from the top (17)
	std::cout << mstack.size() << std::endl; // print out the size (1)
	mstack.push(3); // add 3
	mstack.push(5); // add 5
	mstack.push(737); // add 737
	//[...]
	mstack.push(0); // add 0

	// current stack is [0, 737, 5, 3, 5]

	MutantStack<int>::iterator it = mstack.begin(); // it = 5 because his->c.begin() point the first added element
	MutantStack<int>::iterator ite = mstack.end(); // ite points next to 0(last element)

	++it; // it became 3
	--it; // it became 5 again

	while (it != ite)
	{
	std::cout << *it << std::endl; // print out from 5
	++it;
	}
	std::stack<int> s(mstack); // creating instance "s" of std::stack to check mstack is inherited from stack


	std::cout << "\033[35mlist result\033[0m" << std::endl;
	testList();
	return 0;
}

