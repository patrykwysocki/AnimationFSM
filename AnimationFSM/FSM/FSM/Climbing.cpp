//Patryk Wysocki
//9/11/17
//Simple FSM.
#include "Climbing.h"
#include "Idle.h"

Climbing::Climbing()
{
}

Climbing::~Climbing()
{
}

void Climbing::idle(Animation*a)
{
	std::cout << "Climbing to Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
