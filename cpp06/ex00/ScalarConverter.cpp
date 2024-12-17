/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:30:10 by mito              #+#    #+#             */
/*   Updated: 2024/12/17 10:18:40 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return (*this);
}

void ScalarConverter::convert(const std::string& input) {

	char c = 0;
	int	i = 0;
	float f = 0.0f;
	double d = 0.0;

	e_literals type;

	type = getType(input);
	switch (type) {
		case 0:
			convertChar(input, c, i, f, d);
			break;
		case 1:
			if (convertInt(input, c, i, f, d) == false)
				return ;
			break;
		case 2:
			if (convertFloat(input, c, i, f, d) == false)
				return ;
			break;
		case 3:
			if (convertDouble(input, c, i, f, d) == false)
				return ;
			break;
		default:
			std::cout << "Invalid input" << std::endl;
			return ;
	}
	printResult(c, i, f, d);
}
