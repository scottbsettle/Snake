#pragma once
#include "Base_object.h"
#include "DLList.h"
class Food;
class Player : public Base_object
{
private:
	DLList<Base_object*> Snake;
	Base_object* temp;
	Food* m_food;
	vector<Base_object*> store;
	int XY[2];
	int XY2[2];
	int size;
	int* vel;
	int score;
public:
	Player();
	~Player();
	void addtail(Base_object* _tail);
	bool Collision(Base_object* _tmp);
	void Input();
	void Update(int _frame);
	void Render();
};

