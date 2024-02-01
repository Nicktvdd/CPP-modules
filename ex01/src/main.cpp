#include "../inc/Zombie.hpp"


int main ()
{
    int size = 10;
    Zombie  *zombies = zombieHorde(size, "Disco Zombie");

    for (int i = 0; i < size; i++)
        zombies[i].announce();
    delete [] zombies;
    return (0);
}