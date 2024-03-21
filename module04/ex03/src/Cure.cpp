/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:01:50 by corellan          #+#    #+#             */
/*   Updated: 2023/06/15 17:19:35 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Default constructor for the Cure class called" << std::endl;
	return ;
}

Cure::Cure(Cure const &rhs)
{
	std::cout << "Copy constructor for the Cure class called" << std::endl;
	*this = rhs;
	return ;
}

Cure::~Cure(void)
{
	std::cout << "Default destructor for the Cure class called" << std::endl;
	return ;
}

Cure	&Cure::operator=(Cure const &rhs)
{
	std::cout << "Copy assigment operator for the Cure class called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	AMateria	*pointer = new Cure();
	return (pointer); 
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}
