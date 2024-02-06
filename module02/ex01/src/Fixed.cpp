/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:44:33 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:44:34 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

// Constructors
Fixed::Fixed() : _fixed_point(0)
{
    std::cout << "Default constructor is called" << std::endl;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int Constructor called" << std::endl;
    this->_fixed_point = num << this->_fract_bits;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float Constructor called" << std::endl;
    this->_fixed_point = roundf(num * (1 << this->_fract_bits));
}

// Copy constructor and assignment operator
Fixed::Fixed(const Fixed &source)
{
    std::cout << "Copy constructor is called" << std::endl;
    *this = source;
}

Fixed& Fixed::operator=(const Fixed &source)
{
    std::cout << "Copy assignment operator is called" << std::endl;
    if (this != &source)
        this->_fixed_point = source.getRawBits();
    return *this;
}

// Member functions
float Fixed::toFloat() const
{
    return static_cast<float>(this->_fixed_point) / (1 << this->_fract_bits);
}

int Fixed::toInt() const
{
    return this->_fixed_point >> this->_fract_bits;
}

// Getters and setters
int Fixed::getRawBits() const
{
    return this->_fixed_point;
}

void Fixed::setRawBits(const int raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixed_point = raw;
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor is called" << std::endl;
}

std::ostream& operator<<(std::ostream &output, const Fixed &object)
{
    output << object.toFloat();
    return output;
}