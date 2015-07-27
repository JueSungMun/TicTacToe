#include "map_gui.h"
#include "console_util.h"
#include "game_rule.h"

int main()
{
	int ch=0;
	bool isGameOver = false;

	SetWindowSize(100,40);
	MAP_GUI mg; 
	TICTACTOE_GAME tg;
	if(tg.GetUserState() == tg.CIRCLE)
	{
		mg.InitialzieMap(mg.CIRCLE);
	}
	else
		mg.InitialzieMap(mg.X_VALUE);

	while(1) 
	{
		if(isGameOver)
		{
			//system("pause");
			getch();
			tg.Initialize_Map();
			if(tg.GetUserState() == tg.CIRCLE)
			{
				mg.InitialzieMap(mg.CIRCLE);
			}
			else
				mg.InitialzieMap(mg.X_VALUE);

			isGameOver = false;
		}
		
		SetCursorPosition(5,32);

		if(tg.GetAITurn())
		{
			int ai_num = tg.Artificial_Intelligence();
			if(tg.GetAIState() == tg.CIRCLE)
				mg.UpdateMap(mg.CIRCLE,ai_num);
			else
				mg.UpdateMap(mg.X_VALUE,ai_num);
			if(tg.DetectionWinner(ai_num))
			{
				isGameOver = true;
				mg.UpdateScore(mg.COMPUTER);
			}
			else
				tg.SetPlayerTurn();
		}
		else
		{
			if(_kbhit())
			{
				ch = _getch();
				switch(ch)
				{
					case ESC :
					SetCursorPosition(80,35);
					cout<<"Made by Jue"<<endl;
					return 0;
					break;
					case NUM1 : 
						if(tg.IsPossibleAssin(1))
						{
							if(tg.GetUserState() == tg.CIRCLE)
								mg.UpdateMap(mg.CIRCLE,1);
							else
								mg.UpdateMap(mg.X_VALUE,1);
							if(tg.DetectionWinner(1)) 
							{
								isGameOver = true;
								mg.UpdateScore(mg.USER);
							}
							else tg.SetPlayerTurn();
						}
						break;
					case NUM2 : 
						if(tg.IsPossibleAssin(2))
						{
							if(tg.GetUserState() == tg.CIRCLE)
								mg.UpdateMap(mg.CIRCLE,2);
							else
								mg.UpdateMap(mg.X_VALUE,2);
							if(tg.DetectionWinner(2))
							{
								isGameOver = true;
								mg.UpdateScore(mg.USER);
							}
							else tg.SetPlayerTurn();
						}
						break;
					case NUM3 : 
						if(tg.IsPossibleAssin(3))
						{
							if(tg.GetUserState() == tg.CIRCLE)
								mg.UpdateMap(mg.CIRCLE,3);
							else
								mg.UpdateMap(mg.X_VALUE,3);
							if(tg.DetectionWinner(3))
							{
								isGameOver = true;
								mg.UpdateScore(mg.USER);
							}
							else tg.SetPlayerTurn();
						}
						break;
					case NUM4 : 
						if(tg.IsPossibleAssin(4))
						{
							if(tg.GetUserState() == tg.CIRCLE)
								mg.UpdateMap(mg.CIRCLE,4);
							else
								mg.UpdateMap(mg.X_VALUE,4);
							if(tg.DetectionWinner(4))
							{
								isGameOver = true;
								mg.UpdateScore(mg.USER);
							}
							else tg.SetPlayerTurn();
						}
						break;
					case NUM5 : 
						if(tg.IsPossibleAssin(5))
						{
							if(tg.GetUserState() == tg.CIRCLE)
								mg.UpdateMap(mg.CIRCLE,5);
							else
								mg.UpdateMap(mg.X_VALUE,5);
							if(tg.DetectionWinner(5))
							{
								isGameOver = true;
								mg.UpdateScore(mg.USER);
							}
							else tg.SetPlayerTurn();
						}
						break;
					case NUM6 : 
						if(tg.IsPossibleAssin(6))
						{
							if(tg.GetUserState() == tg.CIRCLE)
								mg.UpdateMap(mg.CIRCLE,6);
							else
								mg.UpdateMap(mg.X_VALUE,6);
							if(tg.DetectionWinner(6))
							{
								isGameOver = true;
								mg.UpdateScore(mg.USER);
							}
							else tg.SetPlayerTurn();
						}
						break;
					case NUM7 : 
						if(tg.IsPossibleAssin(7))
						{
							if(tg.GetUserState() == tg.CIRCLE)
								mg.UpdateMap(mg.CIRCLE,7);
							else
								mg.UpdateMap(mg.X_VALUE,7);
							if(tg.DetectionWinner(7)){
								isGameOver = true;
								mg.UpdateScore(mg.USER);
							}
							else tg.SetPlayerTurn();
						}
						break;
					case NUM8 : 
						if(tg.IsPossibleAssin(8))
						{
							if(tg.GetUserState() == tg.CIRCLE)
								mg.UpdateMap(mg.CIRCLE,8);
							else
								mg.UpdateMap(mg.X_VALUE,8);
							if(tg.DetectionWinner(8)){
								isGameOver = true;
								mg.UpdateScore(mg.USER);
							}
							else tg.SetPlayerTurn();
						}
						break;
					case NUM9 : 
						if(tg.IsPossibleAssin(9))
						{
							if(tg.GetUserState() == tg.CIRCLE)
								mg.UpdateMap(mg.CIRCLE,9);
							else
								mg.UpdateMap(mg.X_VALUE,9);
							if(tg.DetectionWinner(9)){
								isGameOver = true;
								mg.UpdateScore(mg.USER);
							}
							else tg.SetPlayerTurn();
						}
						break;
					case VK_N : 
						isGameOver = false;
						tg.Initialize_Map();
						if(tg.GetUserState() == tg.CIRCLE)
						{
							mg.InitialzieMap(mg.CIRCLE);
						}
						else
							mg.InitialzieMap(mg.X_VALUE);

						break;
					case VK_n :
						isGameOver = false;
						tg.Initialize_Map();
						if(tg.GetUserState() == tg.CIRCLE)
						{
							mg.InitialzieMap(mg.CIRCLE);
						}
						else
							mg.InitialzieMap(mg.X_VALUE);

						break;
				}
			}
		}

		if(tg.DetectionDrawState())
		{
			mg.UpdateScore(mg.DRAW);
			isGameOver = true;
		}
	}	
	return 0;
}