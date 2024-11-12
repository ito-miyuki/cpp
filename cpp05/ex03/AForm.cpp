/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:56:22 by mito              #+#    #+#             */
/*   Updated: 2024/11/12 12:46:30 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(1), _excuteGrade(1), _target("target") {
	std::cout << "default Form constructor called\n";
}

// should this be &const std::string name???
AForm::AForm(const std::string name, int signGrade, int excuteGrade, const std::string target) : _name(name),
_isSigned(false),
_signGrade(signGrade),
_excuteGrade(excuteGrade),
_target(target)
{
	std::cout << "AForm constructor called with args\n";
	if (signGrade < 1 || excuteGrade < 1)
		throw GradeTooHighException("Grade is too high");
	else if (signGrade > 150 || excuteGrade > 150)
		throw GradeTooLowException("Grade is too low");
	std::cout << "constructed\n";
}

AForm::~AForm() {
	std::cout << "AForm destructor called\n";
}

AForm::AForm(const AForm& other) : _name(other._name),
_isSigned(other._isSigned),
_signGrade(other._signGrade),
_excuteGrade(other._excuteGrade),
_target(other._target) {
	std::cout << "AForm copy constructor called\n";
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "AForm copy assignment operator called\n";
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

const std::string& AForm::getName() const {
	return (this->_name);
}

bool AForm::getIsSigned() const {
	return (this->_isSigned);
}

const int& AForm::getSignGrade() const {
	return (this->_signGrade);
}

const int& AForm::getExcuteGrade() const {
	return (this->_excuteGrade);
}

const std::string& AForm::getTarget() const {
	return (this->_target);
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw GradeTooLowException("Grade is too low to sign");
}

// exception calss: GradeTooHighException
AForm::GradeTooHighException::GradeTooHighException(const std::string& message) : _message(message) {}

const char* AForm::GradeTooHighException::what() const noexcept {
	return (_message.c_str());
}

// exception calss: GradeTooLowException
AForm::GradeTooLowException::GradeTooLowException(const std::string& message) : _message(message) {}

const char* AForm::GradeTooLowException::what() const noexcept {
	return (_message.c_str());
}

// exception calss: FormNotSignedException
AForm::FormNotSignedException::FormNotSignedException(const std::string& message) : _message(message) {}

const char* AForm::FormNotSignedException::what() const noexcept {
	return (_message.c_str());
}

std::ostream& operator<<(std::ostream& output, const AForm& AForm) {
	std::cout << "Form name: " << AForm.getName() << std::endl
	<< "Is Form signed: " << AForm.getIsSigned() << std::endl
	<< "Grade to sign: " << AForm.getSignGrade() << std::endl
	<< "Grade to excute: " << AForm.getExcuteGrade() << std::endl;
	return (output);
}


