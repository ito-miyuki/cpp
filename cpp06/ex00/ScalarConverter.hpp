/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:30:16 by mito              #+#    #+#             */
/*   Updated: 2024/11/19 13:37:12 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <cctype>
# include <stdexcept>

//# include "utils.cpp"

enum e_literals {
	CHAR, // 0
	INT, // 1
	FLOAT, // 2
	DOUBLE, // 3
	NONE // 4
};

class ScalarConverter {

    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& other);

        ScalarConverter& operator=(const ScalarConverter& other);

	public:
		static void convert(const std::string& input);

};

e_literals getType(const std::string& input);

#endif
