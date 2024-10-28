/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:56:12 by mito              #+#    #+#             */
/*   Updated: 2024/10/28 15:50:22 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Default Brain constructor called\n";
	for(int i = 0; i < 100; i++)
		this->_ideas[i] = "";
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called\n";
	for(int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
}

Brain::~Brain() {
	std::cout << "Brain destructor called\n";
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain copy assignment operator called\n";
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return (*this);
}

std::string Brain::getIdea(int index) {
	if (index < 0 || index >= 100)
		return ("Index is out of range(0-99)");
	return (this->_ideas[index]);
}

void Brain::setIdea(int index, std::string idea) {
	if (index < 0 || index >= 100) {
		std::cout << "Index is out of range(0-99)\n";
		return ;
	}
	this->_ideas[index] = idea;
}
