/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:19:45 by mito              #+#    #+#             */
/*   Updated: 2024/10/23 16:58:44 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), name("Undefined") {
    std::cout << "DiamonTrap constructor called: " << name << std::endl;
}

// DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
    this->energyPoints = 50; // Frag already overrode scav's values so it has to declare by number
    std::cout << "DiamonTrap constructor called: " << name << std::endl;
}
/*
Because I called Frag's constructor at the last, Diamond inherited Frag's.
*/

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
    std::cout << "DiamondTrap copy constructor called: " << name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
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


//attack() (Scavtrap) Do I have to declare?


void DiamondTrap::whoAmI() {
	std::cout << "I am " << this->name << ", my grand parent is " << ClapTrap::name << std::endl;

}
