/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:25:22 by mito              #+#    #+#             */
/*   Updated: 2024/10/28 15:51:57 by mito             ###   ########.fr       */
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


