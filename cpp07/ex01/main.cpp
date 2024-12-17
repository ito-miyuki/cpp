/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:18:01 by mito              #+#    #+#             */
/*   Updated: 2024/12/17 12:31:45 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

int main() {

	int arr[] = {1, 2, 3, 4, 5};
	std::string arr2[] = {"Hello", "world", "from", "Hive Helsinki"};

	iter(arr, 5, printArr);

	std::cout << "---" << std::endl;
	
	iter(arr2, 4, printArr);

	std::cout << "---" << std::endl;

	iter(arr, 5, incrementArr);
	iter(arr, 5, printArr);

	std::cout << "---" << std::endl;

	iter(arr, 5, incrementArr);
	iter(arr, 5, printArr);

	return 0;
}
