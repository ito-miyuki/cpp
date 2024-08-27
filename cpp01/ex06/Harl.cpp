/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:20:28 by mito              #+#    #+#             */
/*   Updated: 2024/08/27 11:50:00 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain( std::string level )
{
	int i = 0;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            break; ;
    }

	switch (i)
	{
		case 0:
			debug();
			info();
			warning();
			error();
			break;

		case 1:
			info();
			warning();
			error();
			break;

		case 2:
			warning();
			error();
			break;

		case 3:
			error();
			break;

		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

void Harl::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
	std::cout << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}
