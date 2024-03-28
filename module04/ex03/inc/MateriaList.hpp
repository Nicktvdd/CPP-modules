/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaList.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:08:42 by nvan-den          #+#    #+#             */
/*   Updated: 2024/03/28 09:58:13 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIALIST_HPP
# define MATERIALIST_HPP

class	AMateria;

class MateriaList
{
	public:

		AMateria	*reserve;
		MateriaList	*next;

		MateriaList(void);
		MateriaList(AMateria *ptr);
		MateriaList(MateriaList const &rhs);
		~MateriaList(void);

		MateriaList	&operator=(MateriaList const &rhs);

		int			sizeList(void);
		void		addNode(AMateria *ptr);
		MateriaList	*getLast(void);
		void		deleteLast(void);
		void		deleteList(void);
		void		printAddressList(void);

};

#endif