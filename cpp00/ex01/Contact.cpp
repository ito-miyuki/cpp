/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:12:09 by mito              #+#    #+#             */
/*   Updated: 2024/08/15 13:36:52 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool Contact::set_first_name(void)
{
	std::cout << "Enter first name: ";
	std::string name;
	getline(std::cin, name);
	if (name.empty())
		return (false);
	this->first_name = name;
	return (true);
}

bool Contact::set_last_name(void)
{
	std::cout << "Enter last name: ";
	std::string name;
	getline(std::cin, name);
	if (name.empty())
		return (false);
	this->last_name = name;
	return (true);
}

bool Contact::set_nickname(void)
{
	std::cout << "Enter nickname: ";
	std::string name;
	getline(std::cin, name);
	if (name.empty())
		return (false);
	this->nickname = name;
	return (true);
}

bool Contact::set_phone_number(void)
{
	std::cout << "Enter phone_number: ";
	std::string phone;
	getline(std::cin, phone);
	if (phone.empty())
		return (false);
	this->phone_number = phone;
	return (true);
}

bool Contact::set_darkest_secret(void)
{
	std::cout << "Enter darkest_secret: ";
	std::string secret;
	getline(std::cin, secret);
	if (secret.empty())
		return (false);
	this->darkest_secret = secret;
	return (true);
}

