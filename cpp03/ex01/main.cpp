/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:51:58 by mito              #+#    #+#             */
/*   Updated: 2024/10/17 16:46:55 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Miyuki("Miyuki");
	ClapTrap Max("Max");

	Miyuki.attack("Max");
	Max.takeDamage(2);

	Miyuki.attack("Max");
	Max.takeDamage(5);

	Max.attack("Miyuki");
	Miyuki.takeDamage(8);

	Miyuki.attack("Max");
	Max.takeDamage(2);

	Max.attack("Miyuki");
	Miyuki.takeDamage(9);

	Miyuki.beRepaired(6);

	return 0;
}
