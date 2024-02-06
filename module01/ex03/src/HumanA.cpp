/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:43:45 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:43:46 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) :_weapon(weapon)
{
    this->_name = name;
    return;
}

HumanA::~HumanA(void)
{
    return;
}

void    HumanA::attack(void) const
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
    return;
}