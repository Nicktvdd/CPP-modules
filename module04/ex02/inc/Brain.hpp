#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "colors.hpp"
#include <iostream>

class Brain
{
    public:
        //constructpr
        Brain (void);
        //copy constructor
        Brain (const Brain &src);
        //overload operator =
        Brain &operator=(const Brain &src_rh);
        //deconstructor
        ~Brain(void);

        //set-get
        void        setIdea(std::string idea, int index);
        std::string getIdea(int index);
    private:
        std::string _ideas[100];


};


#endif