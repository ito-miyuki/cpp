/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:25:19 by mito              #+#    #+#             */
/*   Updated: 2024/10/29 17:19:35 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class ICharacter; // Forward Declaration

class AMateria
{
	protected:
		//std::string _type;
		std::string const _type;
	public:
		AMateria(); //constructor
		AMateria(std::string const & type);
		virtual ~AMateria(); //destructor
		AMateria(const AMateria& other); //copy constructor

		AMateria& operator=(const AMateria&); // copy assignment operator

		std::string const &getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
