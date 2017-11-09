#pragma once
//Patryk Wysocki
//9/11/17
//Simple FSM.
#include "Animation.h"
#include "State.h"
#include "Idle.h"

class Hammering : public State
{
public:
	Hammering();
	~Hammering();
	void idle(Animation* a);
};