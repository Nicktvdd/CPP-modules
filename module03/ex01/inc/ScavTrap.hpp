#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
    //default constructor
        ScavTrap(void);
    //string constructor
        ScavTrap(std::string name);
    //copy constructor
        ScavTrap (const ScavTrap &src);
    //assignment operator overload
        ScavTrap &operator=(const ScavTrap &rh_src);
    //destructor
        ~ScavTrap(void);
    //methods
        void    attack(const std::string &target);
        void    guardGate(void);
};

#endif