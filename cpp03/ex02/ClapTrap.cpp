/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:52:49 by mito              #+#    #+#             */
/*   Updated: 2024/10/24 11:24:07 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name("undefined"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap constructor called: " << name << std::endl;
}

// copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name)
	, hitPoints(other.hitPoints)
	, energyPoints(other.energyPoints)
	, attackDamage(other.attackDamage) {
	std::cout << "ClapTrap copy constructor called: " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called: " << this->name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints == 0)
		std::cout << "ClapTrap " << this->name << " can't attack because it doesn't have any energy points!\n";
	else if (this->hitPoints == 0)
		std::cout << "ClapTrap " << this->name << " is dead so can't attack\n";
	else
	{
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead\n";
		return ;
	}
	if (amount >= this->hitPoints)
	{
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage and dead\n";
	}
	else
	{
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints == 0)
		std::cout << "ClapTrap " << this->name << " can't repair because it doesn't have any energy points!\n";
	else if (this->hitPoints == 0)
		std::cout << "ClapTrap " << this->name << " is dead. Can't repair\n";
	else
	{
		this->energyPoints--;
		this->hitPoints += amount;
		std::cout << "ClapTrap " << this->name << " is repaired, " << amount << " point back\n";
	}
}
