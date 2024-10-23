/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:02:40 by mito              #+#    #+#             */
/*   Updated: 2024/10/23 16:37:54 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(const FragTrap& other);
		~FragTrap() override;

		FragTrap& operator=(const FragTrap& other);

		void attack(const std::string& target);
		//void attack(const std::string& target) override;
		void highFivesGuys(void);
};

#endif
