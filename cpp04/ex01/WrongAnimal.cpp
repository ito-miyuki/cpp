/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:21:09 by mito              #+#    #+#             */
/*   Updated: 2024/10/24 15:24:46 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("default") {
        std::cout << "Default WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
        std::cout << "WrongAnimal constructor called: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
        this->_type = other._type;
        std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal::~WrongAnimal() {
        std::cout << "WrongAnimal Destructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
        std::cout << "WrongAnimal copy assignment operator called\n";
        if (this != &other)
                this->_type = other._type;
        return (*this);
}

void WrongAnimal::makeSound() const {
        std::cout << this->_type << ": No sounds....\n";
}

std::string WrongAnimal::getType() const {
	return (this->_type);
}
