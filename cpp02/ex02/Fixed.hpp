/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:54:19 by mito              #+#    #+#             */
/*   Updated: 2024/10/17 18:04:15 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <ostream>
# include <cmath>

class Fixed
{
	private:
		int fixedPointNum;
		static const int fractionalBits = 8;

	public:
		Fixed();
		explicit Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& other); // Copy constructor
		~Fixed();

		Fixed& operator=(const Fixed& other);

		Fixed operator+(const Fixed& other);
		Fixed operator-(const Fixed& other);
		Fixed operator*(const Fixed& other);
		Fixed operator/(const Fixed& other);

		bool operator<(const Fixed& other);
		bool operator>(const Fixed& other);
		bool operator==(const Fixed &other);
		bool operator<=(const Fixed &other);
		bool operator>=(const Fixed &other);
		bool operator!=(const Fixed &other);


		Fixed& operator++();
		Fixed& operator--();

		Fixed operator++(int);
		Fixed operator--(int);

		int	getRawBits(void) const;
		void setRawBits( int const raw );
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& output, const Fixed& num);

#endif
