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

std::unique_ptr<AForm> Intern::createShrubberyCreationForm(const std::string& target) {
	return std::make_unique<ShrubberyCreationForm>(target);
}

std::unique_ptr<AForm> Intern::createRobotomyRequestForm(const std::string& target) {
	return std::make_unique<RobotomyRequestForm>(target);
}

std::unique_ptr<AForm> Intern::createPresidentialPardonForm(const std::string& target) {
	return std::make_unique<PresidentialPardonForm>(target);
}

std::unique_ptr<AForm> Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string forms[] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};
	FormConstructor formConstructors[] = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	int i = 0;
	while(i < 3)
	{
		if (formName == forms[i])
			break;
		i++;
	}
	if (i < 3) {
		std::cout << "Intern creates " << formName << std::endl;
		return (this->*formConstructors[i])(target);
	}
	else {
		std::cerr << "Form name '" << formName << "' is invalid\n";
		return nullptr;
	}

}
