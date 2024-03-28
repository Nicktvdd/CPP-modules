/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:08:42 by nvan-den          #+#    #+#             */
/*   Updated: 2024/03/28 09:59:03 by nvan-den         ###   ########.fr       */
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