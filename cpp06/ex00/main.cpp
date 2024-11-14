/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:27:38 by mito              #+#    #+#             */
/*   Updated: 2024/11/14 15:04:01 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream> // delete it


e_literals getType(const std::string& input);


int main() {
	//ScalarConverter scalar;

	std::cout << getType("a") << std::endl;
	std::cout << getType("0.3") << std::endl;
	std::cout << getType("7") << std::endl;

}
