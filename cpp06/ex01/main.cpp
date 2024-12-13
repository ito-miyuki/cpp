/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:41:47 by mito              #+#    #+#             */
/*   Updated: 2024/12/13 15:44:25 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data data;
    data.x = 42;

    uintptr_t serialized = Serializer::serialize(&data);

    Data* deserialized = Serializer::deserialize(serialized);

    // check pointer address
    std::cout << "Original Data pointer: " << &data << std::endl;
	std::cout << "serialized Data pointer: " << serialized << std::endl;
    std::cout << "Deserialized Data pointer: " << deserialized << std::endl;

	if (&data == deserialized)
    	std::cout << "Pointers match: True\n";
	else
		std::cout << "Pointers match: False\n";

	// check data value
    std::cout << "Original data.x = " << data.x << std::endl;
    std::cout << "Deserialized data.x = " << deserialized->x << std::endl;

	if (data.x == deserialized->x)
    	std::cout << "Data match: True\n";
	else
		std::cout << "Data match: False\n";
    return 0;
}
