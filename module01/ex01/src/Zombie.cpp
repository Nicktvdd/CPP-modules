/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:43:27 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:43:28 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie(void)
{
    return;
}

Zombie::~Zombie(void)
{
    std::cout<<this->_name<<" IS DESTROYED"<<std::endl;
    return;
}

void    Zombie::set_name(std::string name)
{
    this->_name = name;
}

void    Zombie::announce(void)
{
    std::cout<<this->_name<<": "<<"BraiiiiiiinnnzzzZ..."<<std::endl;
    return;
}