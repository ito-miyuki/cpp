/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 13:05:59 by mito              #+#    #+#             */
/*   Updated: 2024/12/30 12:03:19 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <iostream>
#include <array>
#include <deque>

void testVector(){
	std::vector<int> numbers = {1, 2, 3, 4, 5};
	try {
		std::vector<int>::iterator it = easyfind(numbers, 0);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(numbers, 1);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(numbers, 5);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator it = easyfind(numbers, -99);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void testArray(){
	std::array<int, 5> numbers = {1, 2, 3, 4, 5};
	try {
		std::array<int, 5>::iterator it = easyfind(numbers, 20);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		std::array<int, 5>::iterator it = easyfind(numbers, 1);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

/*
Double-Ended Queue:sequence container that allows
fast insertion and deletion of elements at both ends,
combining the properties of a vector and a list.
*/
void testDeque(){
	std::deque<int> numbers = {1, 2, 3, 4, 5};
	try {
		std::deque<int>::iterator it = easyfind(numbers, 20);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		std::deque<int>::iterator it = easyfind(numbers, 1);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int main() {
	std::cout << "\033[35mtestVector()\033[0m" << std::endl;
	testVector();

	std::cout << "\033[35mtestArray()\033[0m" << std::endl;
	testArray();

	std::cout << "\033[35mtestDeque()\033[0m" << std::endl;
	testDeque();
	
	return 0;
}
