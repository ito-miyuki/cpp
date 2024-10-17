/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:51:58 by mito              #+#    #+#             */
/*   Updated: 2024/10/17 14:35:32 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Miyuki(Miyuki);
	ClapTrap Max("Max");

	Miyuki.attack("Max");
	Max.takeDamage(6);
	Max.attack("Liam");

	return 0;
}
