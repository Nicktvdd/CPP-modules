/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaList.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:08:42 by corellan          #+#    #+#             */
/*   Updated: 2023/06/14 16:26:11 by corellan         ###   ########.fr       */
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