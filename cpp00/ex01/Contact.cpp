/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:12:09 by mito              #+#    #+#             */
/*   Updated: 2024/08/19 15:11:42 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int is_onlyspace(std::string str)
{
	long unsigned int i = 0;
	for (i = 0; i < str.length(); i++)
	{
		if (isspace(str[i]) == 0)
			return (0);
	}
	if (i == str.length())
		return (1);
	return (0);
}


bool Contact::set_first_name(void)
{
	std::string name;
	while (1)
	{
		std::cout << "Enter first name: ";
		if (!getline(std::cin, name))
			return (false);
		if (name.empty() || is_onlyspace(name))
		{
			std::cout << "Contact can’t have empty fields." << std::endl;
			continue;
		}
		break;
	}
	this->first_name = name;
	return (true);
}

bool Contact::set_last_name(void)
{
	std::string name;
	while (1)
	{
		std::cout << "Enter last name: ";
		if (!getline(std::cin, name))
			return (false);
		if (name.empty() || is_onlyspace(name))
		{
			std::cout << "Contact can’t have empty fields." << std::endl;
			continue;
		}
		break;
	}
	this->last_name = name;
	return (true);
}

bool Contact::set_nickname(void)
{
	std::string name;
	while (1)
	{
		std::cout << "Enter nickname: ";
		if (!getline(std::cin, name))
			return (false);
		if (name.empty() || is_onlyspace(name))
		{
			std::cout << "Contact can’t have empty fields." << std::endl;
			continue;
		}
		break;
	}
	this->nickname = name;
	return (true);
}

bool Contact::set_phone_number(void)
{
	std::string phone;
	while (1)
	{
		std::cout << "Enter phone_number: ";
		if (!getline(std::cin, phone))
			return (false);
		if (phone.empty() || is_onlyspace(phone))
		{
			std::cout << "Contact can’t have empty fields." << std::endl;
			continue;
		}
		break;
	}
	this->phone_number = phone;
	return (true);
}

bool Contact::set_darkest_secret(void)
{
	std::string secret;
	while (1)
	{
		std::cout << "Enter darkest_secret: ";
		if (!getline(std::cin, secret))
			return (false);
		if (secret.empty() || is_onlyspace(secret))
		{
			std::cout << "Contact can’t have white space." << std::endl;
			continue;
		}
		break;
	}
	this->darkest_secret = secret;
	return (true);
}

std::string Contact::get_first_name(void)
{
	return (this->first_name);
}

std::string Contact::get_last_name(void)
{
	return (this->last_name);
}

std::string Contact::get_nickname(void)
{
	return (this->nickname);
}

std::string Contact::get_phone_number(void)
{
	return (this->phone_number);
}

std::string Contact::get_darkest_secret(void)
{
	return (this->darkest_secret);
}
