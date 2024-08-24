#include "HumanB.hpp"

HumanB::HumanB(std::string name) : weapon(nullptr), name(name) {}

void HumanB::attack(void)
{
    if (weapon && !this->weapon->getType().empty())
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " does not have a weapon " << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}