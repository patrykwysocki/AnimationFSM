//Patryk Wysocki
//9/11/17
//Simple FSM.
#include "Jumping.h"
#include "Idle.h"

Jumping::Jumping()
{
}

Jumping::~Jumping()
{
}

void Jumping::idle(Animation*a)
{
	std::cout << "going from jumping to idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
