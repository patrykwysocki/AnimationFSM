#pragma once
//Patryk Wysocki
//9/11/17
//Simple FSM.
#include "State.h"
#include "Animation.h"
#include "Idle.h"
class Walking :public State
{
public:
	Walking();
	~Walking();
	void idle(Animation*a);


};