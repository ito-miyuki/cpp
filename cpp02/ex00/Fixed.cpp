/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:11:31 by mito              #+#    #+#             */
/*   Updated: 2024/10/14 12:10:56 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// constructor
Fixed::Fixed() : FixedPointNum(0)
{
	std::cout << "Default constructor called\n";
}
// destructor
Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

// copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	*this = other; // this calls copy assignment operator
}

// copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		std::cout << "Copy assignment operator called\n";
		this->FixedPointNum = other.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
    return FixedPointNum;
}

void Fixed::setRawBits(int const raw )
{
	this->FixedPointNum = raw;
}
