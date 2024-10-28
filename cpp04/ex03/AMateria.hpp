/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:25:19 by mito              #+#    #+#             */
/*   Updated: 2024/10/28 15:41:52 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(); //constructor
		AMateria(std::string const & type);
		virtual ~AMateria(); //destructor
		AMateria(const AMateria& other); //copy constructor

		AMateria& operator=(const AMateria& other); // copy assignment operator

		std::string const &getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
