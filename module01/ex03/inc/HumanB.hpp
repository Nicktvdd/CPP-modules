/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:43:41 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:43:42 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB{

    public:
        HumanB(std::string name);
        ~HumanB(void);
        void    attack(void) const;
        void    setWeapon(Weapon &weapon);
    private:
        Weapon      *_weapon;
        std::string _name;
};

#endif