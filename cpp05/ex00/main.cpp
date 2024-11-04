/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:55:47 by mito              #+#    #+#             */
/*   Updated: 2024/11/04 18:05:16 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void testGrade() {

	std::cout << "\033[33m\n***testGrade()***\n\033[0m";
	try {
        Bureaucrat bureau("Miyuki", 151);  // invalid
        std::cout << bureau;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

	try {
        Bureaucrat bureau("Heino", 150);  // invalid
        std::cout << bureau;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

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
	Bureaucrat miyuki("Miyuki", 3);
	std::cout << miyuki;

	try {
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
	Bureaucrat miyuki("Miyuki", 150);
	std::cout << miyuki;

	try {
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
	testGrade();
	testIncrease();
	testDecrease();

    return 0;
}
