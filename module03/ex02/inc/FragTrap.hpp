/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:32:43 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/07 11:32:44 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string.h>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
    //default constructor
        FragTrap(void);
    //string constructor
        FragTrap(std::string name);
    //copy constructor
        FragTrap (const FragTrap &src);
    //assignment operator overload
        FragTrap &operator=(const FragTrap &rh_src);
    //destructor
        ~FragTrap(void);
    //methods
        void    attack(const std::string &target);
        void    highFivesGuys(void);
};

#endif