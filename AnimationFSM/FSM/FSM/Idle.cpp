//Patryk Wysocki
//9/11/17
//Simple FSM.
#include "Idle.h"

Idle::Idle()
{
}

Idle::~Idle()
{
}

void Idle::jumping(Animation*a)
{
	std::cout << "jumping" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
void Idle::climbing(Animation*a)
{
	std::cout << "Climbing" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}