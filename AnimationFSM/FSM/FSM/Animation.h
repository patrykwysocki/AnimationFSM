#pragma once
//Patryk Wysocki
//9/11/17
//Simple FSM.
class Animation
{
	class State* current;
public:
	Animation();
	void setCurrent(State* s);
	void idle();
	void jumping();
	void climbing();
	void shoveling();
	void walking();
	void hammering();
	void swordmanship();


};