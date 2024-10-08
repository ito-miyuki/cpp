/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:04:55 by mito              #+#    #+#             */
/*   Updated: 2024/08/19 11:20:11 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

# include "Contact.hpp"

# define CONTACT_MAX 8

class	PhoneBook
{
	public:
		PhoneBook();
		bool	add_contact();
		bool	search_contact();
	private:
		int		current_index;
		Contact contacts[CONTACT_MAX];
};

#endif
