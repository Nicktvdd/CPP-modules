/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:43:39 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:43:40 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA{

    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void    attack(void) const;
    private:
        Weapon      &_weapon;
        std::string _name;
};

#endif