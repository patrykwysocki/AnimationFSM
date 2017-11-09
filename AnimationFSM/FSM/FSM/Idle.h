#pragma once
//Patryk Wysocki
//9/11/17
//Simple FSM.
#include "State.h"
#include "Animation.h"
class Idle :public State
{
public:
	Idle();
	~Idle();

	void jumping(Animation*a);
	void climbing(Animation*a);


};