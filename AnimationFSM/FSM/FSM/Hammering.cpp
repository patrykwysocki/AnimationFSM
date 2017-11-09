//Patryk Wysocki
//9/11/17
//Simple FSM.

#include "Hammering.h"

Hammering::Hammering()
{
}

Hammering::~Hammering()
{
}

void Hammering::idle(Animation * a)
{
	std::cout << "Hammering to Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
