#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main()
{
    Zombie *horde;
    int num_zombies = 10;
    std::string zombie_name = "Larry";

    horde = zombieHorde(num_zombies, zombie_name);
    for (int i = 0; i < num_zombies; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}