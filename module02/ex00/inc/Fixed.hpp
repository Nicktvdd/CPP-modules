/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:44:21 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:44:22 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
public:
    Fixed(void);
    Fixed(const Fixed &source);
    Fixed &operator=(const Fixed &source);
    ~Fixed(void);

    int getRawBits() const;
    void setRawBits(int const raw);

private:
    int _fixed_point = 0;
    static const int _fractional_bits = 8;
};

#endif
