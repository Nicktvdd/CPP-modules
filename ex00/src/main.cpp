#include "../inc/Zombie.hpp"

int main ()
{
    Zombie *new_zombie = newZombie("Zombie 1");
    randomChump("Zombie 2");
    
    delete new_zombie;
    return(0);
}