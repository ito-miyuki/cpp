/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:46:57 by mito              #+#    #+#             */
/*   Updated: 2024/11/14 16:20:03 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm() {
	std::cout << "default RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("Robotomy Request Form", 72, 45, target) {
	std::cout << "RobotomyRequestForm constructor called with target name\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
: AForm(other) {
	std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << "RobotomyRequestForm copy assignment operator called\n";
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() != true)
		throw FormNotSignedException("Form is not signed");
	if (executor.getGrade() > this->getExcuteGrade())
		throw GradeTooLowException("Grade it too low to execute");

	std::cout << "Drilling noises...\n";

	std::srand(std::time(0));
	bool result = std::rand() % 2;
	if (result == 1)
		std::cout << this->getTarget() << " has been robotomized successfully!\n";
	else
		std::cout << "Robotomy failed on " << this->getTarget() << std::endl;

}
