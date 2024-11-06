/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:55:51 by mito              #+#    #+#             */
/*   Updated: 2024/11/05 15:55:23 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("default"), _grade(1) {
	std::cout << "default Bureaucrat constructor called\n";
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {
	std::cout << "Bureaucrat constructor called with args\n";
	if (grade < 1)
		throw GradeTooHighException("Grade is too high");
	else if (grade > 150)
		throw GradeTooLowException("Grade is too low");
	this->_grade = grade;
	std::cout << "constructed\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructer called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat copy assignment operator called\n";
    if (this != &other) {
        this->_grade = other._grade;
    }
    return (*this);
}

std::string Bureaucrat::getName() const {
    return (this->_name);
}

int Bureaucrat::getGrade() const {
    return (this->_grade);
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat) {
	output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
	return output;
}

// exception calss: GradeTooHighException
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& message) : _errorMsg(message) {}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return (_errorMsg.c_str());
}

// exception calss: GradeTooLowException
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& message) : _errorMsg(message) {}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return (_errorMsg.c_str());
}

void Bureaucrat::increaseGrade() {
	if (this->_grade == 1)
		throw GradeTooHighException("Grade cannot be increased anymore");
	_grade--;
}

void Bureaucrat::decreaseGrade() {
	if (this->_grade == 150)
		throw GradeTooLowException("Grade cannot be decreased anymore");
	this->_grade++;
}



