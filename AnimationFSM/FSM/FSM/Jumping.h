#pragma once
//Patryk Wysocki
//9/11/17
//Simple FSM.
#include "State.h"
#include "Animation.h"
class Jumping :public State
{
public:
	Jumping();
	~Jumping();
	void idle(Animation*a);


};