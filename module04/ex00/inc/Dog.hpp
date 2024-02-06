#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal
{

    public:
        //constructor
        Dog (void);
        //copy constructor
        Dog (const Dog &src);
        //overload operator =
        Dog& operator = (const Dog &src_rh);
        //deconstructor
        ~Dog (void);

        //member functions
        void makeSound(void) const;
};


#endif