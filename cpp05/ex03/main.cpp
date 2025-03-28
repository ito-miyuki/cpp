/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:25:20 by mito              #+#    #+#             */
/*   Updated: 2024/11/14 16:22:52 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void testShrubberyCreationForm() {
	std::cout << "\033[33m\n***testShrubberyCreationForm()***\n\033[0m";
	try {
		Bureaucrat miyuki("Miyuki", 1);
		ShrubberyCreationForm shForm("Shrubbery");

		miyuki.signForm(shForm);
		miyuki.executeForm(shForm);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat bob("Bob", 150);
		ShrubberyCreationForm shForm2("Shrubbery2");

		bob.signForm(shForm2);
		bob.executeForm(shForm2);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void testRobotomyRequestForm() {
	std::cout << "\033[33m\n***testRobotomyRequestForm()***\n\033[0m";
	try {
		Bureaucrat miyuki("Miyuki", 1);
		RobotomyRequestForm rbForm("Max"); // target is "Max"

		miyuki.signForm(rbForm);
		miyuki.executeForm(rbForm);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat inka("Inka", 150);
		RobotomyRequestForm rbForm("Alice");

		inka.signForm(rbForm);
		inka.executeForm(rbForm);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void testPresidentialPardonForm() {
	std::cout << "\033[33m\n***testPresidentialPardonForm()***\n\033[0m";

	try {
		Bureaucrat miyuki("Miyuki", 1);
		PresidentialPardonForm ppForm("Yunchia");

		miyuki.signForm(ppForm);
		miyuki.executeForm(ppForm);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat mito("Mito", 5);
		PresidentialPardonForm ppForm("Yunchia");

		mito.decreaseGrade(); // decrease the grade, now it's 4
		mito.signForm(ppForm);
		mito.executeForm(ppForm);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void testIntern() {
	std::cout << "\033[33m\n***testIntern()***\n\033[0m";

	// from subject pdf
	Intern someRandomIntern;

	//Form* rrf;
	std::unique_ptr<AForm> rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	std::cout << std::endl;

	std::unique_ptr<AForm> ppf = someRandomIntern.makeForm("presidential pardon", "Miyuki");

	std::cout << std::endl;

	std::unique_ptr<AForm> scf = someRandomIntern.makeForm("shrubbery creation", "Mike");

	std::cout << std::endl;

	someRandomIntern.makeForm("Presidential Pardonn", "Max"); // wrong request
}


int main() {

	testShrubberyCreationForm();
	testRobotomyRequestForm();
	testPresidentialPardonForm();
	testIntern();
	return 0;
}
