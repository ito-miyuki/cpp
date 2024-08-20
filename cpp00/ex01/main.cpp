/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:21:01 by mito              #+#    #+#             */
/*   Updated: 2024/08/19 12:41:35 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string user_input;

	while (1)
	{
		std::cout << "Please enter ADD, SEARCH or EXIT > ";
		if (std::getline(std::cin, user_input).eof())
			exit(1);
		if (user_input.empty())
			continue ;
		if (user_input == "ADD")
		{
			if (phonebook.add_contact() == false)
				break;
		}
		else if (user_input == "SEARCH")
		{
			if (phonebook.search_contact() == false)
				break;
		}
		else if (user_input == "EXIT")
			break;
		else
			std::cout << "Available commands are: ADD, SEARCH or EXIT" << std::endl;
	}
	return (0);
}
