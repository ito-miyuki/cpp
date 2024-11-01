/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:58:28 by mito              #+#    #+#             */
/*   Updated: 2024/10/31 15:18:24 by mito             ###   ########.fr       */
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
	void* freedObjs[4] = {nullptr};
	int uniqueFreedCount = 0;

	for (int i = 0; i < 4; i++) {
		int isFreed = 0;
		// loop to see if the current _inventory[i] has already been deleted while comparing with CountObjs
		for (int j = 0; j < uniqueFreedCount; j++) {
			if (this->_inventory[i] == freedObjs[j]) { // If _inventory[i] matches a previously freed pointer
				isFreed = 1;
				break;
			}
		}
		// If isFreed == 0, _inventory[i] has not been deleted yet, first time will come here
		if (!isFreed) {
			freedObjs[uniqueFreedCount] = this->_inventory[i]; // Store the pointer in freedObjs to remember
			delete this->_inventory[i];
			uniqueFreedCount++;
		}
	}
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

void	MateriaSource::learnMateria(AMateria *m){
	if (m == nullptr)
		return ;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == nullptr) {
			this->_inventory[i] = m;
			return ;
		}
	}
	for (int i = 0; i < 4; i++) // when there was no spot available
	{
		if (_inventory[i] == m) // if it is alreadt stored previously
			return ;
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

