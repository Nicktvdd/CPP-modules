#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{

    public:
        //constructor
        WrongCat (void);
        //copy constructor
        WrongCat (const WrongCat &src);
        //overload operator =
        WrongCat& operator = (const WrongCat &src_rh);
        //deconstructor
        ~WrongCat (void);

        //member functions
        void makeSound(void) const;
};

#endif