/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:28:16 by mito              #+#    #+#             */
/*   Updated: 2024/10/29 17:14:41 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"

int main()
{
	// {
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	ICharacter* me = new Character("me");
	// 	AMateria* tmp;
	// 	tmp = src->createMateria("ice");
	// 	me->equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	me->equip(tmp);
	// 	ICharacter* bob = new Character("bob");
	// 	me->use(0, *bob);
	// 	me->use(1, *bob);
	// 	delete bob;
	// 	delete me;
	// 	delete src;
	// }
	
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");

		for (int i = 0; i < 10; i++) {
			if (i % 2 == 0) {
				me->equip(src->createMateria("ice"));
				bob->equip(src->createMateria("cure"));
			} else {
				me->equip(src->createMateria("cure"));
				bob->equip(src->createMateria("ice"));
			}
		}
		me->use(0, *bob);
		AMateria *unequipedOne = dynamic_cast<Character*>(me)->getAmateria(2);
		me->unequip(2);
		me->use(1, *bob);
		delete unequipedOne;
		delete bob;
		delete me;
		delete src;
	}

	return 0;
}
