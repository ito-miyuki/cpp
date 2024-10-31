/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:33:29 by mito              #+#    #+#             */
/*   Updated: 2024/10/31 15:37:14 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : _name("default") {
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const Character& other) : _name(other._name) {
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i] != nullptr)
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

// Character::~Character() {
// 	for (int i = 0; i < 4; i++)
// 		delete _inventory[i];
// }

Character::~Character(){
	for(int i = 0; i < 4; i++){
		if (this->_inventory[i] != nullptr){
			delete this->_inventory[i];
			this->_inventory[i] = nullptr;
		}
	}
}

// Character& Character::operator=(const Character& other) {
// 	if (this != &other)
// 	{
// 		_name = other._name;
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

// Character	&Character::operator = (const Character &other){
// 	if (this == &other)
// 		return (*this);
// 	this->_name = other._name;
// 	for (int i = 0; i < 4; i++){
// 		if (this->_inventory[i] != nullptr){
// 			delete this->_inventory[i];
// 			this->_inventory[i] = nullptr;
// 		}
// 		if (other._inventory[i] == nullptr)
// 			this->_inventory[i] = nullptr;
// 		else
// 			this->_inventory[i] = other._inventory[i]->clone();
// 	}
// 	return (*this);
// }
Character	&Character::operator = (const Character &other){
	if (this == &other)
		return (*this);
	this->_name = other._name;
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

std::string const& Character::getName() const {
	return (this->_name);
}

/*
	eqip materia object to inventory.
	if m is null then that is a invalid item.
	Then find an available slot to equip
*/
void Character::equip(AMateria* m) {
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
	//delete m;
}

/*
	if that idx slot is already empty, then don't do anything.
	otherwise, set it to null
*/
void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	if (_inventory[idx] == nullptr)
		return ;
	else {
		_inventory[idx] = nullptr;
	}
}

/*
	this use method is to use object's use method
*/
void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
		return ;
	if (_inventory[idx] != nullptr)
		_inventory[idx]->use(target);
}

AMateria* Character::getAmateria(int idx) {
	if (idx < 0 || idx > 3)
		return nullptr;
	return (_inventory[idx]);
}
