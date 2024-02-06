/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:44:31 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:44:32 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
    // Constructors
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    
    // Copy constructor and assignment operator
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    
    // Member functions
    float toFloat() const;
    int toInt() const;
    
    // Getter and setter
    int getRawBits() const;
    void setRawBits(int const raw);
    
    // Destructor
    ~Fixed();
    
private:
    int _fixed_point;
    static const int _fract_bits = 8;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed); 
#endif