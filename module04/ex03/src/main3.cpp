/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:44:03 by corellan          #+#    #+#             */
/*   Updated: 2023/06/15 19:51:14 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	AMateria	*ptr;
	AMateria	*cpy;
	Character	*chara;
	Character	*chara2;
	MateriaSource	*sour;
	MateriaSource	*sour2;

	ptr = new Ice();
	cpy = new Cure();

	*ptr = *cpy;
	std::cout << std::endl;
	std::cout << ptr->getType() << std::endl;
	std::cout << cpy->getType() << std::endl;
	std::cout << std::endl;
	delete ptr;
	delete cpy;
	std::cout << std::endl;
	chara = new Character("beto");
	chara->equip(new Ice());
	chara->equip(new Cure());
	std::cout << std::endl;
	chara2 = new Character();
	std::cout << std::endl;
	std::cout << chara->getName() << std::endl;
	chara->printInventory();
	std::cout << chara2->getName() << std::endl;
	chara2->printInventory();
	(*chara2) = *chara;
	std::cout << std::endl;
	std::cout << chara->getName() << std::endl;
	chara->printInventory();
	std::cout << chara2->getName() << std::endl;
	chara2->printInventory();
	std::cout << std::endl;
	delete chara;
	delete chara2;
	std::cout << std::endl;
	sour = new MateriaSource();
	sour2 = new MateriaSource();
	std::cout << std::endl;
	sour->learnMateria(new Ice());
	sour->learnMateria(new Cure());
	std::cout << std::endl;
	sour->printInventory();
	sour2->printInventory();
	std::cout << std::endl;
	*sour2 = *sour;
	std::cout << std::endl;
	sour->printInventory();
	sour2->printInventory();
	std::cout << std::endl;
	delete sour;
	delete sour2;
	return (0);
}