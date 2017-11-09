//Patryk Wysocki
//9/11/17
//Simple FSM.

#include "Animation.h"
#include "Idle.h"


void Animation::idle()
{
	current->idle(this);
}

void Animation::jumping()
{
	current->jumping(this);
}

void Animation::climbing()
{
	current->climbing(this);
}
void Animation::shoveling()
{
	current->shoveling(this);
}
void Animation::walking()
{
	current->walking(this);
}
void Animation::hammering()
{
	current->hammering(this);
}
void Animation::swordmanship()
{
	current->swordmanship(this);
}
Animation::Animation()
{
	current = new Idle();
}
void Animation::setCurrent(State* s) 
{ 
	current = s; 
}