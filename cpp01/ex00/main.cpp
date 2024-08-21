#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
    Zombie *zombie = newZombie("Zeds");
    zombie->announce();
    delete zombie;

    randomChump("Lisa");
    return (0);
}