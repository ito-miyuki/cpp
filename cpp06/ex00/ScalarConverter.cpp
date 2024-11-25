/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:30:10 by mito              #+#    #+#             */
/*   Updated: 2024/11/19 16:37:58 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <iostream>
#include <exception>

/*
+123 or +12.3f are valid.
.23f , .312, 1.ab, 1.fab, -0f,  -0.fare invalid.

What about -nan, +nan -> invalid, this don't exist)

+inff -> should I print +inff?

hadn't handle overflow

*/

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return (*this);
}

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

bool is_double(std::string input) {
	if (input == "-inf" || input == "+inf" || input == "inf" || input == "nan")
        return true;

    size_t i = 0;
    int dotCount = 0;

    // 最初の文字が符号ならスキップ
    if (input[i] == '-')
        i++;
    // 残りの文字をチェック
    for (; i < input.length(); i++) {
        if (input[i] == '.')
            dotCount++;
        else if (!isdigit(input[i]))
			return false;      
    }
	if (dotCount == 1)
		return true;
    return false;
}

// bool is_float(std::string input) {
// 	if ((input == "-inff") || (input == "+inff") || (input == "inff")|| (input == "nanf"))
// 		return true;
// 	if (input[input.length() - 1] == 'f') {
// 		for (int i = 0; input[i] ; i++) {
// 			if (input[i] == '.')
// 				return true;
// 		}
// 	}
// 	return false;
// }

bool is_float(std::string input) {
	if ((input == "-inff") || (input == "+inff") || (input == "inff") || (input == "nan"))
		return true;
	if (is_double(input)) {
		if (input[input.length() - 1] == 'f')
			return true;
	}
	return false;
}

void to_char(std::string input) {
	char c = static_cast<char>(input[0]);

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);  // to show fixed number 小数点以下1桁を表示
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void to_int(std::string input) {
	int number = std::stoi(input);

	if (number >= 0 && number <= 255) {
		char charNum = static_cast<char>(number);
		if (isprint(charNum))
			std::cout << "char: '" << charNum << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else {
		std::cout << "char: impossible" << std::endl;
	}
	std::cout << "int: " << number << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(number) << std::endl;
}

void to_float(std::string input) {

	float number = 0.0f;
	try {
		number = std::stof(input);
	} catch (const std::exception& e) {
		std::cout << "Failed to convert\n";
		return ;
	}

	if ((input == "-inff") || (input == "+inff") || (input == "inff") || (input == "nanf"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << static_cast<double>(number) << std::endl;
		return ;
	}

	if (number >= 0 && number <= 255) {
		char charNum = static_cast<char>(number);
		if (isprint(charNum))
			std::cout << "char: '" << charNum << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else {
		std::cout << "char: impossible" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(number) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << number << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(number) << std::endl;
}

void to_double(std::string input) {

	if ((input == "-inf") || (input == "+inf") || (input == "inf") || (input == "nan"))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << input << "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return ;
	}

	double number = 0.0;
	try {
		number = std::stod(input);
	} catch (const std::exception& e) {
		std::cout << "Failed to convert\n";
		return ;
	}

	if (number >= 0 && number <= 255) {
		char charNum = static_cast<char>(number);
		if (isprint(charNum))
			std::cout << "char: '" << charNum << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else {
		std::cout << "char: impossible" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(number) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
	std::cout << "double: " << number << std::endl;
}

void print_impossible(void) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

e_literals getType(const std::string& input) {
	// if (input == nullptr)
	if (input.length() == 0)
		return NONE;
	if (input.length() == 1 && !std::isdigit(input[0]))
		return CHAR;
	else if (is_double(input))
		return DOUBLE;
	else if (is_float(input))
		return FLOAT;
	else if (is_int(input))
		return INT;
	return NONE;
}

void ScalarConverter::convert(const std::string& input) {
	e_literals type;

	type = getType(input);
	switch (type) {
		case 0:
			to_char(input);
			break;
		case 1:
			to_int(input);
			break;
		case 2:
			to_float(input);
			break;
		case 3:
			to_double(input);
			break;
		default:
			print_impossible();
			break;
	}
}
