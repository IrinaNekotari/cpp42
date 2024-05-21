# pragma once
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    private:
        FragTrap();
    public:
        FragTrap(std::string name);
        ~FragTrap();
        FragTrap(const FragTrap& f);
        FragTrap& operator=(const FragTrap& f);
        void    highFivesGuys(void);
};