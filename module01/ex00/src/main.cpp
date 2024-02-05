/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:43:12 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:43:13 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int main ()
{
    Zombie *new_zombie = newZombie("Zombie 1");
    randomChump("Zombie 2");
    
    delete new_zombie;
    return(0);
}