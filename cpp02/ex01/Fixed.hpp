/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:54:19 by mito              #+#    #+#             */
/*   Updated: 2024/10/17 17:36:20 by mito             ###   ########.fr       */
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
		Fixed(); // Default constructor
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& other); // Copy constructor
		~Fixed(); // Destructor
		Fixed& operator=(const Fixed& other); // Copy assignment operator
		int	getRawBits(void) const;
		void setRawBits( int const raw );
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& output, const Fixed& num);

#endif
