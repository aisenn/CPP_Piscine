#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {
    public:
        NinjaTrap(void);
        NinjaTrap(std::string);
        NinjaTrap(NinjaTrap const &);
        ~NinjaTrap(void);

        NinjaTrap &operator=(NinjaTrap const &);

        void rangedAttack(std::string const &target);
		void meleeAttack(std::string const &target);
        
        void ninjaShoebox(ClapTrap &target) const;
        void ninjaShoebox(FragTrap &target) const;
        void ninjaShoebox(ScavTrap &target) const;
        void ninjaShoebox(NinjaTrap &target) const;
};

#endif