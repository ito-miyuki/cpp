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
.23f , .312, 1.ab, 1.fab, -0f,  -0.f are invalid.

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

bool isInt(std::string input) {
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

bool isDouble(std::string input) {
	if (input == "-inf" || input == "+inf" || input == "inf" || input == "nan")
        return true;

    size_t i = 0;
    int dotCount = 0;

    if (input[i] == '-')
        i++;
    for (; i < input.length(); i++) {
        if (input[i] == '.') {
			if (input[i + 1])
			    dotCount++;
			else
				return false;
		}
        else if (!isdigit(input[i]))
			return false;      
    }
	if (dotCount == 1)
		return true;
    return false;
}

bool isFloat(std::string input) {
	if ((input == "-inff") || (input == "+inff") || (input == "inff") || (input == "nan"))
		return true;

	size_t i = 0;
    int dotCount = 0;

    if (input[i] == '-')
        i++;
    for (; i < input.length() - 1; i++) {
        if (input[i] == '.') {
			if (input[i + 1])
			    dotCount++;
			else
				return false;
		}
        else if (!isdigit(input[i]))
			return false;      
    }
	if (dotCount == 1 && input[input.length() - 1] == 'f')
			return true;
	return false;
}

void convertChar(std::string input, char& c, int& i, float& f, double&d ) {
	c = input[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
}


bool	convertInt(std::string input, char& c, int& i, float& f, double& d)
{
	try
	{
		i = std::stoi(input);
		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);
	}
	catch (std::exception& e)
	{
		std::cout << "Invalid Int" << std::endl;
		return false;
	}
	return true;
};

bool	convertFloat(std::string input, char& c, int& i, float& f, double& d)
{
	try
	{
		f = std::stof(input);
		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);
	}
	catch (std::exception& e)
	{
		std::cout << "Invalid Float" << std::endl;
		return false;
	}
	return true;
};

bool	convertDouble(std::string input, char& c, int& i, float& f, double& d)
{
	try
	{
		d = std::stod(input);
		c = static_cast<char>(d);
		f = static_cast<float>(d);
		i = static_cast<int>(d);
	}
	catch (std::exception& e)
	{
		std::cout << "Invalid Double" << std::endl;
		return false;
	}
	return true;
};

e_literals getType(const std::string& input) {

	int len = input.length();

	if (len == 0)
		return NONE;
	if (len == 1 && !std::isdigit(input[0]))
		return CHAR;
	else if (isInt(input))
		return INT;
	else if (isDouble(input))
		return DOUBLE;
	else if (isFloat(input))
		return FLOAT;
	return NONE;
}

void printChar(char c, int i )
{
	if (i >= 0 && i <= 255 && isprint(c))
		std::cout << "char: " << c << std::endl;
	else if (i >= 0 && i <= 255)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
};

void printInt(int i, double d) {
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
        std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

}

void printResult(char& c, int& i, float& f, double& d) {

	if (d == i)
		std::cout << std::fixed << std::setprecision(1);
	printChar(c, i);
	printInt(i, d);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
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
			//print_impossible();
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
