/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:25:45 by corellan          #+#    #+#             */
/*   Updated: 2023/06/13 20:13:27 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const &rhs);
		~Cure(void);

		Cure	&operator=(Cure const &rhs);

		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};

#endif