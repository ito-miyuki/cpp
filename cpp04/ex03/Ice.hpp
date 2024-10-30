/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:44:47 by mito              #+#    #+#             */
/*   Updated: 2024/10/29 17:16:29 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <string>

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice&);
		~Ice() override;
		Ice& operator=(const Ice&);
		void use(ICharacter& target) override;
		AMateria* clone() const override;
};

#endif
