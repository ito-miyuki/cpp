/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:48:52 by mito              #+#    #+#             */
/*   Updated: 2024/10/21 17:13:44 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(); // constructor
		ScavTrap(const std::string name); // constructor with param
		ScavTrap(const ScavTrap& other);
		~ScavTrap() override; // destructor

		ScavTrap& operator=(const ScavTrap& other); // Copy assignment operator

		void guardGate();
		void attack(const std::string& target) override;
};

#endif
