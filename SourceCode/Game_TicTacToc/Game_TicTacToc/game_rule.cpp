#include "game_rule.h"

TICTACTOE_GAME::TICTACTOE_GAME()
{
	user_state.state = CIRCLE;
	ai_state.state = X_VALUE;

	for(int j = 0; j<3; j++)
		for(int i = 0; i<3; i++)
		{
			map[j][i] = EMPTY;
		}
	user_state.isTurn = true;
	user_state.score = 0;
	ai_state.isTurn = !user_state.isTurn;
	ai_state.score = 0;
	ai_state.isNeedDefence = false;
}

void TICTACTOE_GAME::Initialize_Map()
{
	for(int j = 0; j<3; j++)
		for(int i = 0; i<3; i++)
		{
			map[j][i] = EMPTY;
		}
	srand((unsigned int) time (NULL));
	user_state.state = rand()%2+1;

	if(user_state.state == CIRCLE)
	{
		user_state.isTurn = true;
		ai_state.isTurn = false;
		ai_state.state = X_VALUE;
	}
	else 
	{
		user_state.isTurn = false;
		ai_state.isTurn = true;
		ai_state.state = CIRCLE;
	}

	/*
	user_state.isFirstTurn = static_cast<bool>(rand()%2);
	ai_state.isFirstTurn = !user_state.isFirstTurn;
	*/
}

bool TICTACTOE_GAME::IsPossibleAssin(int num)
{
	bool state = false;

	switch(num)
	{
		case 1:
			if(map[2][0] == EMPTY)
			{
				map[2][0] = user_state.state;
				state = true;
			}
			break;
		case 2:
			if(map[2][1] == EMPTY)
			{
				map[2][1] = user_state.state;
				state = true;
			}
			break;
		case 3:
			if(map[2][2] == EMPTY)
			{
				map[2][2] = user_state.state;
				state = true;
			}
			break;
		case 4:
			if(map[1][0] == EMPTY)
			{
				map[1][0] = user_state.state;
				state = true;
			}
			break;
		case 5:
			if(map[1][1] == EMPTY)
			{
				map[1][1] = user_state.state;
				state = true;
			}
			break;
		case 6:
			if(map[1][2] == EMPTY)
			{
				map[1][2] = user_state.state;
				state = true;
			}
			break;
		case 7:
			if(map[0][0] == EMPTY)
			{
				map[0][0] = user_state.state;
				state = true;
			}
			break;
		case 8:
			if(map[0][1] == EMPTY)
			{
				map[0][1] = user_state.state;
				state = true;
			}
			break;
		case 9:
			if(map[0][2] == EMPTY)
			{
				map[0][2] = user_state.state;
				state = true;
			}
			break;
		default : 
			state  = false;
			break;
	}

	return state;
}

int TICTACTOE_GAME::GetUserState()
{
	return user_state.state;
}

int TICTACTOE_GAME::GetAIState()
{
	return ai_state.state;
}

bool TICTACTOE_GAME::DetectionWinner(int num)
{
	bool result = false;
	switch (num)
	{
		case 1:
			if(DetectionLowState(2))
				result = true;
			else if (DetectionColumnState(0))
				result = true;
			else if (DetectionPlusDiagonalState())
				result = true;
			break;
		case 2:
			if(DetectionLowState(2))
				result = true;
			else if (DetectionColumnState(1))
				result = true;
			break;
		case 3:
			if(DetectionLowState(2))
				result = true;
			else if (DetectionColumnState(2))
				result = true;
			else if (DetectionMinusDiagonalState())
				result = true;
			break;
		case 4:
			if(DetectionLowState(1))
				result = true;
			else if (DetectionColumnState(0))
				result = true;
			break;
		case 5:
			if(DetectionLowState(1))
				result = true;
			else if (DetectionColumnState(1))
				result = true;
			else if (DetectionPlusDiagonalState())
				result = true;
			else if (DetectionMinusDiagonalState())
				result = true;
			break;
		case 6:
			if(DetectionLowState(1))
				result = true;
			else if (DetectionColumnState(2))
				result = true;
			break;
		case 7:
			if(DetectionLowState(0))
				result = true;
			else if (DetectionColumnState(0))
				result = true;
			else if (DetectionMinusDiagonalState())
				result = true;
			break;
		case 8:
			if(DetectionLowState(0))
				result = true;
			else if (DetectionColumnState(1))
				result = true;
			break;
		case 9:
			if(DetectionLowState(0))
				result = true;
			else if (DetectionColumnState(2))
				result = true;
			else if (DetectionPlusDiagonalState())
				result = true;
			break;
	}
	return result;
}

