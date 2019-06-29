#include <iostream>
#include <string>
#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Warrior.hpp"

int main()
{
    Sorcerer robert("Robert", "the Magnificent");

    Victim jim("Jimmy");
    Peon joe("Joe");
    Warrior leonidas("Leonidas");

    std::cout << robert << jim << joe << leonidas;

    robert.polymorph(jim);
    robert.polymorph(joe);
    robert.polymorph(leonidas);

    return 0;
}