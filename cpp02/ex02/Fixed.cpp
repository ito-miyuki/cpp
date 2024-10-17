/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:11:31 by mito              #+#    #+#             */
/*   Updated: 2024/10/16 12:28:40 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed() : fixedPointNum(0) {}

Fixed::Fixed(const int num)
{
	this->fixedPointNum = num << fractionalBits;
}

Fixed::Fixed(const float num)
{
	this->fixedPointNum = static_cast<int>(roundf(num * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

// destructor
Fixed::~Fixed() {}

// copy operator
Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->fixedPointNum = other.getRawBits();
	}
	return (*this);
}

// overloading arithmetic operators
Fixed Fixed::operator+(const Fixed& other)
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other)
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other)
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other)
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

// overloading comparison operator
std::ostream&	operator<<(std::ostream& output, const Fixed& num)
{
	output << num.toFloat();
	return output;
}

bool	Fixed::operator<(const Fixed& other)
{
	return (this->fixedPointNum < other.fixedPointNum);
}

bool	Fixed::operator>(const Fixed& other)
{
	return (this->fixedPointNum > other.fixedPointNum);
}

bool	Fixed::operator==(const Fixed &other)
{
	return (this->fixedPointNum == other.fixedPointNum);
}

bool	Fixed::operator<=(const Fixed &other)
{
	return (this->fixedPointNum <= other.fixedPointNum);
}

bool	Fixed::operator>=(const Fixed &other)
{
	return (this->fixedPointNum >= other.fixedPointNum);
}

bool	Fixed::operator!=(const Fixed &other)
{
	return (this->fixedPointNum != other.fixedPointNum);
}

// pre-increment
Fixed& Fixed::operator++()
{
	this->fixedPointNum += 1;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->fixedPointNum -= 1;
	return (*this);
}

//post-decrement
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->fixedPointNum += 1;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->fixedPointNum -= 1;
	return temp;
}

int Fixed::getRawBits(void) const
{
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

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}
