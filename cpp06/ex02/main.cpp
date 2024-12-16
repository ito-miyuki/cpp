/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:28:09 by mito              #+#    #+#             */
/*   Updated: 2024/12/16 14:23:03 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <ctime>

int main() {

	std::srand(std::time(0));

	Base* base = generate();
	identify(base);
	identify(*base);
	identify(nullptr);
	delete base;

	std::cout << "\n--test for random--" << std::endl;
	for (int i = 0; i < 5; ++i) {
    Base* randomBase = generate();
    identify(randomBase);
    identify(*randomBase);
    delete randomBase;
    std::cout << "-----" << std::endl;
	}

	return 0;
}
