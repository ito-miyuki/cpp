/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:52:54 by mito              #+#    #+#             */
/*   Updated: 2024/10/17 14:11:50 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		std::string name;
		int hitPoints;
		int	energyPoints;
		int	attackDamage;

	public:
		ClapTrap(); // constructor
		ClapTrap(std::string name); // constructor
		ClapTrap(const ClapTrap& other); // copy constructor
		~ClapTrap(); //destructor

		ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
