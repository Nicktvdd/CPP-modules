/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:43:48 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:43:49 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
    this->_weapon = nullptr;
    return;
}

HumanB::~HumanB(void)
{
    return;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    return;
}

void    HumanB::attack(void) const
{
    if (this->_weapon == nullptr)
        std::cout<<this->_name<<" doesn't have any weapon!"<<std::endl;
    else
        std::cout<<this->_name<<" attacks with their "<<(*_weapon).getType()<<std::endl;
    return;
}