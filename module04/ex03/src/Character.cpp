/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:13:25 by corellan          #+#    #+#             */
/*   Updated: 2024/03/21 15:22:07 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character(void) : list(NULL), _name("no_name")
{
	int	i;

	for (i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Default constructor for Character class called" << std::endl;
	return ;
}

Character::Character(std::string name) : list(NULL), _name(name)
{
	int	i;

	for (i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	std::cout << "Constructor for Character class called with the " << name << " name" << std::endl;
	return ;
}

Character::Character(Character const &rhs)  : list(NULL), _name("no_name")
{
	std::cout << "Copy constructor for Character clas called" << std::endl;
	*this = rhs;
	return ;
}

Character::~Character(void)
{
	int	i;

	std::cout << "Default destructor for the Character class called" << std::endl;
	for (i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
	if (list != NULL)
		list->deleteList();
	delete list;
	return ;
}

Character	&Character::operator=(Character const &rhs)
{
	int	i;
	std::cout << "Copy assigment for Character class called" << std::endl;
	if (this != &rhs)
	{
		for (i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
		}
		if (list != NULL)
			delete list;
		for (i = 0; i < 4; i++)
		{
			if (rhs.getInventory(i) != NULL)
				this->_inventory[i] = rhs.getInventory(i)->clone();
			else
				this->_inventory[i] = NULL;
		}
		list = new MateriaList(*rhs.list);
		this->_counter = rhs.getCounter();
		this->_flag = rhs.getFlag();
		this->_name = rhs.getName();
	}
	return (*this);
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	int	i;

	i = 0;
	while (this->_inventory[i] != NULL)
	{
		i++;
		if (i == 4)
		{
			std::cout << this->_name << ". Your inventory is full" << std::endl;
			delete m;
			return ;
		}
	}
	std::cout << this->_name << " has equiped the materia " << m->getType() << " in the slot " << i << std::endl;
	this->_inventory[i] = m;
	this->_flag = 1;
	return ;
}

void	Character::unequip(int idx)
{
	int			i;
	int			counter;

	counter = 0;
	if (idx > 3 || idx < 0)
	{
		if (idx > 3)
			std::cout << "Watch out " << this->_name << "!!, The inventory has only four slot starting from zero" << std::endl;
		else
			std::cout << this->_name << ". Duude!! Are you trying to unequip a negative slot? That isn't possible" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << this->_name << ". This slot is already empty" << std::endl;
		return ;
	}
	std::cout << "Materia unequiped from slot " << idx << " of " << this->_name << " pocket" << std::endl;
	if (list == NULL)
		this->list = new MateriaList(this->_inventory[idx]);
	else
		this->list->addNode(this->_inventory[idx]);
	this->_inventory[idx] = NULL;
	for (i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			counter++;
	}
	if (counter == 0)
		this->_flag = 0;
	return ;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx > 3)
	{
		std::cout << "Watch out " << this->_name << "!!, The inventory has only four slots" << std::endl;
		return ;
	}
	else if (idx < 0)
	{
		std::cout << this->_name << "!! I don't have negative numbers of slots" << std::endl;
		return ;
	}
	if (this->_flag == 0)
	{
		std::cout << this->_name << ". The inventory is empty" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << this->_name << ". The selected slot is empty" << std::endl;
		return ;
	}
	else
		this->_inventory[idx]->use(target);
	return ;
}

void	Character::printInventory(void)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < 4)
	{
		if (this->_inventory[i] != NULL)
			std::cout << "My name is " << this->_name << " and my inventory has " << this->_inventory[i]->getType() << " in the slot " << (i + 1) << std::endl;
		else
			counter++;
		i++;
	}
	if (counter == 4)
		std::cout << "My name is " << this->_name << " but my inventory is empty" << std::endl;
	return ;
}

AMateria	*Character::getInventory(int i) const
{
	return (this->_inventory[i]);
}

int	Character::getFlag(void) const
{
	return (this->_flag);
}

int	Character::getCounter(void) const
{
	return (this->_counter);
}
