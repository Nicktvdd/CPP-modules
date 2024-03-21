/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:32:04 by corellan          #+#    #+#             */
/*   Updated: 2023/06/14 19:43:20 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaList.hpp"
#include "Ice.hpp"
#include <string>

int	main(void)
{
	MateriaList *p;
	MateriaList	*v;
	AMateria *s = new Ice();

	p = new MateriaList(s);
	v = new MateriaList();
	*v = *p;
	p->deleteList();
	v->deleteList();
	delete p;
	delete v;
	return (0);
}