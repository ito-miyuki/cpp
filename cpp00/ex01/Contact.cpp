/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:12:09 by mito              #+#    #+#             */
/*   Updated: 2024/08/15 11:22:20 by mito             ###   ########.fr       */
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
