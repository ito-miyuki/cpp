/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:25:22 by mito              #+#    #+#             */
/*   Updated: 2024/10/31 11:52:48 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const& type) : _type(type) {}

AMateria::~AMateria()  {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria& AMateria::operator=(const AMateria& other) {
	this->_type = other._type;
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
