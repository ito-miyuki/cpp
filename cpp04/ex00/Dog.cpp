/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:42:18 by mito              #+#    #+#             */
/*   Updated: 2024/10/23 13:48:51 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
	_type = "Dog";
    std::cout << "Default Dog constructor called\n";
}

Dog::Dog(std::string type) : Animal(type) {
	_type = type;
	std::cout << "Dog constructor called: " << type << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
    this->_type = other._type;
    std::cout << "Dog copy constructor called\n";
}

Dog::~Dog() {
    std::cout << "Dog Destructor called\n";
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called\n";
	if (this != &other)
	{
		this->_type = other._type;
		Animal::operator=(other); // to copy other member varible
	}
	return (*this);
}

void Dog::makeSound() const {
        std::cout << this->_type << ": woof woof!\n";
}

