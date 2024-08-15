/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:21:01 by mito              #+#    #+#             */
/*   Updated: 2024/08/15 14:57:38 by mito             ###   ########.fr       */
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
		std::getline(std::cin, user_input);
		if (user_input.empty())
			continue ; // or shoud I stop program by using break?
		if (user_input == "ADD")
		{
			if (phonebook.add_contact() == false)
				break;
			else
				std::cout << "Contact added successfully!" << std::endl;
		}
		else if (user_input == "SEARCH")
			std::cout << "you entered SEARCH" << std::endl; // excute actual comand
		else if (user_input == "EXIT")
			break;
		else
			std::cout << "Available commands are: ADD, SEARCH or EXIT" << std::endl;
	}
}
