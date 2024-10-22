/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:52:54 by mito              #+#    #+#             */
/*   Updated: 2024/10/21 17:36:26 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string name;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned int attackDamage;

	public:
		ClapTrap(); // constructor
		ClapTrap(std::string name); // constructor
		ClapTrap(const ClapTrap& other); // copy constructor
		virtual ~ClapTrap(); //destructor

		ClapTrap& operator=(const ClapTrap& other); // Copy assignment operator

		void attack(const std::string& target);
		//virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
