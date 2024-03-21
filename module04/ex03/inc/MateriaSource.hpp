/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:48:17 by corellan          #+#    #+#             */
/*   Updated: 2023/06/15 19:44:53 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &rhs);
		~MateriaSource(void);

		MateriaSource	&operator=(MateriaSource const &rhs);

		void		learnMateria(AMateria *);
		AMateria	*getMateria(int idx) const;
		AMateria	*createMateria(std::string const &type);
		void		printInventory(void);
	
	private:
		AMateria	*_materias[4];
};

#endif