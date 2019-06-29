#ifndef NINJATRAP_HPP
#define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap {
    public:
        NinjaTrap(void);
        NinjaTrap(std::string);
        NinjaTrap(NinjaTrap const &);
        NinjaTrap &operator=(NinjaTrap const &);
        ~NinjaTrap(void);

        void rangedAttack(std::string const &target);
		void meleeAttack(std::string const &target);
        
        void ninjaShoebox(std::string const &target);
        void ninjaShoebox(ClapTrap const &target);
        void ninjaShoebox(FragTrap const &target);
        void ninjaShoebox(ScavTrap const &target);
        void ninjaShoebox(NinjaTrap const &target);
};

#endif