# pragma once
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    private:
        FragTrap();
    public:
        FragTrap(std::string name);
        ~FragTrap();
        void    highFivesGuys(void);
};