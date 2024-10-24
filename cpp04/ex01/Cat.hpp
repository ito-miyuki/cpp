/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:02:00 by mito              #+#    #+#             */
/*   Updated: 2024/10/24 16:46:59 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

    public:
		Cat();
		Cat(std::string type);
		Cat(const Cat& other);
		~Cat() override;

		Cat& operator=(const Cat& other);
        void makeSound() const override;

	private:
		Brain* brain;
};

#endif
