#include "Human.hpp"

void Human::meleeAttack(std::string const & target)
{
	std::cout << target << " was damaged by melee attack" << std::endl;
}

void Human::rangedAttack(std::string const & target)
{
	std::cout << target << " was damaged by ranged attack" << std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
	std::cout << target << "'s morale was decreased by intimidating shout" << std::endl;
}

void Human::action(std::string const & action_name, std::string const & target)
{
	std::string fnNames[] = {"meleeAttack", "rangedAttack", "intimidatingShout"};

    typedef void (Human::*ActionsFn)(std::string const & target);
    ActionsFn actions[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};

	for (int i = 0; i < 3; i++)
	{
		if (fnNames[i] == action_name)
		{
			(this->*(actions[i]))(target);
			return;
		}
	}
}