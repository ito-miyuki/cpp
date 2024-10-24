/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:43:41 by mito              #+#    #+#             */
/*   Updated: 2024/10/23 13:43:58 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"


class Dog : public Animal {

    public:
		Dog();
		Dog(std::string type);
		Dog(const Dog& other);
		~Dog() override;

		Dog& operator=(const Dog& other);
        void makeSound() const override;
};

#endif
