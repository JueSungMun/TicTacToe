#include "console_util.h"
#include <string>

void SetWindowSize(int width, int height)
{
	string command="mode con:cols=";
	command += to_string(width);
	command += " lines=";
	command += to_string(height);
	system(command.c_str());
}

void GetCursorPosition()
{
	COORD pos;
    CONSOLE_SCREEN_BUFFER_INFO buf;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&buf);
    pos.X = buf.dwCursorPosition.X;
    pos.Y = buf.dwCursorPosition.Y;
	cout<<"X : "<<pos.X<<", "<<"Y: "<<pos.Y<<endl;
}

void SetCursorPosition(int x,int y)
{
	COORD pos = {x,y};   //short 타입의 X, Y 속성이 들어 있는 구조체이다.
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

//VK_LEFT
/*
bool GetKeyButtonDown(int vkey)
{
	GetAsyncKeyState(VK_NUMPAD1);
}
*/