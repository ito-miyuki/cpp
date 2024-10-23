#include "Animal.hpp"

Animal::Animal() : _type("default") {
        std::cout << "Default Animal constructor called\n";
}

Animal::Animal(std::string type) : _type(type) {
        std::cout << "Animal constructor called: " << type << std::endl;
}

Animal::Animal(const Animal& other) {
        this->_type = other._type;
        std::cout << "Animal copy constructor called\n";
}

Animal::~Animal() {
        std::cout << "Animal Destructor called\n";
}

Animal& Animal::operator=(const Animal& other) {
        std::cout << "Animal copy assignment operator called\n";
        if (this != &other)
                this->_type = other._type;
        return (*this);
}

void Animal::makeSound() const {
        std::cout << this->_type << ": No sounds....\n";
}

std::string Animal::getType() const {
	return (this->_type);
}
