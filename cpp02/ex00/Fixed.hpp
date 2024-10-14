/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:54:19 by mito              #+#    #+#             */
/*   Updated: 2024/10/14 12:03:53 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int FixedPointNum;

	public:
		Fixed(); // Default constructor
		Fixed(const Fixed& other); // Copy constructor
		~Fixed(); // Destructor
		Fixed& operator=(const Fixed& other); // Copy assignment operator
		int	getRawBits(void) const;
		void setRawBits( int const raw );
};

#endif
