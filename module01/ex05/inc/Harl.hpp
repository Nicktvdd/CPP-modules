/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:44:06 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/05 10:44:07 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

#define RED    "\033[0;31m"
#define GREEN  "\033[0;32m"
#define BLUE   "\033[0;34m"
#define YELLOW "\033[0;33m"
#define MAGENTA "\033[0;35m"
#define CYAN   "\033[0;36m"
#define WHITE  "\033[1;37m"
#define GRAY   "\033[1;30m"
#define BLACK  "\033[0;30m"
#define DARK_RED   "\033[1;31m"
#define DARK_GREEN "\033[1;32m"
#define DARK_BLUE  "\033[1;34m"
#define DARK_GRAY  "\033[1;30m"
#define RESET "\033[0m"


class Harl{

    public:
        Harl (void);
        ~Harl (void);
        void    complain( std::string level )const;

    private:
        void    _debug(void) const;
        void    _info(void) const;
        void    _warning(void) const;
        void    _error(void) const;

};

#endif