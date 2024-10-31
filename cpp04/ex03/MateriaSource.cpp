/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:58:28 by mito              #+#    #+#             */
/*   Updated: 2024/10/31 11:54:26 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

// it doesn't have to call IMateria's constructor because IMateria is an interface
MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i] != nullptr)
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
			if (other._inventory[i] != nullptr)
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m) {
	if (m == nullptr)
		return ;

	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == nullptr)
		{
			_inventory[i] = m;
			return ;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != nullptr && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (0);
}
