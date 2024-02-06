/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:43:35 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:43:36 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

int main ()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << "\n---------------" << std::endl;
    std::cout << std::setw(40) << std::left << "Memory Adress of the string variable: " << &brain << std::endl;
    std::cout << std::setw(40) << std::left << "Memory Adress held by stringPTR: " << stringPTR << std::endl;
    std::cout << std::setw(40) << std::left << "Memory Adress held by stringREF: " << &stringREF << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << std::setw(40) << std::left << "Value of the string variable: " << brain << std::endl;
    std::cout << std::setw(40) << std::left << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << std::setw(40) << std::left << "Value pointed to by stringREF: " << stringREF << std::endl;
    std::cout << "---------------\n" << std::endl;

    return (0);
}