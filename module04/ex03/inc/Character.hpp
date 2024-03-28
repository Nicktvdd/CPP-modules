/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:08:42 by nvan-den          #+#    #+#             */
/*   Updated: 2024/03/28 09:57:59 by nvan-den         ###   ########.fr       */
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