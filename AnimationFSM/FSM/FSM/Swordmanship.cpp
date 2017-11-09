//Patryk Wysocki
//9/11/17
//Simple FSM.
#include "Swordmanship.h"

SwordmanShip::SwordmanShip()
{
}

SwordmanShip::~SwordmanShip()
{
}

void SwordmanShip::idle(Animation * a)
{
	std::cout << "Swordmanship to Idle" << std::endl;
	a->setCurrent(new Idle());
	delete this;
}
