/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaList.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:08:42 by nvan-den          #+#    #+#             */
/*   Updated: 2024/03/28 09:59:11 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaList.hpp"
#include "AMateria.hpp"

MateriaList::MateriaList(void) : reserve(NULL), next(NULL)
{
	this->reserve = NULL;
	this->next = NULL;
	return ;
}

MateriaList::MateriaList(AMateria *ptr) : reserve(NULL), next(NULL)
{
	this->reserve = ptr;
	return ;
}

MateriaList::MateriaList(MateriaList const &rhs) : reserve(NULL), next(NULL)
{
	MateriaList	*temp;
	MateriaList	*temp2;

	temp = const_cast<MateriaList*>(&rhs);
	temp2 = this;
	if (temp == NULL)
		return ;
	temp2->reserve = temp->reserve->clone();
	while (temp->next != NULL)
	{
		temp2->next = new MateriaList(temp->next->reserve->clone());
		temp = temp->next;
		temp2 = temp2->next;
		temp2->next = NULL;
	}
	return ;
}

MateriaList::~MateriaList(void)
{
	return ;
}

MateriaList	&MateriaList::operator=(MateriaList const &rhs)
{
	MateriaList	*temp;
	MateriaList	*temp2;

	temp2 = this;
	temp = const_cast<MateriaList*>(&rhs);
	if (this != &rhs)
	{
		this->deleteList();
		if (temp == NULL)
			return (*this);
		temp2->reserve = temp->reserve->clone();
		while (temp->next != NULL)
		{
			temp2->next = new MateriaList(temp->next->reserve->clone());
			temp = temp->next;
			temp2 = temp2->next;
			temp2->next = NULL;
		}
	}
	return (*this);
}

int	MateriaList::sizeList(void)
{
	int			i;
	MateriaList	*iter;

	i = 0;
	iter = this;
	while (iter != NULL)
	{
		i++;
		iter = iter->next;
	}
	return (i);
}

void	MateriaList::addNode(AMateria *ptr)
{
	MateriaList	*temp;

	temp = this;
	if (ptr == NULL)
		return ;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new MateriaList(ptr);
	return ;
}

MateriaList	*MateriaList::getLast(void)
{
	MateriaList	*temp;

	temp = this;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	MateriaList::deleteLast(void)
{
	MateriaList	*last;
	MateriaList	*secondLast;

	secondLast = this;
	last = NULL;
	if (this->sizeList() == 1)
		return ;
	while (secondLast->next->next != NULL)
		secondLast = secondLast->next;
	last = this->getLast();
	delete last->reserve;
	delete last;
	secondLast->next = NULL;
	return ;
}

void	MateriaList::deleteList(void)
{
	while (this->sizeList() > 1)
		this->deleteLast();
	delete this->reserve;
	this->reserve = NULL;
}

void	MateriaList::printAddressList(void)
{
	MateriaList	*ptr;

	ptr = this;
	while (ptr != NULL)
	{
		std::cout << ptr << std::endl;
		ptr = ptr->next;
	}
	return ;
}

