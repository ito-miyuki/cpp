/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:58:20 by mito              #+#    #+#             */
/*   Updated: 2024/10/31 10:30:41 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria* _inventory[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		~MateriaSource() override;
		MateriaSource& operator=(const MateriaSource& other);
		void learnMateria(AMateria*) override;
		AMateria* createMateria(std::string const & type) override;
};

#endif
