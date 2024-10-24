#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "**Wrong animal test**\n";
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

	std::cout << "\n---getType()---\n";
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;

	std::cout << "\n---makeSound()---\n";
    cat->makeSound(); // will output the cat sound!
    dog->makeSound();
    animal->makeSound();

	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;
	std::cout << std::endl;

	std::cout << "**Wrong animal test**\n";
	const WrongAnimal*	wrongCat = new WrongCat();

	std::cout << "\n---getType()---\n";
	std::cout << wrongCat->getType() << " " << std::endl;

	std::cout << "\n---makeSound()---\n";
	wrongCat->makeSound(); // will output wrong animal sound!

	std::cout << std::endl;
	delete wrongCat;

    return 0;
}

