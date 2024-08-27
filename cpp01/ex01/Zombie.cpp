#include "Zombie.hpp"

Zombie::Zombie() : name("default name") {}

Zombie::~Zombie(void)
{
    std::cout << this->name << " destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}
