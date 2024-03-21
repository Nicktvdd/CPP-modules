/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:25:22 by corellan          #+#    #+#             */
/*   Updated: 2023/06/14 10:09:53 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "Default constructor for the Ice class called" << std::endl;
	return ;
}

Ice::Ice(Ice const &rhs)
{
	std::cout << "Copy constructor for the Ice class called" << std::endl;
	*this = rhs;
	return ;
}

Ice::~Ice(void)
{
	std::cout << "Default destructor for the Ice class called" << std::endl;
	return ;
}

Ice	&Ice::operator=(Ice const &rhs)
{
	std::cout << "Copy assigment operator for the Ice class called" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	AMateria	*pointer = new Ice();
	return (pointer); 
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}
