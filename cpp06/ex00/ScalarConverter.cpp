/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:30:10 by mito              #+#    #+#             */
/*   Updated: 2024/12/13 13:44:38 by mito             ###   ########.fr       */
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


/* different approach*/

// void convertChar(std::string input) {
// 	char c = static_cast<char>(input[0]);

// 	std::cout << "char: '" << c << "'" << std::endl;
// 	std::cout << "int: " << static_cast<int>(c) << std::endl;
// 	std::cout << std::fixed << std::setprecision(1);  // to show fixed number 小数点以下1桁を表示
// 	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
// 	std::cout << "double: " << static_cast<double>(c) << std::endl;
// }

// void convertInt(std::string input) {
//     int number = 0; // do I need to init?

//     try {
//         long temp = std::stol(input); // to prevent overflow, convert it to long
//         if (temp < std::numeric_limits<int>::min() || temp > std::numeric_limits<int>::max()) {
//             std::cout << "int: value out of range" << std::endl; // change to something better
//             return;
//         }
//         number = static_cast<int>(temp); // and then cast temp(long) to Int
//     } catch (const std::exception& e) {
//         std::cout << "int: invalid input" << std::endl; // change to something better
//         return;
//     }

//     if (number >= 0 && number <= 255) {
//         char charNum = static_cast<char>(number);
//         if (isprint(charNum))
//             std::cout << "char: '" << charNum << "'" << std::endl;
//         else
//             std::cout << "char: Non displayable" << std::endl;
//     } else {
//         std::cout << "char: impossible" << std::endl;
//     }

//     std::cout << "int: " << number << std::endl;
//     std::cout << std::fixed << std::setprecision(1);
//     std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
//     std::cout << "double: " << static_cast<double>(number) << std::endl;
// }


// void convertFloat(std::string input) {

// 	float number = 0.0f;
// 	try {
// 		number = std::stof(input);
// 	} catch (const std::exception& e) {
// 		std::cout << "Failed to convert\n";
// 		return ;
// 	}

// 	if ((input == "-inff") || (input == "+inff") || (input == "inff") || (input == "nanf"))
// 	{
// 		std::cout << "char: impossible" << std::endl;
// 		std::cout << "int: " << "impossible" << std::endl;
// 		std::cout << "float: " << input << std::endl;
// 		std::cout << "double: " << static_cast<double>(number) << std::endl;
// 		return ;
// 	}

// 	if (number >= 0 && number <= 255) {
// 		char charNum = static_cast<char>(number);
// 		if (isprint(charNum))
// 			std::cout << "char: '" << charNum << "'" << std::endl;
// 		else
// 			std::cout << "char: Non displayable" << std::endl;
// 	}
// 	else {
// 		std::cout << "char: impossible" << std::endl;
// 	}
// 	std::cout << "int: " << static_cast<int>(number) << std::endl;
// 	std::cout << std::fixed << std::setprecision(1);
// 	std::cout << "float: " << number << "f" << std::endl;
// 	std::cout << "double: " << static_cast<double>(number) << std::endl;
// }

// void convertDouble(std::string input) {

// 	if ((input == "-inf") || (input == "+inf") || (input == "inf") || (input == "nan"))
// 	{
// 		std::cout << "char: impossible" << std::endl;
// 		std::cout << "int: " << "impossible" << std::endl;
// 		std::cout << "float: " << input << "f" << std::endl;
// 		std::cout << "double: " << input << std::endl;
// 		return ;
// 	}

// 	double number = 0.0;
// 	// to prevent overflow or some other invalid case
// 	try {
// 		number = std::stod(input);
// 	} catch (const std::exception& e) {
// 		std::cout << "Failed to convert\n";
// 		return ;
// 	}

// 	if (number >= 0 && number <= 255) {
// 		char charNum = static_cast<char>(number);
// 		if (isprint(charNum))
// 			std::cout << "char: '" << charNum << "'" << std::endl;
// 		else
// 			std::cout << "char: Non displayable" << std::endl;
// 	}
// 	else {
// 		std::cout << "char: impossible" << std::endl;
// 	}
// 	std::cout << "int: " << static_cast<int>(number) << std::endl;
// 	std::cout << std::fixed << std::setprecision(1);
// 	std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
// 	std::cout << "double: " << number << std::endl;
// }

// void print_impossible(void) {
// 	std::cout << "char: impossible" << std::endl;
// 	std::cout << "int: impossible" << std::endl;
// 	std::cout << "float: impossible" << std::endl;
// 	std::cout << "double: impossible" << std::endl;
// }
