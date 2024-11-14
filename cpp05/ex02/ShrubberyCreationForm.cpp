/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:13:28 by mito              #+#    #+#             */
/*   Updated: 2024/11/14 10:05:59 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137, "target") {
	std::cout << "default ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("Shrubbery Creation Form", 145, 137, target) {
	std::cout << "ShrubberyCreationForm constructor called with target name\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
: AForm(other) {
	std::cout << "ShrubberyCreationForm copy constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << "ShrubberyCreationForm copy assignment operator called\n";
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->getIsSigned() != true)
		throw FormNotSignedException("Form is not signed");
	if (executor.getGrade() > this->getExcuteGrade())
		throw GradeTooLowException("Grade it too low to execute");
	std::ofstream outfile(this->getTarget() + "_Shrubbery");
	if (!outfile)
		throw std::runtime_error("Error in ShrubberyCreationForm::execute()"); // ios_base?
	outfile << "             /\\ " << std::endl;
	outfile << "            /\\/\\" << std::endl;
	outfile << "           /\\/\\/\\ " << std::endl;
	outfile << "   *      /*\\/\\*/\\" << std::endl;
	outfile << "  ***    /\\/\\/\\/\\/\\" << std::endl;
	outfile << " *****       ||      " << std::endl;
	outfile << "   |         ||      " << std::endl;

	outfile.close();
}
