//Patryk Wysocki
//9/11/17
//Simple FSM.
#pragma once
#include "Animation.h"
#include "State.h"
#include "Idle.h"

class Shoveling : public State
{
public:
	Shoveling();
	~Shoveling();
	void idle(Animation* a);
};