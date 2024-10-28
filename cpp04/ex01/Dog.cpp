/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:42:18 by mito              #+#    #+#             */
/*   Updated: 2024/10/28 13:27:20 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
    std::cout << "Default Dog constructor called\n";
	_type = "Dog";
	brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog constructor called: " << type << std::endl;
	_type = type;
	brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog copy constructor called\n";
	brain = new Brain(*other.brain);
}

/*
Shallow copy in Cat class for testing(THIS IS WRONG)
Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Shallow Copy Constructor for Cat called\n";
    this->brain = other.brain; // this way, it is sharing the same Brain pointer
}
*/

Dog::~Dog() {
    std::cout << "Dog destructor called\n";
	delete brain;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called\n";
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return (*this);
}

void Dog::makeSound() const {
        std::cout << this->_type << ": woof woof!\n";
}

Brain* Dog::getBrain() {
	return (brain);
}

