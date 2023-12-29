# include "Sed.hpp"

int main(int args, char *argv[])
{
    if (args != 4)
    {
        std::cout << RED << BOLD << "Erreur !" << END << std::endl;
        std::cout << WHITE << "Le programme doit avoir trois (3) arguments !" << END << std::endl;
    }
    else 
    {
        SedObject s(argv[1]);
        s.replace(argv[2], argv[3]);
    }
    return (1);
}