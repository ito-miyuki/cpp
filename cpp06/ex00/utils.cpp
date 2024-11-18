/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:57:45 by mito              #+#    #+#             */
/*   Updated: 2024/11/18 11:44:23 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool is_int(std::string input) {
	int i = 0;
	if (input[0] == '-')
		i++;
	while (input[i]) {
		if (!isdigit(input[i]))
			return false;
		i++;
	}
	return true;
}

bool is_float(std::string input) {
	if (input[input.length() - 1] == 'f') {
		for (int i = 0; input[i] ; i++) {
			if (input[i] == '.')
				return true;
		}
	}
	return false;
}

bool is_double(std::string input) {
	for (int i = 0; input[i]; i++) {
		if (input[i] == '.') {
			if (input[input.length()] == 'f')
				return false;
			else
				return true;
		}
	}
	return false;
}

e_literals getType(const std::string input) {
	// if (input == nullptr)
	if (input.length() == 0)
		return NONE;
	if (input.length() == 1 && !std::isdigit(input[0]))
		return CHAR;
	else if (is_int(input))
		return INT;
	else if (is_float(input))
		return FLOAT;
	else if (is_double(input))
		return DOUBLE;
	return NONE;
}

