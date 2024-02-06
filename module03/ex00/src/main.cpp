#include "../inc/ClapTrap.hpp"

int main ()
{
    ClapTrap Good_guy("Vault Hunter");
    ClapTrap Bad_guy;

    Good_guy.stats();
    Bad_guy.stats();

    Good_guy.beRepaired(1);
    Good_guy.attack(Bad_guy.get_name());
    Good_guy.takeDamage(5);
    Good_guy.stats();
    Good_guy.beRepaired(5);
    Good_guy.stats();
    Good_guy.takeDamage(10);
    Good_guy.stats();
    Good_guy.beRepaired(5);
    Good_guy.attack(Bad_guy.get_name());

    for (int i = 0; i <= 10; i++)
        Bad_guy.attack("Someone");
    Bad_guy.beRepaired(10);
    Bad_guy.stats();
    return (0);
}