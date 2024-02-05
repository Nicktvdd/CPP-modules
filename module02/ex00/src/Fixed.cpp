/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:44:24 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:44:25 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout<<"Default constructor called"<<std::endl;
    this->_fixed_point = 0;
    return;
}

Fixed::Fixed (const Fixed &source)
{
    std::cout<<"Copy constructor called"<<std::endl;
    *this = source;
    return;
}

Fixed&  Fixed::operator=(const Fixed &source)
{
    std::cout<<"Copy assignement operator called"<<std::endl;
    if (this != &source)
        this->_fixed_point = source.getRawBits();
    return (*this);
}

Fixed::~Fixed(void)
{
    std::cout<<"Destructor called"<<std::endl;
    return;
}

int Fixed::getRawBits (void) const
{
    std::cout<<"getRawBits member function called"<<std::endl;
    return (this->_fixed_point);
}

void Fixed::setRawBits(int const raw)
{
    std::cout<<"setRawBits member function called"<<std::endl;
    this->_fixed_point = raw;
    return;
}