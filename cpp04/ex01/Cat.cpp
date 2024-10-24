/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:02:06 by mito              #+#    #+#             */
/*   Updated: 2024/10/24 17:29:03 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>


Cat::Cat() : Animal() {
    std::cout << "Default Cat constructor called\n";
	_type = "Cat";
	brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat constructor called: " << type << std::endl;
	_type = type;
	brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called\n";
    // this->_type = other._type; // I don't need this because Animal(other) already copied.
	brain = new Brain(*other.brain);
}

Cat::~Cat() {
    std::cout << "Cat destructor called\n";
	delete brain;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called\n";
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return (*this);
}

void Cat::makeSound() const {
    std::cout << this->_type << ": meow meow!\n";
}
