#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    public:
		Zombie(void);
        ~Zombie(void);
        void set_name(std::string name);
        void announce(void);

    private:
        std::string name;
};

#endif
