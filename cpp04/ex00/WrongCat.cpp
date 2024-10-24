/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:25:03 by mito              #+#    #+#             */
/*   Updated: 2024/10/24 15:28:51 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongCat";
    std::cout << "Default WrongCat constructor called\n";
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	_type = type;
	std::cout << "WrongCat constructor called: " << type << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    this->_type = other._type;
    std::cout << "WrongCat copy constructor called\n";
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat copy assignment operator called\n";
	if (this != &other)
	{
		this->_type = other._type;
		WrongAnimal::operator=(other); // to copy other member varible
	}
	return (*this);
}

void WrongCat::makeSound() const {
        std::cout << this->_type << ": fake meow!\n";
}
