/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:49:34 by corellan          #+#    #+#             */
/*   Updated: 2023/06/15 19:24:36 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "MateriaList.hpp"

class Character : public ICharacter
{
	public:

		MateriaList	*list;

		Character(void);
		Character(std::string name);
		Character(Character const &rhs);
		~Character(void);

		Character	&operator=(Character const &rhs);

		std::string const	&getName(void) const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void				use(int idx, ICharacter &target);
		AMateria			*getInventory(int i) const;
		int					getFlag(void) const;
		int					getCounter(void) const;
		void				printInventory(void);
	
	private:

		std::string	_name;
		AMateria	*_inventory[4];
		int			_flag;
		int			_counter;
};

#endif