

        // ~DiamondTrap();

#include "DiamondTrap.hpp"

// we don't declare constructor this time??
// DiamondTrap::DiamondTrap() {

// }

// constructor with param
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
    name = name;
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;

    std::cout << "DiamonTrap constructor called: " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
    //name = name; ??
    std::cout << "DiamondTrap copy constructor called: " << name << std::endl;
}

