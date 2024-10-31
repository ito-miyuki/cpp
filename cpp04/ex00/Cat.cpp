/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:02:06 by mito              #+#    #+#             */
/*   Updated: 2024/10/31 10:07:13 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
	_type = "Cat";
    std::cout << "Default Cat constructor called\n";
}

Cat::Cat(std::string type) : Animal(type) {
	_type = type;
	std::cout << "Cat constructor called: " << type << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    this->_type = other._type;
    std::cout << "Cat copy constructor called\n";
}

Cat::~Cat() {
    std::cout << "Cat Destructor called\n";
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called\n";
	if (this != &other)
	{
		this->_type = other._type;
		Animal::operator=(other); // to copy other member varible
	}
	return (*this);
}

void Cat::makeSound() const {
        std::cout << this->_type << ": meow meow!\n";
}
