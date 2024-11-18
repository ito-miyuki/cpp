/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:30:16 by mito              #+#    #+#             */
/*   Updated: 2024/11/18 11:59:32 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
# define SCALARCONVERTER

# include <string>
# include <cctype>
# include <stdexcept>

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
		static void convert(std::string input);

};

// e_literals getType(std::string& input);
e_literals getType(std::string input);

#endif
