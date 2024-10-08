#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB
{
    private:
        Weapon* weapon;
        std::string name;
    
    public:
        HumanB(std::string name);
        void attack(void);
        void setWeapon(Weapon& weapon);
};

# endif