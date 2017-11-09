#pragma once
//Patryk Wysocki
//9/11/17
//Simple FSM.
#include "State.h"
#include "Animation.h"
#include "Idle.h"
class SwordmanShip :public State
{
public:
	SwordmanShip();
	~SwordmanShip();
	void idle(Animation*a);


};