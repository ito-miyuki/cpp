/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mito <mito@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:00:48 by mito              #+#    #+#             */
/*   Updated: 2024/10/28 12:57:10 by mito             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>


void arrTest() {
	const int size = 7;
	Animal* animalArr[size];

	std::cout << "\n***arrTest***\n";
	for (int i = 0; i < (size / 2); i++) {
		animalArr[i] = new Cat();
	}

	for (int i = (size / 2); i < size; i++) {
		animalArr[i] = new Dog();
	}

	for (int i = 0; i < size; i++) {
		animalArr[i]->makeSound();
	}
	std::cout << std::endl;

	for (int i = 0; i < size; i++) {
		delete animalArr[i];
	}
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;
}

void deepCopyCat() {
	std::cout << "\n***deepCopyCat***\n";
	Cat catOriginal;

	catOriginal.getBrain()->setIdea(0, "Sleep on the counch");
	catOriginal.getBrain()->setIdea(1, "Walk around a yard");

	std::cout << "idea: " << catOriginal.getBrain()->getIdea(0) << std::endl;
	std::cout << "idea: " << catOriginal.getBrain()->getIdea(1) << std::endl;

	Cat copyCat = catOriginal;

	std::cout << "copied idea: " << copyCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "copied idea: " << copyCat.getBrain()->getIdea(1) << std::endl;

	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;
}

void deepCopyDog() {
	std::cout << "\n***deepCopyDog***\n";
	Dog dogOriginal;

	dogOriginal.getBrain()->setIdea(0, "Play with owner");
	dogOriginal.getBrain()->setIdea(1, "Eat ham");
	dogOriginal.getBrain()->setIdea(1, "sleep in a bed");
	// test for index that is out of range
	dogOriginal.getBrain()->setIdea(99, "bark at neighbors");

	std::cout << "idea: " << dogOriginal.getBrain()->getIdea(0) << std::endl;
	std::cout << "idea: " << dogOriginal.getBrain()->getIdea(1) << std::endl;
	std::cout << "idea: " << dogOriginal.getBrain()->getIdea(2) << std::endl;

	Dog copyDog = dogOriginal;

	std::cout << "copied idea: " << copyDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "copied idea: " << copyDog.getBrain()->getIdea(1) << std::endl;
	std::cout << "copied idea: " << copyDog.getBrain()->getIdea(2) << std::endl;

	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;
}

int main() {

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j; //should not create a leak
	delete i;

	arrTest();
	deepCopyCat();
	deepCopyDog();

	return (0);
}
