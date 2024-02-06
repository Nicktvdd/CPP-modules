#include "../inc/Cat.hpp"

//constructor
Cat::Cat(void)
{
    std::cout << BLUE << "Cat is Constructed" << RESET << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
}

//copy constructor
Cat::Cat(const Cat &src)
{
    std::cout << BLUE << "Cat copy constructor" << RESET << std::endl;
    *this = src;
    return;
}

//overload operator =
Cat& Cat::operator=(const Cat &src_rh)
{
    std::cout << BLUE << "Cat overload operator=" << RESET << std::endl;
    if (this != &src_rh)
    {
        this->_type = src_rh._type;
        this->_brain = new Brain ();
        *this->_brain = *src_rh._brain;
    }
    return (*this);
}

//destructor
Cat::~Cat(void)
{
    std::cout << BLUE << "Cat is Deconstructed" << RESET << std::endl;
    delete this->_brain;
    return;
}

//member functions
void Cat::makeSound(void) const
{
    std::cout << RED << "Miaaww" << RESET << std::endl;
    return;
}

Brain   *Cat::getBrain(void)
{
    return(this->_brain);
}