
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception> // do i need it?

class Bureaucrat {
    private:
        std::string _name;
        int _grade;

		class GradeTooHighException : public std::exception {
			private:
				std::string _errorMsg;
			public:
				GradeTooHighException(const std::string &message); // constructer
				virtual const char* what() const noexcept override; // what() is from std::exception library
		};

    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade); // const?
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat &other);

        std::string getName() const;
        int getGrade() const ;

};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat);

#endif