bool TICTACTOE_GAME::DetectionLowState(int y)
{
	int result = 1;
	int userWinProbability = 0;
	Defence_Index temp_Idx={0,0};

	for(int i = 0; i<3; i++)
		result *= map[y][i];

	for(int i = 0; i<3; i++)
	{
		if(map[y][i] == user_state.state)
			userWinProbability += 33;
		else if(map[y][i] == ai_state.state)
			userWinProbability = -100;
		else
		{
			temp_Idx.y = y;
			temp_Idx.x = i;
		}
	}

	if(userWinProbability == 66)
	{
		ai_state.isNeedDefence = true;
		defence_Idx = temp_Idx;
	}
	
	if(result == 1 || result == 8)
	{
		return true;
	}
	else
		return false;

}

bool TICTACTOE_GAME::DetectionColumnState(int x)
{
	int result = 1;
	int userWinProbability = 0;
	Defence_Index temp_Idx={0,0};
	
	for(int j = 0; j<3; j++)
		result *= map[j][x];

	for(int i = 0; i<3; i++)
	{
		if(map[i][x] == user_state.state)
			userWinProbability += 33;
		else if (map[i][x] == ai_state.state)
			userWinProbability = -100;
		else
		{
			temp_Idx.y = i;
			temp_Idx.x = x;
		}
	}
	
	if(userWinProbability == 66)
	{
		ai_state.isNeedDefence = true;
		defence_Idx = temp_Idx;
	}	
	
	if(result == 1 || result == 8)
	{
		return true;
	}
	else
		return false;
}

bool TICTACTOE_GAME::DetectionPlusDiagonalState()
{
	int result = 1;
	int userWinProbability =0 ;
	Defence_Index temp_Idx={0,0};
	result = map[0][2] * map[1][1]* map[2][0];

	for(int i=0; i<3; i++)
	{
		if(map[i][2-i] == user_state.state)
			userWinProbability += 33;
		else if(map[i][2-i] == ai_state.state)
			userWinProbability = -100;
		else
		{
			temp_Idx.y = i;
			temp_Idx.x = 2-i;
		}
	}

	if(userWinProbability == 66)
	{
		ai_state.isNeedDefence = true;
		defence_Idx = temp_Idx;
	}
	
	if(result == 1 || result == 8)
	{
		return true;
	}
	else
		return false;
}

bool TICTACTOE_GAME::DetectionMinusDiagonalState()
{
	int result = 1;
	int userWinProbability = 0;
	Defence_Index temp_Idx={0,0};
	result = map[0][0] * map[1][1]* map[2][2];

	for(int i=0; i<3; i++)
	{
		if(map[i][i] == user_state.state)
			userWinProbability += 33;
		else if(map[i][i] == ai_state.state)
			userWinProbability = -100;
		else
		{
			temp_Idx.y = i;
			temp_Idx.x = i;
		}
	}

	if(userWinProbability == 66)
	{
		ai_state.isNeedDefence = true;
		defence_Idx = temp_Idx;
	}
	
	if(result == 1 || result == 8)
	{
		return true;
	}
	else
		return false;
}

bool TICTACTOE_GAME::GetAITurn()
{
	return ai_state.isTurn;
}

void TICTACTOE_GAME::SetPlayerTurn()
{
	user_state.isTurn = !user_state.isTurn; 
	ai_state.isTurn = !ai_state.isTurn;
}

int TICTACTOE_GAME::Artificial_Intelligence()
{
	int result = 0;
	int differenceInWinDefeat = user_state.score - ai_state.score;

	if(differenceInWinDefeat >=2)
	{
		if(ai_state.isNeedDefence)
			result = Priority_Defence_AI();
		else
			result = Priority_Position_AI();
	}
	else
		result = Priority_Position_AI();
		
	/*
	if(result == 0)
	{
		cout<<"Draw"<<endl;
	}
	*/
	return result;
}

int TICTACTOE_GAME::Priority_Defence_AI()
{
	//map[defence_Idx.y][defence_Idx.x] = ai_state.state;

	if(map[defence_Idx.y][defence_Idx.x] == EMPTY)
	{
		map[defence_Idx.y][defence_Idx.x] = ai_state.state;
		ai_state.isNeedDefence = false;
		return ConverIndexToNumber(defence_Idx.y, defence_Idx.x);
	}
	else
		return 0;
}

