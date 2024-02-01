#include "../inc/Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->_type = type;
    return;
}

Weapon::~Weapon(void)
{
    return;
}

const std::string &Weapon::getType(void) const
{
    return (this->_type);
}

void        Weapon::setType(std::string new_type)
{
    this->_type = new_type;
    return;
}