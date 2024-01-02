#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    ClapTrap c1("Annoying tincan");
    ClapTrap c2("Cl4p-Tr4p");

    c1.attack("Handsome Jack");
    c1.takeDamage(999);
    c1.beRepaired(8);
    c1.attack("Handsome Jack");
    c2.attack("Handsome Jack");
    c2.takeDamage(9);
    c2.beRepaired(8);
    c2.takeDamage(999);
    std::cout << "*Angelic choir*" << std::endl;
    ScavTrap c3("Bob");
    FragTrap c4("BibBoop");
    c3.attack("Handsome Jack");
    c3.guardGate();
    c3.takeDamage(99);
    c3.beRepaired(99);
    for (size_t i = 0; i < 50; i++)
    {
        c3.attack("Handsome Jack");
    }
    std::cout << "*Handsome Jack fucking DIES*" << std::endl;
    c4.highFivesGuys();
    return (0);
}