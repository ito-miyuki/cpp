/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:58:28 by mito              #+#    #+#             */
/*   Updated: 2024/10/29 17:04:56 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

// class MateriaSource : public IMateriaSource {
// 	private:
// 		AMateria* _inventory[4];
// 	public:
// 		MateriaSource();
// 		MateriaSource(const MateriaSource& other);
// 		~MateriaSource() override;
// 		MateriaSource& operator=(const MateriaSource& other);
// 		void learnMateria(AMateria*) override;
// 		AMateria* createMateria(std::string const & type);
// }

// it doesn't have to call IMateria's constructor because IMateria is an interface
MateriaSource::MateriaSource() {
	std::cout << "MateriaSource constructor called\n";
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	std::cout << "MateriaSource copy constructor called\n";
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i] != nullptr)
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

// modify this one
MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called\n";
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	std::cout << "MateriaSource copy assignment operator called\n";
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
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (_inventory[i] == m)
	// 		return ;
	// }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != 0 && _inventory[i]->getType() == type)
			return (_inventory[i]->clone());
	}
	return (0);
}
