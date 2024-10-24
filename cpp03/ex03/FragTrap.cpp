/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:02:34 by mito              #+#    #+#             */
/*   Updated: 2024/10/24 11:33:00 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap conctructor called: " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called\n";
}


FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called: " << this->name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

void FragTrap::attack(const std::string& target) {
	if (this->energyPoints == 0)
		std::cout << "FragTrap " << this->name << " can't attack because it doesn't have any energy points!\n";
	else if (this->hitPoints == 0)
		std::cout << "FragTrap " << this->name << " is dead so can't attack\n";
	else
	{
		this->energyPoints--;
		std::cout << "FragTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!\n";
	}
}

void FragTrap::highFivesGuys(void) {
	std::cout << "High five guys!! ( ^o^)/\\(^-^) \n";

}
