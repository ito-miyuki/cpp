/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:27:27 by mito              #+#    #+#             */
/*   Updated: 2024/10/24 16:16:28 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WEONGCAT_HPP

#include "WrongAnimal.hpp"


class WrongCat : public WrongAnimal {

    public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat& other);
		~WrongCat() override;

		WrongCat& operator=(const WrongCat& other);
        void makeSound() const;
};

#endif
