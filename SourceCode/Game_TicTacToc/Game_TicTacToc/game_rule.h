#ifndef GAME_RULE_HEADER
#define GAME_RULE_HEADER
#include "console_util.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

typedef struct
{
	int state;	//EMPTY, CIRCLE, X_VALUE;
	bool isTurn;
	bool isNeedDefence;
	int score;
} Player;

typedef struct
{
	int y;
	int x;
} Defence_Index;

class TICTACTOE_GAME
{
private:
	int map[3][3];
	Player user_state;
	Player ai_state;
	Defence_Index defence_Idx;
	list<bool> draw_list;

public:
	enum STATE {EMPTY, CIRCLE, X_VALUE};
	enum POSITION_PRIORITY {WAY_POINT=1, VERTEX, CENTER};
	TICTACTOE_GAME();
	void Initialize_Map();
	bool IsPossibleAssin(int num);
	bool DetectionWinner(int num);
	bool DetectionLowState(int y);
	bool DetectionColumnState(int x);
	bool DetectionPlusDiagonalState();
	bool DetectionMinusDiagonalState();
	int Artificial_Intelligence();
	int Priority_Position_AI();
	int Priority_Defence_AI();
	bool GetAITurn();
	void SetPlayerTurn();
	int GetUserState();
	int GetAIState();
	int ConverIndexToNumber(int y, int x);
	bool DetectionDrawState();
};
#endif