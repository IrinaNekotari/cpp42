#include "Harl.hpp"

Harl::Harl(void){}

Harl::~Harl(void){}

void    Harl::debug(void)
{
    std::cout << WHITE << "[" << GREEN << "DEBUG" << WHITE 
                << "] What a beautiful " << BOLD << YELLOW << "day"
                << END << WHITE << " !" << END
                << std::endl;
}

void    Harl::info(void)
{
    std::cout << WHITE << "[" << BLUE << "INFO" << WHITE 
                << "] Are those " << BOLD << CYAN << "clouds"
                << END << WHITE << " ?" << END
                << std::endl;
}

void    Harl::warning(void)
{
    std::cout << WHITE << "[" << YELLOW << "WARNING" << WHITE 
                << "] Looks like " << BOLD << BLUE << "rain"
                << END << WHITE << "." << END
                << std::endl;
}

void    Harl::error(void)
{
    std::cout << WHITE << "[" << RED << "ERROR" << WHITE 
                << "] Dang, it's " << BOLD << RED << "raining"
                << END << WHITE << " :( ." << END
                << std::endl;
}

void Harl::complain(std::string level)
{
    t_func  f[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string cmp[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4 && cmp[i].compare(level))
        i++ ;
    if (i < 4)
        (this->*f[i])();
}