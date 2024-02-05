#include "../inc/Harl.hpp"

Harl::Harl(void)
{
    return;
}

Harl::~Harl(void)
{
    return;
}

void    Harl::complain(std::string level) const
{
    void (Harl::*funct_arr[4])(void) const = 
    {
        &Harl::_debug,
        &Harl::_info,
        &Harl::_warning,
        &Harl::_error
    };

    std::string input[4] = {"debug", "info", "warning", "error"};
    if (level[0] == '\0')
    {
        std::cout<<RED<<"Argument is empty"<<std::endl;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (level == input[i])
        {
            (this->*funct_arr[i])();
            return;
        }
    }
    std::cout<<RED<<"\""<<level<<"\""<<" is not a valid argument"<<std::endl;
}

void Harl::_debug(void) const
{
    std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<<std::endl;
    return;
}

void Harl::_info(void) const
{
    std::cout<<"I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!"<<std::endl;
    return;
}

void Harl::_warning(void) const
{
    std::cout<<"I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month."<<std::endl;
    return;
}

void Harl::_error(void) const
{
    std::cout<<"This is unacceptable! I want to speak to the manager now."<<std::endl;
    return;
}