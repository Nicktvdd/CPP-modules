/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:08:42 by nvan-den          #+#    #+#             */
/*   Updated: 2024/03/28 09:58:51 by nvan-den         ###   ########.fr       */
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
