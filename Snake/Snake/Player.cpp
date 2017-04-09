#include "stdafx.h"
#include "Player.h"
#include "Food.h"

Player::Player()
{
	vel = new int[2];
	vel[0] = 1;
	vel[1] = 0;
	SetVel(vel);
	setAlive(true);
	size = 1;
	m_food = new Food;
	m_food->PlaceFood();
	temp = nullptr;
	score = 0;
}


Player::~Player()
{
	delete[] vel;
	delete m_food;
	DLLIter<Base_object*> itter(Snake);
	itter.beginHead();
	for (int loop = 0; loop < (int)store.size(); loop++)
		delete store[loop];
	Snake.clear();

}


void Player::Input()
{
	Base_object::Input();
	if (_kbhit())
	{
		char ch = _getch();
		switch (tolower(ch))
		{
		case 'w':
		{
			if (vel[1] != 1)
			{
				vel[0] = 0;
				vel[1] = -1;
				SetVel(vel);
			}
			break;
		}
		case 's':
		{
			if (vel[1] != -1)
			{
				vel[0] = 0;
				vel[1] = 1;
				SetVel(vel);
			}
			break;
		}
		case 'a':
		{
			if (vel[0] != 1)
			{
				vel[0] = -1;
				vel[1] = 0;
				SetVel(vel);
			}
			break;
		}
		case 'd':
		{
			if (vel[0] != -1)
			{
				vel[0] = 1;
				vel[1] = 0;
				SetVel(vel);
			}
			break;
		}
		}
	}
}
void Player::Update(int _frame)
{
	//out of bounds check
	if (getX() == 0 || getX() == 29 || getY() == 0 || getY() == 19)
		setAlive(false);
	//Update snake list 
	DLLIter<Base_object*> itter(Snake);
	itter.beginHead();
	XY[0] = itter.current()->getX();
	XY[1] = itter.current()->getY();
	itter.current()->setX(this->getX());
	itter.current()->setY(this->getY());
	++itter;
	while (!itter.end())
	{
		if (vel[0] == 0)
		{
			if (vel[1] == 1)
			{
				XY2[0] = itter.current()->getX();
				XY2[1] = itter.current()->getY();
			}
			else
			{
				XY2[0] = itter.current()->getX();
				XY2[1] = itter.current()->getY();
			}
		}
		else if (vel[1] == 0)
		{
			if (vel[0] == 1)
			{
				XY2[0] = itter.current()->getX();
				XY2[1] = itter.current()->getY();
			}
			else
			{
				XY2[0] = itter.current()->getX();
				XY2[1] = itter.current()->getY();
			}
		}
		itter.current()->setX(XY[0]);
		itter.current()->setY(XY[1]);
		XY[0] = XY2[0];
		XY[1] = XY2[1];
		++itter;
	}
	if (Collision(m_food))
	{
		temp = new Base_object;
		store.push_back(temp);
		m_food->PlaceFood();
		DLLIter<Base_object*> iter(Snake);
		iter.beginTail();
		temp->setX(iter.current()->getX());
		temp->setY(iter.current()->getY());
		temp->SetVel(iter.current()->getvel());
		addtail(temp);
	}
	Base_object::Update(_frame);
	itter.beginHead();
	while (!itter.end())
	{
		if (this->getX() == itter.current()->getX() && this->getY() == itter.current()->getY())
		{
			setAlive(false);
		}
		++itter;
	}

}
void Player::Render()
{
	DLLIter<Base_object*> itter(Snake);
	Console::Lock(true);
	Console::Clear();
	Console::DrawBox(0, 0, 30, 20, false);
	Base_object::Render();
	itter.beginHead();
	m_food->Render();
	while (!itter.end())
	{
		Console::SetCursorPosition(itter.current()->getX(), itter.current()->getY());
		cout << itter.current()->getImage();
		++itter;
	}
	Console::Lock(false);
}
bool Player::Collision(Base_object* _tmp)
{
	if (getX() - 1 + getWidth() < _tmp->getX())
		return false;
	if (getX() + 1 > _tmp->getX() + _tmp->getWidth())
		return false;
	if (getY() + 1 > _tmp->getY() + _tmp->getHight())
		return false;
	if (getY() - 1 + getHight() < _tmp->getY())
		return false;


	return true;

}
void Player::addtail(Base_object* _tail)
{

	if (_tail->getvel()[0] == 0)
	{
		if (_tail->getvel()[1] == 1)
		{
			_tail->setX(_tail->getX());
			_tail->setY(_tail->getY());
			Snake.addTail(_tail);
		}
		else
		{
			_tail->setX(_tail->getX());
			_tail->setY(_tail->getY());
			Snake.addTail(_tail);

		}
	}
	else if (_tail->getvel()[1] == 0)
	{
		if (_tail->getvel()[0] == 1)
		{
			_tail->setY(_tail->getY());
			_tail->setX(_tail->getX());
			Snake.addTail(_tail);
		}
		else
		{
			_tail->setY(_tail->getY());
			_tail->setX(_tail->getX());
			Snake.addTail(_tail);
		}
	}
	size++;
}