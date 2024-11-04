
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat() : _name("default"), _grade(1) {
	std::cout << "default Bureaucrat constructer called\n";
}

// add error handling
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {
	std::cout << "Bureaucrat constructer called with args\n";
	// if (grade < 1)
	// 	// do error handling
	// else if (grade > 150)
	// 	// do error handling
	std::cout << "constructed\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "copy constructer called\n";
}

Bureaucrat::~Bureaucrat() {
	std::cout << "destructer called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "copy assignment operator called\n";
    if (this != &other) {
        this->_name = other._name;
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

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &message) : _errorMsg(message) {}