int TICTACTOE_GAME::Priority_Position_AI()
{

	if(map[1][1] == EMPTY)				//5
	{
		map[1][1] = ai_state.state;
		return 5;
	}
	else if (map[0][0] == EMPTY)		//7
	{
		map[0][0] = ai_state.state;
		return 7;
	}
	else if (map[0][2] == EMPTY)		//9
	{
		map[0][2] = ai_state.state;
		return 9;
	}
	else if (map[2][0] == EMPTY)		//1
	{
		map[2][0] = ai_state.state;
		return 1;
	}
	else if (map[2][2] == EMPTY)		//3
	{
		map[2][2] = ai_state.state;
		return 3;
	}
	else if (map[0][1] == EMPTY)		//8
	{
		map[0][1] = ai_state.state;
		return 8;
	}
	else if (map[1][0] == EMPTY)		//4
	{
		map[1][0] = ai_state.state;
		return 4;
	}
	else if (map[2][1] == EMPTY)		//2
	{
		map[2][1] = ai_state.state;
		return 2;
	}
	else if (map[1][2] == EMPTY)		//6
	{
		map[1][2] = ai_state.state;
		return 6;
	}
	else
		return 0;
}

int TICTACTOE_GAME::ConverIndexToNumber(int y, int x)
{
	if(y ==0 && x ==0)
		return 7;
	else if(y==0 && x==1)
		return 8;
	else if(y==0 && x==2)
		return 9;
	else if(y==1 && x==0)
		return 4;
	else if(y==1 && x==1)
		return 5;
	else if(y==1 && x==2)
		return 6;
	else if(y==2 && x==0)
		return 1;
	else if(y==2 && x==1)
		return 2;
	else if(y==2 && x==2)
		return 3;
	else
		return 0;
}

bool TICTACTOE_GAME::DetectionDrawState()
{
	bool isUserOccupy = false;
	bool isAIOccupy = false;
	bool result = false;
	draw_list.clear();
	list<bool>::iterator itor;
	//가로 세줄 상태 확인
	for(int j = 0; j<3; j++)
	{
		for(int i = 0; i<3; i++)
		{
			if(map[j][i] == user_state.state)
				isUserOccupy = true;
			else if(map[j][i] == ai_state.state)
				isAIOccupy = true;
		}

		if(isUserOccupy && isAIOccupy)
			draw_list.push_back(true);
		else
			return false;
	
		isUserOccupy = false;
		isAIOccupy = false;
	}

	//세로 세줄 상태확인
	for(int j = 0; j<3; j++)
	{
		for(int i = 0; i<3; i++)
		{
			if(map[i][j] == user_state.state)
				isUserOccupy = true;
			else if(map[i][j] == ai_state.state)
				isAIOccupy = true;
		}

		if(isUserOccupy && isAIOccupy)
			draw_list.push_back(true);
		else
			return false;
	
		isUserOccupy = false;
		isAIOccupy = false;
	}

	//대각선 확인
	for(int i=0; i<3; i++)
	{
		if(map[i][i] == user_state.state)
			isUserOccupy = true;
		else if(map[i][i] == ai_state.state)
			isAIOccupy = true;
	}

	if(isUserOccupy && isAIOccupy)
		draw_list.push_back(true);
	else
		return false;
	
	isUserOccupy = false;
	isAIOccupy = false;

	for(int i=0; i<3; i++)
	{
		if(map[i][2-i] == user_state.state)
			isUserOccupy = true;
		else if(map[i][2-i] == ai_state.state)
			isAIOccupy = true;
	}

	if(isUserOccupy && isAIOccupy)
		draw_list.push_back(true);
	else
		return false;
	
	isUserOccupy = false;
	isAIOccupy = false;

	for(itor=draw_list.begin() ; itor != draw_list.end(); itor++)
	{
		result = *itor;
		if(result == false)
			return false;
	}

	/*
	if(result)
	{
		SetCursorPosition(50,15);
		std::cout<<"User and Computer is draw!!"<<std::endl;
		SetCursorPosition(50,16);
		std::cout<<"If you want more game enter the 'Enter Key' "<<std::endl;
	}
	*/
		
	return result;
}