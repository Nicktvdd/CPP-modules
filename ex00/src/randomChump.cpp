#include "../inc/Zombie.hpp"

void randomChump( std::string name )
{
    Zombie newOne = Zombie(name);
    newOne.announce();
    return;
}