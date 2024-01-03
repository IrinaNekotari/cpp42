# pragma once
# include <iostream>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define BLUE "\x1b[34m"
# define CYAN "\x1b[36m"
# define YELLOW "\x1b[33m"
# define PURPLE "\x1b[35m"
# define WHITE "\x1b[37m"
# define BOLD "\x1b[1m"
# define LINE "\x1b[4m"
# define END "\x1b[0m"

class ClapTrap
{
    protected:
        std::string     name;
        int             hp;
        int             ep;
        int             ap;
        ClapTrap();
    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& c);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& c);
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
};