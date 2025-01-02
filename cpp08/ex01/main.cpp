/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:12:56 by mito              #+#    #+#             */
/*   Updated: 2025/01/02 16:18:10 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdexcept>

void testAddNumbers(){

	try {
		Span sp(10);

		std::vector<int> vec1 = {1, 2, 3, 4, 5};
		std::vector<int> vec2 = {6, 7, 8};
		std::vector<int> vec3 = {9, 10};

		sp.addNumbers(vec1.begin(), vec1.end());

		sp.addNumbers(vec2.begin(), vec2.end());

		sp.addNumbers(vec3.begin(), vec3.end());

		for (int n : sp.getVector()) {
            std::cout << n << " ";
        }
        std::cout << std::endl;
		

	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void smallVector(){

	try {
		Span sp = Span(1);
		sp.addNumber(6);

		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		Span sp = Span(1);
		sp.addNumber(6);

		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void exceedSize() {
	try {
		Span sp = Span(3);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(1);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		Span sp = Span(2);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(1);
	} catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

int main()
{
	std::cout << "\033[35mtest from Subject\033[0m" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\033[35mexceedSize()\033[0m" << std::endl;
	exceedSize();

	std::cout << "\033[35msmallVector()\033[0m" << std::endl;
	smallVector();

	std::cout << "\033[35mtestAddNumbers()\033[0m" << std::endl;
	testAddNumbers();

	return 0;

}

