#include "stdafx.h"
#include "Food.h"


Food::Food()
{
	vel[0] = 0;
	vel[1] = 0;
	setImage((char)248);
	SetVel(vel);
}


Food::~Food()
{
}

void Food::PlaceFood()
{
	setX(rand() % 28 + 1);
	setY(rand() % 18 + 1);
}
void Food::Input()
{

}
void Food::Update(int _frame)
{

}
void Food::Render()
{
	Console::SetCursorPosition(getX(), getY());
	cout << getImage();
}