/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:40:20 by mito              #+#    #+#             */
/*   Updated: 2024/11/12 12:50:39 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern() {
	std::cout << "default Intern constructor called\n";
}

Intern::~Intern() {
	std::cout << "Intern destructor called\n";
}
Intern::Intern(const Intern& other) {
	(void)other;
	std::cout << "Intern copy constructor called\n";
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	std::cout << "Intern copy assignment operator called\n";
	return (*this);
}

std::unique_ptr<AForm> Intern::makeForm(const std::string& formName, const std::string& target) {

	std::unique_ptr<AForm> form;

	std::string forms[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	int i = 0;
	while(i < 3)
	{
		if (formName == forms[i])
			break;
		i++;
	}

	switch (i) {
		case 0:
			form = std::make_unique<ShrubberyCreationForm>(target);
			break;
		case 1:
			form = std::make_unique<RobotomyRequestForm>(target);
			break;
		case 2:
			form = std::make_unique<PresidentialPardonForm>(target);
			break;
		default:
			std::cerr << "Form name '" << formName << "' is invalid\n";
			return nullptr;
	};
	std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}
