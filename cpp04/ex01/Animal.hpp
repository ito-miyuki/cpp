#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal {
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& other);
        virtual ~Animal();

        Animal& operator=(const Animal& other);

        virtual void makeSound() const;
		std::string getType() const;
};

#endif
