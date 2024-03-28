/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:08:42 by nvan-den          #+#    #+#             */
/*   Updated: 2024/03/28 09:59:14 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	int	i;

	std::cout << "Default constructor for MateriaSource class called" << std::endl;
	for (i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const &rhs)
{
	int	i;

	std::cout << "Copy constructor for MateriaSource class called" << std::endl;
	for (i = 0; i < 4; i++)
	{
		if (rhs.getMateria(i) != NULL)
			this->_materias[i] = rhs.getMateria(i)->clone();
		else
			this->_materias[i] = NULL;
	}
	return ;
}

MateriaSource::~MateriaSource(void)
{
	int	i;

	std::cout << "Default destructor for the MateriaSource class called" << std::endl;
	for (i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	}
	return ;
}

void	MateriaSource::learnMateria(AMateria *ptr)
{
	int	i;

	i = 0;
	while (this->_materias[i] != NULL)
	{
		i++;
		if (i >= 4)
		{
			std::cout << "The materias inventory is full." << std::endl;
			delete ptr;
			return ;
		}
	}
	this->_materias[i] = ptr;
	std::cout << "it has been learnt a " << this->_materias[i]->getType() << " materia, in the slot " << i << std::endl;
	return ;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	AMateria	*ptr;
	int			i;

	i = 0;
	ptr = NULL;
	while (this->_materias[i] != NULL)
	{
		if (this->_materias[i]->getType().compare(type) == 0)
		{
			ptr = this->_materias[i]->clone();
			break ;
		}
		if (i > 3)
			break ;
		i++;
	}
	return (ptr);
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	int	i;

	std::cout << "Copy assigment operator for MateriaSource class called" << std::endl;
	for (i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL)
		{
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
	for (i = 0; i < 4; i++)
	{
		if (rhs.getMateria(i) != NULL)
			this->_materias[i] = rhs.getMateria(i)->clone();
		else
			this->_materias[i] = NULL;
	}
	return (*this);
}

void	MateriaSource::printInventory(void)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < 4)
	{
		if (this->_materias[i] != NULL)
			std::cout << "My inventory of materias has " << this->_materias[i]->getType() << " in the slot " << (i + 1) << std::endl;
		else
			counter++;
		i++;
	}
	if (counter == 4)
		std::cout << "my inventory of materias is empty" << std::endl;
	return ;
}

AMateria	*MateriaSource::getMateria(int idx) const
{
	if (idx > 3 || idx < 0)
		return (NULL);
	return (this->_materias[idx]);
}