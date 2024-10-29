/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:25:22 by mito              #+#    #+#             */
/*   Updated: 2024/10/29 17:19:27 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("default") {
	std::cout << "Default constructor called\n";
}

AMateria::AMateria(std::string const& type) : _type(type) {
	std::cout << "type constructor called: " << this->_type << std::endl;
}

AMateria::~AMateria()  {
	std::cout << "Destructor called\n";
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
	std::cout << "Copy constructor called\n";
}

// should not copy???: copy constructer
// AMateria::AMateria(const AMateria& other) {
// 	std::cout << "Copy constructor called\n";
// }

AMateria& AMateria::operator=(const AMateria&) {
	std::cout << "AMateria copy assignment operator called\n";
	return (*this);
}

std::string const& AMateria::getType() const {
	return (this->_type);
}

/*
	AMateria can use getName() through target(ICharacter type) that is passed as parameter
*/
void AMateria::use(ICharacter& target) {
	std::cout << target.getName() << " uses AMateria " << _type << std::endl;
}
