/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:34:44 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/07 11:34:45 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

//constructor
WrongCat::WrongCat(void)
{
    std::cout << BLUE << "WrongCat is Constructed" << RESET << std::endl;
    this->_type = "WrongCat";
}

//copy constructor
WrongCat::WrongCat(const WrongCat &src)
{
    std::cout << "WrongCat copy constructor" << std::endl;
    *this = src;
    return;
}

//overload operator =
WrongCat& WrongCat::operator=(const WrongCat &src_rh)
{
    std::cout << "WrongCat overload operator=" << std::endl;
    if (this != &src_rh)
    {
        this->_type = src_rh._type;
    }
    return (*this);
}

//destructor
WrongCat::~WrongCat(void)
{
    std::cout << BLUE << "WrongCat is Deconstructed" << RESET << std::endl;
    return;
}

//member functions
void WrongCat::makeSound(void) const
{
    std::cout << RED << "Miaaww" << RESET << std::endl;
    return;
}