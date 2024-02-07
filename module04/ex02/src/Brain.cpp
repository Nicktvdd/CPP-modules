/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvan-den <nvan-den@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:34:32 by nvan-den          #+#    #+#             */
/*   Updated: 2024/02/07 11:34:33 by nvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

//constructor
Brain::Brain(void)
{
    std::cout << BLUE << "Brain is constructed" << RESET << std::endl;
    return;
}

//copy constructor
Brain::Brain(const Brain &src)
{
    std::cout << BLUE << "Brain copy constructor" << RESET << std::endl;
    *this = src;
    return;
}

//operator overload =
Brain &Brain::operator=(const Brain &src_rh)
{
    std::cout << BLUE << "Brain overload operator" << RESET << std::endl;
    if (this != &src_rh)
    {
        for (int i = 0; i < 100; i++)
        {
            this->_ideas[i]=src_rh._ideas[i];
        }
    }
    return (*this);
}

//deconstructor
Brain::~Brain(void)
{
    std::cout << BLUE << "Brain is deconstructed" << std::endl;
    return;
}

//set-get
void Brain::setIdea(std::string idea, int index)
{
    this->_ideas[index] = idea;
    return;
}

std::string Brain::getIdea(int index)
{
    return(this->_ideas[index]);
}