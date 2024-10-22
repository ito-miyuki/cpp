#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;
    public:
        using ScavTrap::attack;
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);
        ~DiamondTrap();
};

#endif