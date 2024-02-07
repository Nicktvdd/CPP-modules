/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:34:13 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/07 11:34:14 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "colors.hpp"
#include <string>

class Animal
{

    public:
        //constructor
        Animal (void);
        //copy constructor
        Animal (const Animal &src);
        //overload operator =
        Animal& operator = (const Animal &src_rh);
        //destructor - pure virtual - at least one pure function to make the class abstract - constructor cant be made pure
        virtual  ~Animal (void) = 0;

        //member functions
        virtual void makeSound(void) const;
        //get
        std::string getType(void) const;
    protected:
        std::string _type;
};

#endif