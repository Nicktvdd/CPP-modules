/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:43:05 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:43:06 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

    public:
        Zombie(std::string name);
        ~Zombie(void);
        void announce(void);
        
    private:
        std::string _name;

};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif