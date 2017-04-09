#include "stdafx.h"
#include "Base_object.h"


Base_object::Base_object()
{
	width = 1;
	hight = 1;
	x = 10;
	y = 10;
	Alive = false;
	vel[0] = 1;
	vel[1] = 0;
	image = (char)254;
}


Base_object::~Base_object()
{
}

void Base_object::Input()
{

}

void Base_object::Update(int _frame)
{
	SetVel(vel);
	x += vel[0];
	y += vel[1];
}
void Base_object::Render()
{
	Console::SetCursorPosition(x, y);
	cout << image;
}