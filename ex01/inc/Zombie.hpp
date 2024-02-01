#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

    public:
        Zombie(void);
        ~Zombie(void);
        void    announce(void);
        void    set_name(std::string name);
        
    private:
        std::string _name;

};

Zombie*    zombieHorde( int N, std::string name );

#endif