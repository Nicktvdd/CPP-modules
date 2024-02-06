#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int main ()
{
    {
        std::cout<<RED<<"----------TEST 1----------"<<RESET<<std::endl<<std::endl;
        FragTrap Good_guy("Rambo");
        FragTrap Bad_guy;

        Good_guy.stats();
        Bad_guy.stats();
        Good_guy.highFivesGuys();
        Good_guy.beRepaired(1);
        Good_guy.attack(Bad_guy.get_name());
        Good_guy.takeDamage(5);
        Good_guy.stats();
        Good_guy.beRepaired(5);
        Good_guy.stats();
        Good_guy.takeDamage(10);
        Good_guy.stats();
        Good_guy.beRepaired(5);
        Good_guy.stats();
        Good_guy.attack(Bad_guy.get_name());

        for (int i = 0; i <= 10; i++)
            Bad_guy.attack("Someone");
        Bad_guy.beRepaired(10);
        Bad_guy.stats();
    }
    {
        std::cout<<std::endl<<std::endl;
        std::cout<<RED<<"----------TEST ALL----------"<<RESET<<std::endl<<std::endl;

        ClapTrap Clappy("Clappy");
        ScavTrap Scavvy ("Scavvy");
        FragTrap Fraggy("Fraggy");

        Clappy.stats();
        Scavvy.stats();
        Fraggy.stats();

    }
    return (0);
}