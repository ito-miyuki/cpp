#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
{
    this->type = weaponType;
}

const std::string& Weapon::getType(void)
{
    return (this->type);
}

void Weapon::setType(std::string newType)
{
    this->type = newType;
}