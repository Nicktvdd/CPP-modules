/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:43:43 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:43:44 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon{

    public:
        Weapon(std::string type);
        ~Weapon(void);
        const std::string &getType(void) const;
        void        setType(std::string new_type);
    private:
        std::string _type;
};

#endif