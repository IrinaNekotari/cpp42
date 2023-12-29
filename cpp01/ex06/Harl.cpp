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
    std::string cmp[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4 && cmp[i].compare(level))
        i++ ;
    switch (i)
    {
    case 0: this->debug();
            this->info();
            this->warning();
            this->error();
            break ;
    case 1: this->info();
            this->warning();
            this->error();
            break ;
    case 2: this->warning();
            this->error();
            break ;
    case 3: this->error();
            break;
    default: std::cout << "[####]" << std::endl;
             break;
    }
}