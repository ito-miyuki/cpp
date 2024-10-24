#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

# include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);
        ~DiamondTrap();

		DiamondTrap& operator=(const DiamondTrap& other);
		void attack(const std::string& target);

		void whoAmI();
};

#endif
