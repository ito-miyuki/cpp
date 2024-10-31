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

// MateriaSource::~MateriaSource() {
// 	for (int i = 0; i < 4; i++)
// 		delete _inventory[i];
// }

// // Lingy's solution for testing
MateriaSource::~MateriaSource(){
	void*	freeObjects[4] = {nullptr};
	int		freeCount = 0;

	for (int i = 0; i < 4; i++)
	{
		int	checkFree = 0;
		for (int j = 0; j < freeCount; j++)
		{
			if (this->_inventory[i] == freeObjects[j])
			{
				checkFree = 1;
				break;
			}
		}
		if (!checkFree)
		{
			freeObjects[freeCount] = this->_inventory[i];
			delete this->_inventory[i];
			this->_inventory[i] = nullptr;
			freeCount++;
		}
	}
}

// MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
// 	if (this != &other)
// 	{
// 		for (int i = 0; i < 4; i++)
// 		{
// 			delete _inventory[i];
// 			if (other._inventory[i] != nullptr)
// 				_inventory[i] = other._inventory[i]->clone();
// 			else
// 				_inventory[i] = nullptr;
// 		}
// 	}
// 	return (*this);
// }

MateriaSource	&MateriaSource::operator = (const MateriaSource &other){
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i] != nullptr){
			delete this->_inventory[i];
			this->_inventory[i] = nullptr;
		}
		if (other._inventory[i] == nullptr)
			this->_inventory[i] = nullptr;
		else
			this->_inventory[i] = other._inventory[i]->clone();
	}
	return (*this);
}

// void MateriaSource::learnMateria(AMateria* m) {
// 	if (m == nullptr)
// 		return ;

// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (_inventory[i] == nullptr)
// 		{
// 			_inventory[i] = m;
// 			return ;
// 		}
// 	}
// 	delete m;
// }

// // Lingy's solution for testing
void	MateriaSource::learnMateria(AMateria *m){
	if (m == nullptr)
		return ;
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i] == nullptr){
			this->_inventory[i] = m;
			return ;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == m)
			return ;
	}
	delete m;
	m = nullptr;
}

// AMateria* MateriaSource::createMateria(std::string const& type) {
// 	for (int i = 0; i < 4; i++)
// 	{
// 		if (_inventory[i] != nullptr && _inventory[i]->getType() == type)
// 			return (_inventory[i]->clone());
// 	}
// 	return (0);
// }

// Lingyi's solution for testing
AMateria	*MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i] != nullptr
			&& this->_inventory[i]->getType() == type){
				return (this->_inventory[i]->clone());
			}
	}
	return (nullptr);
}

