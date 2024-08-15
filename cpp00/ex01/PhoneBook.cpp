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

bool PhoneBook::search_contact()
{
	PhoneBook phonebook;

	if (phonebook.current_index == 0)
		std::cout << "There is no contact yet" << std::endl;
	else
		std::cout << "in development..." << std::endl;
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
	if (this->current_index >= 8) // replace it with CONTACT_MAX
		this->current_index = 0;
	return (true);
}
