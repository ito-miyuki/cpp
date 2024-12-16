/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:57:45 by mito              #+#    #+#             */
/*   Updated: 2024/12/16 16:44:10 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
	if ((input == "-inff") || (input == "+inff") || (input == "inff") || (input == "nanf"))
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

void convertChar(std::string input, char& c, int& i, float& f, double&d) {
	c = input[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);
}

bool convertInt(std::string input, char& c, int& i, float& f, double& d)
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
}

bool convertFloat(std::string input, char& c, int& i, float& f, double& d)
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
}

bool convertDouble(std::string input, char& c, int& i, float& f, double& d)
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
}

e_literals getType(const std::string& input) {

	int len = input.length();

	if (len == 0)
		return NONE;
	if (len == 1 && !std::isdigit(input[0]))
		return CHAR;
	else if (isInt(input))
		return INT;
	else if (isFloat(input))
		return FLOAT;
	else if (isDouble(input))
		return DOUBLE;
	return NONE;
}

void printChar(char c, int i)
{
	if (i >= 0 && i <= 255 && isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else if (i >= 0 && i <= 255)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

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
