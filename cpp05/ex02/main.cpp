/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:25:20 by mito              #+#    #+#             */
/*   Updated: 2024/11/08 10:10:30 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testShrubberyCreationForm() {
	std::cout << "\033[33m\n***testShrubberyCreationForm()***\n\033[0m";
	Bureaucrat miyuki("Miyuki", 1);
	ShrubberyCreationForm shForm;

	miyuki.signForm(shForm);
	shForm.execute(miyuki);
}

void testRobotomyRequestForm() {
	std::cout << "\033[33m\n***testRobotomyRequestForm()***\n\033[0m";
	Bureaucrat miyuki("Miyuki", 1);
	RobotomyRequestForm rbForm("Max"); // target is "Max"

	miyuki.signForm(rbForm);
	rbForm.execute(miyuki);
}

void testPresidentialPardonForm() {
	std::cout << "\033[33m\n***testPresidentialPardonForm()***\n\033[0m";
	Bureaucrat miyuki("Miyuki", 1);
	PresidentialPardonForm ppForm("Yunchia");

	miyuki.signForm(ppForm);
	ppForm.execute(miyuki);
}

int main() {

	testShrubberyCreationForm();
	testRobotomyRequestForm();
	testPresidentialPardonForm();
	return 0;
}
