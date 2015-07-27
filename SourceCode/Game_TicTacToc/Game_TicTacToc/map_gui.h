#ifndef MAP_GUI_HEADER
#define MAP_GUI_HEADER

#include <iostream>
#include <tchar.h>
#include "console_util.h"

using namespace std;


class MAP_GUI
{
private:
	int width;		//게임판 넓이
	int height;		//게임판 높이
	int userScore;
	int computerScore;
	int drawScore;
	TCHAR* mapData;
	
public:
	enum STATE {CIRCLE, X_VALUE};
	enum WINNER {USER, COMPUTER, DRAW, INITIAL};
	MAP_GUI();
	MAP_GUI(int _width, int _height);
	~MAP_GUI();
	void InitialzieMap(STATE USER_INFO);
	void UpdateMap(STATE value, int input);
	void UpdateScore(WINNER winner);
	int GetBias(int input);
	void ShowMap();
};
#endif


