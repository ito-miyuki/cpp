/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:55:47 by mito              #+#    #+#             */
/*   Updated: 2024/11/14 16:30:39 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void testCopy() {
    std::cout << "\033[33m\n***testCopy()***\n\033[0m";

    try {
        Bureaucrat original("Alice", 42);
        Bureaucrat copy(original); // create copy of Alice

        // printout the status
        std::cout << original;
        std::cout << copy;

        // modify original
        copy.increaseGrade(); // copy's grade is increased
        std::cout << "--after increasing copy's grade--\n";
        std::cout << original;
        std::cout << copy;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void testGrade() {

	std::cout << "\033[33m\n***testGrade()***\n\033[0m";
	try {
        Bureaucrat bureau("Miyuki", 151);  // invalid
        std::cout << bureau;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

	std::cout << std::endl;

	try {
        Bureaucrat bureau("Heino", 150);  // invalid
        std::cout << bureau;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

	std::cout << std::endl;

	try {
        Bureaucrat bureau("Max", 1);
        std::cout << bureau;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void testIncrease() {

	std::cout << "\033[33m\n***testIncrease()***\n\033[0m";

	try {
		Bureaucrat miyuki("Miyuki", 3);
		std::cout << miyuki;
		miyuki.increaseGrade(); // become 2
		std::cout << miyuki;

		miyuki.increaseGrade(); // become 1
		std::cout << miyuki;

		miyuki.increaseGrade(); // become 0, invalid
		std::cout << miyuki;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void testDecrease() {

	std::cout << "\033[33m\n***testDecrease()***\n\033[0m";

	try {
		Bureaucrat miyuki("Miyuki", 150);
		std::cout << miyuki;
		miyuki.decreaseGrade(); // become 151
		std::cout << miyuki;

		miyuki.decreaseGrade();
		std::cout << miyuki;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    testCopy();
	testGrade();
	testIncrease();
	testDecrease();

    return 0;
}
