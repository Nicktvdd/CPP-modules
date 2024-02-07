/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:32:22 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/07 11:32:23 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main ()
{
    ClapTrap Good_guy("Vault Hunter");
    ClapTrap Bad_guy;

    Good_guy.stats();
    Bad_guy.stats();

    Good_guy.beRepaired(1);
    Good_guy.attack(Bad_guy.get_name());
    Good_guy.takeDamage(5);
    Good_guy.stats();
    Good_guy.beRepaired(5);
    Good_guy.stats();
    Good_guy.takeDamage(10);
    Good_guy.stats();
    Good_guy.beRepaired(5);
    Good_guy.attack(Bad_guy.get_name());

    for (int i = 0; i <= 10; i++)
        Bad_guy.attack("Someone");
    Bad_guy.beRepaired(10);
    Bad_guy.stats();
    return (0);
}