#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include "colors.hpp"
#include <string>

class WrongAnimal
{

    public:
        //constructor
        WrongAnimal (void);
        //copy constructor
        WrongAnimal (const WrongAnimal &src);
        //overload operator =
        WrongAnimal& operator = (const WrongAnimal &src_rh);
        //destructor
        ~WrongAnimal (void);

        //member functions
        void makeSound(void) const;
        //get
        std::string getType(void) const;
    protected:
        std::string _type;
};

#endif