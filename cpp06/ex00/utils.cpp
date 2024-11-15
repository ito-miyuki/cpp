/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:57:45 by mito              #+#    #+#             */
/*   Updated: 2024/11/15 17:40:55 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool is_int(std::string input) {
	for (int i = 0; input[i] ; i++) {
		if (!isdigit(input[i]))
			return false;
	}
}

bool is_float(std::string input) {

}

e_literals getType(const std::string& input) {
	if (!input)
		return NONE;
	if (input.length() == 1 && !std::isdigit(input[0]))
		return CHAR;
	else if (is_int(input))
		return INT;
	else if (is_float(input))
		return FLOAT;
}
