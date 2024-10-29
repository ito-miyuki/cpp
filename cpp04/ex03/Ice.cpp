/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:45:55 by mito              #+#    #+#             */
/*   Updated: 2024/10/29 14:31:11 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice constructor called\n";
}

Ice::Ice(const Ice&) : AMateria("ice") {
	std::cout << "Ice copy constructor called\n";
}

Ice::~Ice() {
	std::cout << "Ice destructor called\n";
}

Ice& Ice::operator=(const Ice&) {
	std::cout << "Ice copy assignment operator called\n";
	return (*this);
}

AMateria* Ice::clone() const {
	return (new Ice());
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}


