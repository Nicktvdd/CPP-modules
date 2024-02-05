/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:43:25 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:43:26 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"


int main ()
{
    int size = 10;
    Zombie  *zombies = zombieHorde(size, "Disco Zombie");

    for (int i = 0; i < size; i++)
        zombies[i].announce();
    delete [] zombies;
    return (0);
}