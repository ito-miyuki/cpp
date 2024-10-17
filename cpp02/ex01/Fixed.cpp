/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:11:31 by mito              #+#    #+#             */
/*   Updated: 2024/10/17 17:30:13 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : fixedPointNum(0)
{
	std::cout << "Default constructor called\n";
}

// Int constructor
Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called\n";
	this->fixedPointNum = num << fractionalBits;
}
 // Float constructor: Float num => Fixed point num
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	this->fixedPointNum = static_cast<int>(roundf(num * (1 << fractionalBits)));
	std::cout << "float=" << num << ", fixedPointNum=" << this->fixedPointNum << std::endl;
}
// copy constructor
Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

// copy assignment operator
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		std::cout << "Copy assignment operator called\n";
		this->fixedPointNum = other.getRawBits();
	}
	return (*this);
}

// destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
    return fixedPointNum;
}

void Fixed::setRawBits(int const raw )
{
	this->fixedPointNum = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(fixedPointNum) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return fixedPointNum >> fractionalBits;
}

std::ostream&	operator<<(std::ostream& output, const Fixed& num)
{
	output << num.toFloat();
	return output;
}

