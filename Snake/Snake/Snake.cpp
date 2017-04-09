// Snake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Base_object.h"
#include "Player.h"


int _tmain(int argc, _TCHAR* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1);
	srand((unsigned int)time(0));
	Base_object* node = new Base_object;
	//Player test;
	bool run = true;
	bool play = true;
	int _frame = 0;
	//test.addtail(node);
	Console::SetWindowSize(30, 21);
	while (run)
	{
		Player test;
		test.addtail(node);
		while (test.getAlive())
		{
			Sleep(100);
			test.Input();
			test.Update(_frame);
			test.Render();
			_frame++;
			
		}
		Console::SetCursorPosition(10, 20);
		cout << "Game Over\n";
		cout << "Play Again Y/N";
		
		while (play)
		{

			if (_kbhit())
			{
				char ch = _getch();
				switch (tolower(ch))
				{
				case'y':
				{
						   play = false;
						   break;
				}
				case'n':
				{
						   play = false;
					   run = false;
					   break;
				}
				}
			}
		}
		play = true;
	}
	Console::Clear();
	Console::SetCursorPosition(2, 10);
	cout << "Have nice day 0_0";
	Sleep(2000);
	delete node;
	return 0;
}

