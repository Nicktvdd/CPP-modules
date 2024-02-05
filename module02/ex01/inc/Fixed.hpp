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
        //Constructors
        Fixed(void);
        Fixed(const int num);
        Fixed(const float num);
        //Copy-copy Assignment
        Fixed (const Fixed &source);
        Fixed& operator=(const Fixed &source);
        //member functs
        float   toFloat(void) const;
        int     toInt(void) const;
        //get-set
        int     getRawBits(void)const;
        void    setRawBits(int const raw);
        //Destructor
        ~Fixed(void);
        
    private:
        int                 _fixed_point;
        static const int    _fract_bits = 8;
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed); 
#endif