/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:21:01 by mito              #+#    #+#             */
/*   Updated: 2024/08/15 10:25:23 by mito             ###   ########.fr       */
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
			std::cout << "you entered ADD" << std::endl; // excute actual comand
			phonebook.add_contact(); // might need error handlings
		}
		else if (user_input == "SEARCH")
			std::cout << "you entered SEARCH" << std::endl; // excute actual comand
		else if (user_input == "EXIT")
			break;
		else
			std::cout << "Available commands are: ADD, SEARCH or EXIT" << std::endl;
	}
}
