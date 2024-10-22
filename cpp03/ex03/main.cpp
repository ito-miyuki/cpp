/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:51:58 by mito              #+#    #+#             */
/*   Updated: 2024/10/21 17:50:53 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void testClapTrap()
{
	ClapTrap mitoClap("mitoClap");
	ClapTrap alliClap("alliClap");

	mitoClap.attack("alliClap");
}

void testScavTrap()
{
	ScavTrap mitoScav("mitoScav");
	ScavTrap alliScav("alliScav");

	mitoScav.attack("alliScav");
	alliScav.guardGate();
}

void testFragTrap()
{
	FragTrap mitoFrag("mitoFrag");
	FragTrap alliFrag("alliFrag");

	mitoFrag.attack("alliFrag");
	alliFrag.highFivesGuys();
}

int main(void)
{
	// ScavTrap* a = new ScavTrap("Copy");
	// delete a;  // without virtual keyword in destrucctor, it won't work

	std::cout << "**Test for ClapTrap class**" << std::endl;
	testClapTrap();

	std::cout << std::endl;

	std::cout << "**Test for ScavTrap class**" << std::endl;
	testScavTrap();

	std::cout << std::endl;

	std::cout << "**Test for FragTrap class**" << std::endl;
	testFragTrap();

	return 0;
}
