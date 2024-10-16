/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:52:49 by mito              #+#    #+#             */
/*   Updated: 2024/10/16 13:20:26 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energypoints(10), attackDamage(0)
{
	std::cout << "Default constructor called\n";
	name = "Default name";
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energypoints(10), attackDamage(0)
{
	std::cout << "constructor called with name: " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{
	//std::cout << "ClapTrap " << <name> << " attacks " << target << " causing " << <damage> << " points of damage!\n";
	std::cout << "Attacked " << target << std::endl;
}

void takeDamage(unsigned int amount);
void beRepaired(unsigned int amount);
