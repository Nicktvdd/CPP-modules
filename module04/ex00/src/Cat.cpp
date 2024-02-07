/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:33:18 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/07 11:33:19 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

//constructor
Cat::Cat(void)
{
    std::cout << BLUE << "Cat is Constructed" << RESET << std::endl;
    this->_type = "Cat";
}

//copy constructor
Cat::Cat(const Cat &src)
{
    std::cout << "Cat copy constructor" << std::endl;
    *this = src;
    return;
}

//overload operator =
Cat& Cat::operator=(const Cat &src_rh)
{
    std::cout << "Cat overload operator=" << std::endl;
    if (this != &src_rh)
    {
        this->_type = src_rh._type;
    }
    return (*this);
}

//destructor
Cat::~Cat(void)
{
    std::cout << BLUE << "Cat is Deconstructed" << RESET << std::endl;
    return;
}

//member functions
void Cat::makeSound(void) const
{
    std::cout << RED << "Miaaww" << RESET << std::endl;
    return;
}