#pragma once
#include "Base_object.h"
#include "Player.h"
class Food : public Base_object
{
private:
	int vel[2];
public:
	Food();
	~Food();
	void PlaceFood();
	void Input();
	void Update(int _frame);
	void Render();
};

