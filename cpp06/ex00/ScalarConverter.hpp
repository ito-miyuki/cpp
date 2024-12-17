/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:30:16 by mito              #+#    #+#             */
/*   Updated: 2024/12/17 10:26:01 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <cctype>
# include <exception>
#include <limits>
#include <iostream>
#include <iomanip>

enum e_literals {
	CHAR, // 0
	INT, // 1
	FLOAT, // 2
	DOUBLE, // 3
	NONE // 4
};

class ScalarConverter {

    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& other);

        ScalarConverter& operator=(const ScalarConverter& other);

	public:
		static void convert(const std::string& input);

};

bool isInt(std::string input);
bool isDouble(std::string input);
bool isFloat(std::string input);
void convertChar(std::string input, char& c, int& i, float& f, double&d);
bool convertInt(std::string input, char& c, int& i, float& f, double& d);
bool convertFloat(std::string input, char& c, int& i, float& f, double& d);
bool convertDouble(std::string input, char& c, int& i, float& f, double& d);
e_literals getType(const std::string& input);
void printChar(char c, int i);
void printInt(int i, double d);
void printResult(char& c, int& i, float& f, double& d);

#endif
