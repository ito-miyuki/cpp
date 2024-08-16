/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:00:22 by mito              #+#    #+#             */
/*   Updated: 2024/08/15 15:51:10 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : current_index(0) {}

void	list_all_contacts(Contact contact[])
{
	for (int i = 0; i < CONTACT_MAX; i++)
	{
		if (contact[i].get_first_name().empty())
			break;
		std::cout << i + 1;
		std::cout << '|';
		std::cout << contact[i].get_first_name();
		std::cout << '|';
		std::cout << contact[i].get_last_name();
		std::cout << '|';
		std::cout << contact[i].get_nickname() << std::endl;
	}	
}

void print_contact_detail(Contact contact)
{
	std::cout << contact.get_first_name() << std::endl;
	std::cout << contact.get_last_name() << std::endl;
	std::cout << contact.get_nickname() << std::endl;
	std::cout << contact.get_phone_number() << std::endl;
	std::cout << contact.get_darkest_secret() << std::endl;
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
			return (true); // corrent return value? think about it again!
		}
	}
	list_all_contacts(this->contacts);

	while (1)
	{
		std::cout << "Enter the index: ";
		std::getline(std::cin, str_index);
		if (str_index.empty())
			return (false);
		index = stoi(str_index) - 1;
		if (index < 0 || index > CONTACT_MAX) // index >= contact max?
			std::cout << "Index is available between 1 - 8" << std::endl;
		else if (this->contacts[index].get_last_name().empty())
			std::cout << "There is no contact at this index" << std::endl;
		else
			break;
	}
	print_contact_detail(this->contacts[index]);
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
