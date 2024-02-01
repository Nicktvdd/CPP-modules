#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB{

    public:
        HumanB(std::string name);
        ~HumanB(void);
        void    attack(void) const;
        void    setWeapon(Weapon &weapon);
    private:
        Weapon      *_weapon;
        std::string _name;
};

#endif