#include "Harl.hpp"

int main(int args, char *argv[])
{
    Harl h;
    if (args != 2)
    {
        std::cout << WHITE << "[" << RED << "ERROR" << END << WHITE << "]" << END << std::endl;
        std::cout << WHITE << "Ce programme a besoin d'un seul et unique argument !" << END << std::endl;
    }
    else
    {
        h.complain(argv[1]);
    }
    return (0);
}