/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:19:45 by mito              #+#    #+#             */
/*   Updated: 2024/10/25 15:24:09 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), name("Undefined") {
    std::cout << "DiamonTrap constructor called: " << name << std::endl;
}

/*
Because I called Frag's constructor at the last, Diamond inherited Frag's.
*/
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
    this->energyPoints = 50; // Frag already overrode scav's values so it has to declare by number
    std::cout << "DiamonTrap constructor called: " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
    std::cout << "DiamondTrap copy constructor called: " << name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "DiamondTrap copy assignment operator called\n";
	if (this != &other)
	{
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		this->name = other.name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called: " << name << std::endl;
}


void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}


void DiamondTrap::whoAmI() {
	std::cout << "I am " << this->name << ", my ClapTrap name is " << ClapTrap::name << std::endl;

}
