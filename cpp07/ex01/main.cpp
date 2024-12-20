/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:18:01 by mito              #+#    #+#             */
/*   Updated: 2024/12/20 12:59:04 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

int main() {

	int intArr[] = {1, 2, 3, 4, 5};
	std::string stringArr[] = {"Hello", "world", "from", "Hive Helsinki"};
	char charArr[] = {'a', 'b', 'c'};

	iter(intArr, 5, printArr); // print out intArr

	std::cout << "---" << std::endl;

	iter(stringArr, 4, printArr); // print out stringArr

	std::cout << "---" << std::endl;

	iter(intArr, 5, incrementArr); // increment int and output
	iter(intArr, 5, printArr);

	std::cout << "---" << std::endl;

	iter(intArr, 5, incrementArr); // increment int again and output
	iter(intArr, 5, printArr);

	std::cout << "---" << std::endl;

	iter(charArr, 3, printArr); // print out charArr
	iter(charArr, 3, incrementArr); // in crement char
	std::cout << "increment char array" << std::endl;
	iter(charArr, 3, printArr); // print out result

	return 0;
}
