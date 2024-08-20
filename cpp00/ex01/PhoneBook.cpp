/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:00:22 by mito              #+#    #+#             */
/*   Updated: 2024/08/19 12:59:44 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void print_in_format(std::string data)
{
	if (data.length() < 10)
		std::cout << std::setw(10) << data;
	else
		std::cout << std::setw(10) << data.substr(0, 9) + '.';

}
PhoneBook::PhoneBook() : current_index(0) {}

void	list_all_contacts(Contact contact[])
{
	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First name" << "|"
			<< std::setw(10) << "Last name" << "|"
			<< std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < CONTACT_MAX; i++)
	{
		if (contact[i].get_first_name().empty())
			break;
		std::cout << std::setw(10) << i + 1;
		std::cout << '|';
		print_in_format(contact[i].get_first_name());
		std::cout << '|';
		print_in_format(contact[i].get_last_name());
		std::cout << '|';
		print_in_format(contact[i].get_nickname());
		std::cout << std::endl;
	}
}

void print_contact_detail(Contact contact)
{
	std::cout << "First name: " << contact.get_first_name() << std::endl;
	std::cout << "last name: " << contact.get_last_name() << std::endl;
	std::cout << "nickname: " << contact.get_nickname() << std::endl;
	std::cout << "phone number: " << contact.get_phone_number() << std::endl;
	std::cout << "darkest secret: " << contact.get_darkest_secret() << std::endl;
}

bool PhoneBook::search_contact()
{
	std::string str_index;
	int index;

	if (this->current_index == 0)
	{
		if (this->contacts[1].get_first_name().empty())
		{
			std::cout << "There is no contact yet" << std::endl;
			return (true);
		}
	}
	list_all_contacts(this->contacts);

	while (1)
	{
		std::cout << "Enter the index: ";
		if (std::getline(std::cin, str_index).eof())
			exit(1);
		if (str_index.empty())
		{
			std::cout << "Index is available between 1 - 8" << std::endl;
			continue;
		}
		if (str_index.length() != 1)
		{
			std::cout << "Index is available between 1 - 8" << std::endl;
			continue;
		}
		index = atoi(str_index.c_str());
		if (index > CONTACT_MAX || index < 1)
		{
			std::cout << "Index is available between 1 - 8" << std::endl;
			continue;
		}
		if (this->contacts[index - 1].get_first_name().empty())
			std::cout << "There is no contact at this index" << std::endl;
		else
			break;
	}
	print_contact_detail(this->contacts[index - 1]);
	return (true);
}

bool PhoneBook::add_contact(void)
{
	Contact new_contact;

	if (new_contact.set_first_name() == false)
		return (false);
	if (new_contact.set_last_name() == false)
		return (false);
	if (new_contact.set_nickname() == false)
		return (false);
	if (new_contact.set_phone_number() == false)
		return (false);
	if (new_contact.set_darkest_secret() == false)
		return (false);
	this->contacts[this->current_index] = new_contact;
	this->current_index++;
	if (this->current_index >= CONTACT_MAX)
		this->current_index = 0;
	return (true);
}
