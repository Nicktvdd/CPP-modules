/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:08:42 by nvan-den          #+#    #+#             */
/*   Updated: 2024/03/28 09:59:00 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int	main(void)
{
	IMateriaSource	*src = new MateriaSource();
	AMateria		*hello = new Ice();
	AMateria		*hello2 = new Cure();
	AMateria		*hello3 = new Ice();
	MateriaList		*point = new MateriaList(hello);
	point->addNode(hello2);
	point->addNode(hello3);
	point->printAddressList();
	MateriaList		*copy = new MateriaList(*point);
	copy->printAddressList();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter	*me = new Character("me");

	AMateria	*tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(3);
	me->unequip(2);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->unequip(3);
	me->unequip(2);

	ICharacter	*bob = new Character("bob");

	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;
	delete bob;
	delete me;
	delete src;
	point->deleteList();
	copy->deleteList();
	delete point;
	delete copy;
	
	return (0);
}

