/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:45:48 by mito              #+#    #+#             */
/*   Updated: 2024/10/29 14:52:34 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {
	std::cout << "Ice constructor called\n";
}

Cure::Cure(const Cure&) : AMateria("cure") {
	std::cout << "Cure copy constructor called\n";
}

Cure::~Cure() {
	std::cout << "Cure destructor called\n";
}

Cure& Cure::operator=(const Cure&) {
	std::cout << "Cure copy assignment operator called\n";
	return (*this);
}

AMateria* Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "’s wounds *\n";
}
