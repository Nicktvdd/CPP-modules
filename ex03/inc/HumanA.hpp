#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA{

    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void    attack(void) const;
    private:
        Weapon      &_weapon;
        std::string _name;
};

#endif