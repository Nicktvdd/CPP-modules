#include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
    return;
}

Zombie::~Zombie(void)
{
    std::cout<<this->_name<<" IS DESTROYED"<<std::endl;
    return;
}

void Zombie::announce(void)
{
    std::cout<<this->_name<<": "<<"BraiiiiiiinnnzzzZ..."<<std::endl;
    return;
}