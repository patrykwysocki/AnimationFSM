#pragma once
//Patryk Wysocki
//9/11/17
//Simple FSM.
#include "State.h"
#include "Animation.h"
class Climbing :public State
{
public:
	Climbing();
	~Climbing();
	void idle(Animation*a);


};