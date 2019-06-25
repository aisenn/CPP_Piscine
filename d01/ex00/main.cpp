#include <iostream>
#include <string>
#include "Pony.hpp"

static void ponyOnTheHeap( std::string name, std::string breed, int height, int age )
{
	Pony *pony = new Pony(name, breed, height, age);

	std::cout << "Pony in the heap" << std::endl
			  << "Name: " << pony->getName() << std::endl
			  << "Breed: " << pony->getBreed() << std::endl
			  << "Age: " << pony->getAge() << std::endl
			  << "Height: " << pony->getHeight() << std::endl;
	delete pony;
}

static void ponyOnTheStack( std::string name, std::string breed, int height, int age )
{
	Pony pony(name, breed, height, age);

	std::cout << "Pony in the stack" << std::endl
			  << "Name: " << pony.getName() << std::endl
			  << "Breed: " << pony.getBreed() << std::endl
			  << "Age: " << pony.getAge() << std::endl
			  << "Height: " << pony.getHeight() << std::endl;
}

int main( void )
{
	std::cout << std::endl;
	ponyOnTheHeap("Heather Ryan Chester Hugo Watson Watts Nicholson Jonathan Lewis Parker", "British Riding Pony", 142, 3);
	std::cout << std::endl;
	ponyOnTheStack("Dracarys", "Welsh Pony", 92, 1);
	return (0);
}
