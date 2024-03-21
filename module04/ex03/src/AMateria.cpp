/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:01:01 by corellan          #+#    #+#             */
/*   Updated: 2023/06/15 19:02:49 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void) : _type("unknown")
{
	std::cout << "Default Constructor for AMateria class called" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const &rhs)
{
	std::cout << "Copy constructor for AMateria class called" << std::endl;
	*this = rhs;
	return ;
}

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
	std::cout << "Constructor for AMateria class called, passing " << type << " as parameter" << std::endl;
	return ;
}

AMateria::~AMateria(void)
{
	std::cout << "Default Destructor for AMateria class called" << std::endl;
	return ;
}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	std::cout << "Copy assigment operator for AMateria class called" << std::endl;
	if (this != &rhs)
	{
		if (this->getType().compare(rhs.getType()) != 0)
		{
			std::cout << "Both pointers have a different type of Materia. The copy is not possible" << std::endl;
			return (*this);
		}
		this->_type = rhs.getType();
	}
	return (*this);
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "If you are trying to attack " << target.getName() << " with " << this->_type << ", it means that something is wrong" << std::endl;
	return ;
}
