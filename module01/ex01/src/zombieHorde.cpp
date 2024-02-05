/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:43:29 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:43:30 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie    *zombieHorde( int N, std::string name )
{
    if (N <= 0)
    {
        std::cout<<"Cannot allocate less than 1 Zombie"<<std::endl;
        return (NULL);
    }
    
    Zombie *zombies = new Zombie[N];

    if (!zombies)
    {
        return (NULL);
        std::cout<<"Allocation failed"<<std::endl;
    }
    else
    {
        for (int i = 0; i < N; i++)
            zombies[i].set_name(name);
    }
    return(zombies);
}