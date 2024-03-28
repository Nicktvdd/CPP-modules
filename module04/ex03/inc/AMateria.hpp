/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:08:42 by nvan-den          #+#    #+#             */
/*   Updated: 2024/03/28 09:58:03 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>

class	ICharacter;

class	AMateria
{
	protected:
		std::string	_type;
	
	public:
		AMateria(void);
		AMateria(AMateria const &rhs);
		AMateria(std::string const &type);
		virtual	~AMateria(void);

		AMateria	&operator=(AMateria const &rhs);

		std::string const	&getType(void) const;

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
};

#endif