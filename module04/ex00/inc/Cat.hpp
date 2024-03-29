/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:33:03 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/07 11:33:04 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal
{

    public:
        //constructor
        Cat (void);
        //copy constructor
        Cat (const Cat &src);
        //overload operator =
        Cat& operator = (const Cat &src_rh);
        //deconstructor
        ~Cat (void);

        //member functions
        void makeSound(void) const;
};

#endif