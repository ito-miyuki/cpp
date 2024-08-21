#ifndef ZONBIE_HPP
# define ZONBIE_HPP

#include <iostream>
#include <string.h>

class Zombie
{
    public:
        void announce(void);
        Zombie(std::string);
        ~Zombie(void);

    private:
        std::string name;
};

#endif