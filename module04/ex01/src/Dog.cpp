/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:34:01 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/07 11:34:02 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

//constructor
Dog::Dog(void)
{
    std::cout << BLUE << "Dog is Constructed" << RESET << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
}

//copy constructor
Dog::Dog(const Dog &src)
{
    std::cout << BLUE << "Dog copy constructor" << RESET << std::endl;
    *this = src;
    return;
}

//overload operator =
Dog& Dog::operator=(const Dog &src_rh)
{
    std::cout << BLUE << "Dog overload operator=" << RESET << std::endl;
    if (this != &src_rh)
    {
        this->_type = src_rh._type;
        this->_brain = new Brain ();
        *this->_brain = *src_rh._brain;
    }
    return (*this);
}

//destructor
Dog::~Dog(void)
{
    std::cout << BLUE << "Dog is Deconstructed" << RESET << std::endl;
    delete this->_brain;
    return;
}

//member functions
void Dog::makeSound(void) const
{
    std::cout << RED << "Woof Woof" << RESET << std::endl;
    return;
}