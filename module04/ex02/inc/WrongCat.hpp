/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:34:26 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/07 11:34:27 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal
{

    public:
        //constructor
        WrongCat (void);
        //copy constructor
        WrongCat (const WrongCat &src);
        //overload operator =
        WrongCat& operator = (const WrongCat &src_rh);
        //deconstructor
        ~WrongCat (void);

        //member functions
        void makeSound(void) const;
};

#endif