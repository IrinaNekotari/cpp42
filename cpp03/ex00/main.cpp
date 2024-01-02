#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap c1("Bob");
    ClapTrap c2("Cl4p-Tr4p");
    ClapTrap c3(c1);

    c1.attack("Handsome Jack");
    c1.takeDamage(999);
    c1.beRepaired(8);
    c1.attack("Handsome Jack");
    c1.attack("Handsome Jack");
    c2.attack("Handsome Jack");
    c2.takeDamage(9);
    c2.beRepaired(8);
    return (0);
}
