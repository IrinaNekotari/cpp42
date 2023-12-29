#include "Harl.hpp"

int main(void)
{
    std::string s;
    Harl    h;
    while (1)
    {
        std::cout << "Niveau a tester : ";
        std::cin >> s;
        if (!s.compare("exit") || !s.compare("EXIT"))
            break ;
        h.complain(s);
    }
    return (0);
}