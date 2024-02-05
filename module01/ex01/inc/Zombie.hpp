/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:43:22 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:43:23 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

    public:
        Zombie(void);
        ~Zombie(void);
        void    announce(void);
        void    set_name(std::string name);
        
    private:
        std::string _name;

};

Zombie*    zombieHorde( int N, std::string name );

#endif