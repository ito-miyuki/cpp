/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:52:49 by mito              #+#    #+#             */
/*   Updated: 2024/10/15 16:57:00 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energypoints(10), attackDamage(0)
{
	std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energypoints(10), attackDamage(0)
{
	// std::cout << "Default constructor called\n";
}
