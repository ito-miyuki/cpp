#include "Animal.hpp"

int main()
{
    Animal animal;
    animal.makeSound();
	std::cout << animal.getType() << " " << std::endl;

    Animal yaya("yaya");
    yaya.makeSound();
	std::cout << yaya.getType() << " " << std::endl;
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();
    return 0;
}

