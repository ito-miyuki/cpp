/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:01:08 by mito              #+#    #+#             */
/*   Updated: 2024/10/28 13:50:15 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal {
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& other);
        virtual ~Animal() = 0; // pure virtual function

        Animal& operator=(const Animal& other);

        virtual void makeSound() const = 0; // pure virtual function
		std::string getType() const;
};

#endif
