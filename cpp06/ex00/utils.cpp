/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:57:45 by mito              #+#    #+#             */
/*   Updated: 2024/11/14 14:58:20 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

e_literals getType(const std::string& input) {
	if (input.length() == 1 && !std::isdigit(input[0]))
		return CHAR;
	else
		return NONE;
}
