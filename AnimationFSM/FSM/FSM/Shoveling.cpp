//Patryk Wysocki
//9/11/17
//Simple FSM.
#include "Shoveling.h"
Shoveling::Shoveling()
{
}

Shoveling::~Shoveling()
{
}

void Shoveling::idle(Animation * a)
{
	std::cout << "Shoveling to Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
