/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:51:58 by mito              #+#    #+#             */
/*   Updated: 2024/10/23 16:56:53 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
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

void testDiamondTrap()
{
	DiamondTrap mitoDiamond("mitoDiamond");
	DiamondTrap alliDiamond("alliDiamond");

	mitoDiamond.attack("alliDiamond");
	mitoDiamond.whoAmI();
	alliDiamond.whoAmI();

}

int main(void)
{
	ScavTrap* a = new ScavTrap("Copy");
	delete a;  // without virtual keyword in destrucctor, it won't work

	std::cout << "**Test for ClapTrap class**" << std::endl;
	testClapTrap();

	std::cout << std::endl;

	std::cout << "**Test for ScavTrap class**" << std::endl;
	testScavTrap();

	std::cout << std::endl;

	std::cout << "**Test for FragTrap class**" << std::endl;
	testFragTrap();

	std::cout << std::endl;

	std::cout << "**Test for DiamondTrap class**" << std::endl;
	testDiamondTrap();

	return 0;
}
