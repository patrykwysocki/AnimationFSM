//Patryk Wysocki
//9/11/17
//Simple FSM.
#include "Walking.h"

Walking::Walking()
{
}

Walking::~Walking()
{
}

void Walking::idle(Animation * a)
{
	std::cout << "Walking to Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
