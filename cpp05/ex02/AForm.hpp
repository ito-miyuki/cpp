/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:56:30 by mito              #+#    #+#             */
/*   Updated: 2024/11/14 16:00:52 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int  _signGrade;
		const int _excuteGrade;
		const std::string _target;

	public:
		AForm();
		AForm(const std::string name, int signGrade, int excuteGrade, const std::string target);
		virtual ~AForm();
		AForm(const AForm& other);

		AForm& operator=(const AForm& other);

		const std::string& getName() const;
		bool getIsSigned() const;
		const int& getSignGrade() const;
		const int& getExcuteGrade() const;
		const std::string& getTarget() const;

		void beSigned(Bureaucrat& bureaucrat);

		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception {
			private:
				const std::string _message;
			public:
				GradeTooHighException(const std::string& message);
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception {
			private:
				const std::string _message;
			public:
				GradeTooLowException(const std::string& message);
				const char* what() const noexcept override;
		};

		class FormNotSignedException : public std::exception {
			private:
				const std::string _message;
			public:
				FormNotSignedException(const std::string& message);
				const char* what() const noexcept override;
		};
	};

std::ostream& operator<<(std::ostream& output, const AForm& form);


#endif
