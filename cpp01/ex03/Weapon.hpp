#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
    private:
        std::string type;

    public:
        Weapon(std::string weaponType);
        const   std::string& getType(void);
        void    setType(std::string newType);
};

#endif