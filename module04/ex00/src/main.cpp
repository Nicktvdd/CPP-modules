/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:33:25 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/07 11:33:26 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/colors.hpp"

int main() 
{
    std::cout << GREEN << "----------animal from animal----------" << RESET << std::endl;
    const Animal *animo = new Animal();
    std::cout << "Type: " << RED << animo->getType() << RESET << std::endl;
    std::cout << "Sound: ";
    animo->makeSound();
    delete animo;
    std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;

    std::cout << GREEN << "----------cat from animal----------" << RESET << std::endl;
    const Animal *kitty = new Cat();
    std::cout << "Type: " << RED << kitty->getType() << RESET << std::endl;
    std::cout << "Sound: ";
    kitty->makeSound();
    delete kitty;
    std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;

    std::cout << GREEN << "----------dog from animal----------" << RESET << std::endl;
    const Animal *doggy = new Dog();
    std::cout << "Type: " << RED << doggy->getType() << RESET << std::endl;
    std::cout << "Sound: ";
    doggy->makeSound();
    delete doggy;
    std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;

    std::cout << GREEN << "----------wrong animal from wrong animal----------" << RESET << std::endl;
    const WrongAnimal *wrongAnimo = new WrongAnimal();
    std::cout << "Type: " << RED << wrongAnimo->getType() << RESET << std::endl;
    std::cout << "Sound: ";
    wrongAnimo->makeSound();
    delete wrongAnimo;
    std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;

    std::cout << GREEN << "----------wrong cat from wrong animal----------" << RESET << std::endl;
    const WrongAnimal *wrongKitty = new WrongCat();
    std::cout << "Type: " << RED << wrongKitty->getType() << RESET << std::endl;
    std::cout << "Sound: ";
    wrongKitty->makeSound();
    delete wrongKitty;
    std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;

    std::cout << GREEN << "----------wrong cat from wrong cat----------" << RESET << std::endl;
    const WrongCat *wrongKitty2 = new WrongCat();
    std::cout << "Type: " << RED << wrongKitty2->getType() << RESET << std::endl;
    std::cout << "Sound: ";
    wrongKitty2->makeSound();
    delete wrongKitty2;
    std::cout << GREEN << "--------------------------" << RESET << std::endl << std::endl;
    return 0;
 }