/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:48:33 by mito              #+#    #+#             */
/*   Updated: 2025/01/03 19:37:03 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

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
	std::stack<int> s(mstack);
	return 0;
}

// #include <iostream>
// #include "MutantStack.hpp"

// int main() {
//     MutantStack<int> mstack;

//     mstack.push(10);
//     mstack.push(20);
//     mstack.push(30);

//     std::cout << "Stack contents (using iterator):" << std::endl;
//     for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     return 0;
// }

