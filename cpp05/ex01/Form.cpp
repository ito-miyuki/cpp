/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:56:22 by mito              #+#    #+#             */
/*   Updated: 2024/11/05 15:55:23 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(1), _excuteGrade(1) {
	std::cout << "default Form constructor called\n";
}

Form::Form(const std::string name, int signGrade, int excuteGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _excuteGrade(excuteGrade) {
	std::cout << "Form constructor called with args\n";
	if (signGrade < 1 || excuteGrade < 1)
		throw GradeTooHighException("Grade is too high");
	else if (signGrade > 150 || excuteGrade > 150)
		throw GradeTooLowException("Graade is too low");
	std::cout << "constructed\n";
}

Form::~Form() {
	std::cout << "Form destructer called\n";
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _excuteGrade(other._excuteGrade) {
	std::cout << "Form copy constructor called\n";
}

Form& Form::operator=(const Form& other) {
	std::cout << "Form copy assignment operator called\n";
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

const std::string& Form::getName() const {
	return (this->_name);
}

bool Form::getIsSigned() const {
	return (this->_isSigned);
}

const int& Form::getSignGrade() const {
	return (this->_signGrade);
}

const int& Form::getExcuteGrade() const {
	return (this->_excuteGrade);
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw GradeTooLowException("Grade is too low to sign");
}

// exception calss: GradeTooHighException
Form::GradeTooHighException::GradeTooHighException(const std::string& message) : _message(message) {}

const char* Form::GradeTooHighException::what() const noexcept {
	return (_message.c_str());
}

// exception calss: GradeTooLowException
Form::GradeTooLowException::GradeTooLowException(const std::string& message) : _message(message) {}

const char* Form::GradeTooLowException::what() const noexcept {
	return (_message.c_str());

}

std::ostream& operator<<(std::ostream& output, const Form& form) {
	std::cout << "Form name: " << form.getName() << std::endl
	<< "Is form signed: " << form.getIsSigned() << std::endl
	<< "Grade to sign: " << form.getSignGrade() << std::endl
	<< "Grade to excute: " << form.getExcuteGrade() << std::endl;
	return (output);
}


