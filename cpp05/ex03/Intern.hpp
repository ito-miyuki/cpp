/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:40:17 by mito              #+#    #+#             */
/*   Updated: 2024/11/12 11:55:30 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"
# include <memory> // for std::unique_ptr

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);

		Intern& operator=(const Intern& other);

		std::unique_ptr<AForm> makeForm(const std::string& formName, const std::string& target);

	private:
		std::unique_ptr<AForm> createShrubberyCreationForm(const std::string& target);
		std::unique_ptr<AForm> createRobotomyRequestForm(const std::string& target);
		std::unique_ptr<AForm> createPresidentialPardonForm(const std::string& target);
};

typedef std::unique_ptr<AForm> (Intern::*FormConstructor)(const std::string& target);


#endif
