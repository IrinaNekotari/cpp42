# pragma once
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        ScavTrap();
    public:
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(const ScavTrap& s);
        ScavTrap& operator=(const ScavTrap& s);
        void    guardGate(void);
        void    attack(const std::string& target);
};