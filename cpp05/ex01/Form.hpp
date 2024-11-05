/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:56:30 by mito              #+#    #+#             */
/*   Updated: 2024/11/05 15:44:25 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>
// # include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int  _signGrade;
		const int _excuteGrade;

		class GradeTooHighException : public std::exception {
			private:
				const std::string _message;
			public:
				GradeTooHighException(const std::string& message);
				virtual const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			private:
				const std::string _message;
			public:
				GradeTooLowException(const std::string& message);
				virtual const char* what() const noexcept override;
		};

	public:
		Form();
		Form(const std::string name, int signGrade, int excuteGrade);
		~Form();
		Form(const Form& other);

		Form& operator=(const Form& other);

		const std::string& getName() const;
		bool getIsSigned() const;
		const int& getSignGrade() const;
		const int& getExcuteGrade() const;

		void beSigned(Bureaucrat& bureaucrat);

	};

std::ostream& operator<<(std::ostream& output, const Form& form);


#endif
