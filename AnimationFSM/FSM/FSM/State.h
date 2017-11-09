#pragma once
//Patryk Wysocki
//9/11/17
//Simple FSM.
#include "Animation.h"
#include <iostream>
class State 
{
public:
	virtual void idle(Animation*a)
	{
		std::cout << "state::idling"<<std::endl;
	}
	virtual void jumping(Animation*a)
	{
		std::cout << "state::jumping" << std::endl;
	}
	virtual void climbing(Animation*a)
	{
		std::cout << "state::climbing" << std::endl;
	}
	virtual void shoveling(Animation*a)
	{
		std::cout << "state::shoveling" << std::endl;
	}
	virtual void swordmanship(Animation*a)
	{
		std::cout << "state::swordmanship" << std::endl;
	}
	virtual void walking(Animation*a)
	{
		std::cout << "state::walking" << std::endl;
	}
	virtual void hammering(Animation*a)
	{
		std::cout << "state::hammering" << std::endl;
	}
};