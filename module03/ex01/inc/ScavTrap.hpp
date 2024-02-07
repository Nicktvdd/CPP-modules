/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:32:28 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/07 11:32:29 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
    //default constructor
        ScavTrap(void);
    //string constructor
        ScavTrap(std::string name);
    //copy constructor
        ScavTrap (const ScavTrap &src);
    //assignment operator overload
        ScavTrap &operator=(const ScavTrap &rh_src);
    //destructor
        ~ScavTrap(void);
    //methods
        void    attack(const std::string &target);
        void    guardGate(void);
};

#endif