/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:08:42 by nvan-den          #+#    #+#             */
/*   Updated: 2024/03/28 09:58:55 by nvan-den         ###   ########.fr       */
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
