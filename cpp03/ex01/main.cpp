/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:51:58 by mito              #+#    #+#             */
/*   Updated: 2024/10/21 13:00:07 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


int main(void)
{
	ScavTrap mitoScav("mitoScav");
	ScavTrap alliScav("alliScav");

	mitoScav.attack("alliScav");
	alliScav.takeDamage(2);

	alliScav.attack("mitoScav");
	mitoScav.takeDamage(8);

	mitoScav.guardGate();

	alliScav.attack("mitoScav");
	mitoScav.takeDamage(9);

	mitoScav.beRepaired(6);

	return 0;
}
