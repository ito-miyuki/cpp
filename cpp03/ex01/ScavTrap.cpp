/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:48:38 by mito              #+#    #+#             */
/*   Updated: 2024/10/18 14:28:43 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// constructor
ScavTrap::ScavTrap() : ClapTrap() {
	//name = "undifined"; // why we don'y init name too?
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called\n";
}

// constructor with param
ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	//name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called\n";
}

// copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) {
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "ScavTrap default constructor called\n";
}

// destructor
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called: " << this->name << std::endl;
}
