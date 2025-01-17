/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:02:54 by mito              #+#    #+#             */
/*   Updated: 2024/11/14 16:19:44 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm() {
	std::cout << "default PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("Presidential Pardon Form", 25, 5, target) {
	std::cout << "PresidentialPardonForm constructor called with target name\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
: AForm(other) {
	std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	std::cout << "PresidentialPardonForm copy assignment operator called\n";
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() != true)
		throw FormNotSignedException("Form is not signed");
	if (executor.getGrade() > this->getExcuteGrade())
		throw GradeTooLowException("Grade it too low to execute");

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}
