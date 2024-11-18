/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:27:38 by mito              #+#    #+#             */
/*   Updated: 2024/11/18 13:46:57 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream> // delete it


int main() {
	//ScalarConverter scalar;

	std::cout << "CHAR == 0" << std::endl;
	std::cout << getType("a") << std::endl;
	std::cout << getType("C") << std::endl;
	std::cout << getType("f") << std::endl;

	std::cout << "INT == 1" << std::endl;
	std::cout << getType("0") << std::endl;
	std::cout << getType("42") << std::endl;
	std::cout << getType("-42") << std::endl;


	std::cout << "FLOAT == 2" << std::endl;
	std::cout << getType("0.0f") << std::endl;
	std::cout << getType("-4.2f") << std::endl;
	std::cout << getType("4.2f") << std::endl;

	std::cout << "DOUBLE == 3" << std::endl;
	std::cout << getType("0.0") << std::endl;
	std::cout << getType("-4.2") << std::endl;
	std::cout << getType("4.2") << std::endl;

	return (0);
}
