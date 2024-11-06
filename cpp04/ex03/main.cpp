/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:28:16 by mito              #+#    #+#             */
/*   Updated: 2024/10/31 15:37:54 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

void testSubject() {
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;
}

int main()
{

	std::cout << "\n***testSubject()***\n";
	testSubject();

	std::cout << "***my own test***\n";
    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    // create characters
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");

    // equip Materia
    for (int i = 0; i < 8; i++) {
        me->equip(src->createMateria("ice"));
        bob->equip(src->createMateria("cure"));
    }

    // use Materia
    me->use(0, *bob);
    me->use(1, *bob);

	// use invalid index
	bob->use(-1, *bob);

    // for safe unequip
    AMateria* unequippedOne = dynamic_cast<Character*>(me)->getInventory(0);
    me->unequip(0);

	// try to use it again but should not work or crash
    me->use(0, *bob); // try to use it again but should not work or crash

    delete unequippedOne;
    delete bob;
    delete me;
    delete src;

    return 0;
}