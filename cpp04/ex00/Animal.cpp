/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:01:25 by mito              #+#    #+#             */
/*   Updated: 2024/10/31 10:09:46 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
# include <iostream>

Animal::Animal() : _type("default") {
    std::cout << "Default Animal constructor called\n";
}

Animal::Animal(std::string type) : _type(type) {
    std::cout << "Animal constructor called: " << type << std::endl;
}

Animal::Animal(const Animal& other) {
    this->_type = other._type;
    std::cout << "Animal copy constructor called\n";
}

Animal::~Animal() {
    std::cout << "Animal Destructor called\n";
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal copy assignment operator called\n";
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

void Animal::makeSound() const {
    std::cout << this->_type << ": No sounds....\n";
}

std::string Animal::getType() const {
	return (this->_type);
}
