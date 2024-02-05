/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:44:47 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:44:48 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

#include <iostream>
int main( void ) 
{
    { 
        std::cout<<RED<<"*****TEST 1*****"<<RESET<<std::endl;
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl<<std::endl;
    }
    {   
        std::cout<<RED<<"*****TEST 2*****"<<RESET<<std::endl;
        Fixed a(1.5f);
        Fixed b(2.5f);

        std::cout<<GREEN<< "a:" <<RESET<<std::endl;
        std::cout<< a <<std::endl<<std::endl;

        std::cout<<GREEN<< "b:" <<RESET<<std::endl;
        std::cout<< b <<std::endl<<std::endl;

        std::cout<<GREEN<< "a < b:" <<RESET<<std::endl;
        std::cout<< (a < b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a > b:" <<RESET<<std::endl;
        std::cout<< (a > b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a <= b:" <<RESET<<std::endl;
        std::cout<< (a <= b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a >= b:" <<RESET<<std::endl;
        std::cout<< (a >= b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a == b:" <<RESET<<std::endl;
        std::cout<< (a == b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a != b:" <<RESET<<std::endl;
        std::cout<< (a != b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a + b:" <<RESET<<std::endl;
        std::cout<< (a + b) <<std::endl<<std::endl;


        std::cout<<GREEN<< "a - b:" <<RESET<<std::endl;
        std::cout<< (a - b) <<std::endl<<std::endl;


        std::cout<<GREEN<< "a * b:" <<RESET<<std::endl;
        std::cout<< (a * b) <<std::endl<<std::endl;


        std::cout<<GREEN<< "a / b:" <<RESET<<std::endl;
        std::cout<< (a / b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a++:" <<RESET<<std::endl;
        std::cout<< (a++) <<std::endl;
        std::cout<<GREEN<< "a after ++:" <<RESET<<std::endl;
        std::cout<< (a) <<std::endl<<std::endl;

        std::cout<<GREEN<< "++a:" <<RESET<<std::endl;
        std::cout<< (++a) <<std::endl<<std::endl;

        std::cout<<GREEN<< "a--:" <<RESET<<std::endl;
        std::cout<< (a--) <<std::endl;
        std::cout<<GREEN<< "a after --:" <<RESET<<std::endl;
        std::cout<< (a) <<std::endl<<std::endl;

        std::cout<<GREEN<< "--a:" <<RESET<<std::endl;
        std::cout<< (--a) <<std::endl<<std::endl;

        std::cout<<GREEN<< "find min:" <<RESET<<std::endl;
        std::cout<< a.min(a, b) <<std::endl<<std::endl;

        std::cout<<GREEN<< "find max:" <<RESET<<std::endl;
        std::cout<< b.max(a, b) <<std::endl<<std::endl;


        return 0;   
    }
}