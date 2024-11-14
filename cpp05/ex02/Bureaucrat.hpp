/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:55:57 by mito              #+#    #+#             */
/*   Updated: 2024/11/14 13:19:30 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

# include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

		class GradeTooHighException : public std::exception {
			private:
				std::string _errorMsg;
			public:
				GradeTooHighException(const std::string& message);
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			private:
				std::string _errorMsg;
			public:
				GradeTooLowException(const std::string& message);
				const char* what() const noexcept override;
		};

    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat &other);

        std::string getName() const;
        int getGrade() const ;

		void increaseGrade();
		void decreaseGrade();

		void signForm(AForm& form);

		void executeForm(AForm const & form);

};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat);

#endif
