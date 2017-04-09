#pragma once
#include "Base_object.h"
#include "DLList.h"
class Shadows :
	public Base_object
{
private:
	int* m_vel;
	Base_object* head;
	Base_object* tail;
	DLList<Base_object*> m_shadows;
public:
	Shadows();
	~Shadows();
	void addtail(Base_object* _tail);
	void Input();
	void Update(int _frame);
	void Render();
};

