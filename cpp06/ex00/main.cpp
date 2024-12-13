/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:27:38 by mito              #+#    #+#             */
/*   Updated: 2024/11/19 13:37:34 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream> // for testing. you might need to delete it


// void getTypeTest() {
// 	std::cout << "CHAR == 0" << std::endl;
// 	std::cout << getType("a") << std::endl;
// 	std::cout << getType("C") << std::endl;
// 	std::cout << getType("f") << std::endl;

// 	std::cout << "INT == 1" << std::endl;
// 	std::cout << getType("0") << std::endl;
// 	std::cout << getType("42") << std::endl;
// 	std::cout << getType("-42") << std::endl;


// 	std::cout << "FLOAT == 2" << std::endl;
// 	std::cout << getType("0.0f") << std::endl;
// 	std::cout << getType("-4.2f") << std::endl;
// 	std::cout << getType("4.2f") << std::endl;
// 	std::cout << getType("-inff") << std::endl;
// 	std::cout << getType("+inff") << std::endl;
// 	std::cout << getType("nanf") << std::endl;

// 	std::cout << "DOUBLE == 3" << std::endl;
// 	std::cout << getType("0.0") << std::endl;
// 	std::cout << getType("-4.2") << std::endl;
// 	std::cout << getType("4.2") << std::endl;
// 	std::cout << getType("-inf") << std::endl;
// 	std::cout << getType("+inf") << std::endl;
// 	std::cout << getType("nan") << std::endl;
// }

int main(int argc, char* argv[]) {
	//getTypeTest();
	if (argc != 2) {
		std::cout << "Wrong argument number. Input should be: ./scalarconverter <value>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
