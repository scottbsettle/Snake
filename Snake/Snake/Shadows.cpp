#include "stdafx.h"
#include "Shadows.h"
#include "Player.h"

Shadows::Shadows()
{
	tail = new Base_object;
}


Shadows::~Shadows()
{
	delete tail;
}
void Shadows::addtail(Base_object* _tail)
{
	m_vel = _tail->getvel();
	if (m_vel[0] == 0)
	{
		if (m_vel[1] == 1)
		{
			tail->setX(_tail->getX());
			tail->setY(_tail->getY() - 1);
			m_shadows.addTail(tail);
		}
		else
		{
			tail->setX(_tail->getX());
			tail->setY(_tail->getY() + 1);
			m_shadows.addTail(tail);
		}
	}
	else if (m_vel[1] == 0)
		{
		if (m_vel[0] == 1)
		{
			tail->setY(_tail->getY());
			tail->setY(_tail->getX() - 1);
			m_shadows.addTail(tail);
		}
		else
		{
			tail->setY(_tail->getY());
			tail->setY(_tail->getX() + 1);
			m_shadows.addTail(tail);
		}
		}
	
}
void Shadows::Input()
{
	Base_object::Input();
}
void Shadows::Update(int _frame)
{
	Base_object::Update(_frame);
}
void Shadows::Render()
{
	DLLIter<Base_object*> itter(m_shadows);
	itter.beginHead();
	while (!itter.end())
	{
		Console::SetCursorPosition(itter.current()->getX(), itter.current()->getY());
		cout << itter.current()->getImage();
		++itter;
	}

}