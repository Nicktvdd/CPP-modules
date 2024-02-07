/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:34:42 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/07 11:34:43 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

//constructor
WrongAnimal::WrongAnimal(void)
{
    std::cout << BLUE << "WrongAnimal is Constructed" << RESET << std::endl;
    this->_type = "WrongAnimal";
}

//copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    std::cout << "WrongAnimal copy constructor" << std::endl;
    *this = src;
    return;
}

//overload operator =
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &src_rh)
{
    std::cout << "WrongAnimal overload operator=" << std::endl;
    if (this != &src_rh)
    {
        this->_type = src_rh._type;
    }
    return (*this);
}

//destructor
WrongAnimal::~WrongAnimal(void)
{
    std::cout << BLUE << "WrongAnimal is Deconstructed" << RESET << std::endl;
    return;
}

//member functions
void WrongAnimal::makeSound(void) const
{
    std::cout << RED << "WrongAnimals can make all sorts of sounds!" << RESET << std::endl;
    return;
}

//get
std::string WrongAnimal::getType(void) const
{
    return (this->_type);
}