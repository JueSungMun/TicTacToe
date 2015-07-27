#include "map_gui.h"

MAP_GUI::MAP_GUI() : width(15), height(15), userScore(0), computerScore(0), drawScore(0)
{
	mapData = new TCHAR[width*height+1];
}
   
MAP_GUI::MAP_GUI(int _width, int _height) : width(_width), height(_height), userScore(0), computerScore(0), drawScore(0)
{
	mapData = new TCHAR[width*height+1];
}

MAP_GUI::~MAP_GUI()
{
	delete[] mapData;
}

void MAP_GUI::InitialzieMap(STATE USER_INFO)
{
	system("cls");
	cout<<endl;
	cout<<"     □□□□□ □   □□□  □□□□□    □        □□□  □□□□□    □□□    □□□□□   "<<endl;
	cout<<"         □     □  □           □      □  □     □           □      □      □  □           "<<endl;
	cout<<"         □     □ □            □     □ □ □   □            □     □        □ □□□□□   "<<endl;
	cout<<"         □     □  □           □    □      □   □           □      □      □  □           "<<endl;
	cout<<"         □     □   □□□      □   □        □   □□□      □        □□□    □□□□□   "<<endl;
	cout<<endl<<endl;

	for(int i=0; i<width*height; i++)
	mapData[i] = _T('　');	
	mapData[width*height] = _T('\0');
	ShowMap();		

	cout<<"     Input : number (1~9)   7 8 9"<<endl;
	cout<<"                            -----"<<endl;
	cout<<"                            4 5 6"<<endl;
	cout<<"                            -----"<<endl;
	cout<<"                            1 2 3"<<endl;
	
	if(USER_INFO == CIRCLE)
	{
		SetCursorPosition(50,15);
		cout<<"User is Circle, Your are first turn"<<endl;
		SetCursorPosition(50,16);
		cout<<"Computer is X_Value"<<endl;
	}
	else 
	{
		SetCursorPosition(50,15);
		cout<<"Computer is Circle, Computer is first turn"<<endl;
		SetCursorPosition(50,16);
		cout<<"User is X_Value"<<endl;
	}

	SetCursorPosition(50, 20);
	cout<<"STOP - Esc Key "<<endl;
	SetCursorPosition(50, 21);
	cout<<"Restart - N Key " <<endl;

	UpdateScore(INITIAL);
}

void MAP_GUI::UpdateScore(WINNER winner)
{
	switch(winner)
	{
		case WINNER::COMPUTER : 
			computerScore++;
			SetCursorPosition(50,23);
			std::cout<<"Computer is Win!!"<<std::endl;
			SetCursorPosition(50,24);
			std::cout<<"If you want more game enter the 'Enter Key' "<<std::endl;
			break;
		case WINNER::USER : 
			userScore++;
			SetCursorPosition(50,23);
			std::cout<<"User is Win!!"<<std::endl;
			SetCursorPosition(50,24);
			std::cout<<"If you want more game enter the 'Enter Key' "<<std::endl;
			break;
		case WINNER::DRAW : 
			drawScore++;
			SetCursorPosition(50,23);
			std::cout<<"User and Computer is draw!!"<<std::endl;
			SetCursorPosition(50,24);
			std::cout<<"If you want more game enter the 'Enter Key' "<<std::endl;
			break;
		case WINNER::INITIAL : 
			break;
	}

	SetCursorPosition(50,10);
	cout<<"User vs Computer 전적" <<endl;
	SetCursorPosition(50,11);
	cout<<"User : "<<userScore<<endl;
	SetCursorPosition(50,12);
	cout<<"Computer : " <<computerScore<<endl;
	SetCursorPosition(50,13);
	cout<<"Draw : " <<drawScore<<endl;
}

int MAP_GUI::GetBias(int input)
{
	int bias = 0;

	switch (input)
	{
		case 1:
			bias = 150;
			break;
		case 2:
			bias = 155;
			break;
		case 3:
			bias = 160;
			break;
		case 4:
			bias = 75;
			break;
		case 5:
			bias = 80;
			break;
		case 6:
			bias = 85;
			break;
		case 7:
			bias = 0;
			break;
		case 8:
			bias = 5;
			break;
		case 9:
			bias = 10;
			break;
		default : 
			break;
	}
	return bias;
}

void MAP_GUI::UpdateMap(STATE value, int input)
{
	int maxIndex = width*4+5;		//5*5 입력창의 인덱스 최대값
	int pixelWidth = 5;
	int bias = GetBias(input);		//입력된 숫자에 해당하는 배열 시작 인덱스

	if(0 < input && input < 10)
	{
		switch(value)
		{
			case STATE::CIRCLE :
				for(int j=0; j<maxIndex; j+=width*4)
				{
					for(int i=0; i<pixelWidth; i++)
					{
						int index = i%pixelWidth;
						if(index==1 || index== 2|| index==3)
							mapData[i+j+bias] = _T('□');
						else
							mapData[i+j+bias] = _T('　');
					}
				}

				for(int j=width; j<maxIndex-5; j+=width)
				{
					for(int i=0; i<pixelWidth; i++)
					{
						int index = i%pixelWidth;
						if(index==0 || index== 4)
							mapData[i+j+bias] = _T('□');
						else
							mapData[i+j+bias] = _T('　');
					}
				}

				ShowMap();
				break;

			case STATE::X_VALUE :

				for(int j=0; j<maxIndex; j+=width)
				{
					for(int i=0; i<pixelWidth; i++)
					{
						int index = i+j;

						if(index%16 ==0 )
							mapData[index+bias] = _T('□');
						else if (index%14 == 4)
							mapData[index+bias] = _T('□');
						else
							mapData[index+bias] = _T('　');
					}
				}

				ShowMap();
				break;
		}
	}
	
}

void MAP_GUI::ShowMap()
{
	std::locale::global(std::locale("kor"));

	int index = 0;

	//GetCursorPosition();
	SetCursorPosition(0,8);
	for(int j = 0; j<height*width; j+=width)
	{
		if(j % (width*5) == 0)
			std::cout<<"   ----------------------------------"<<endl;

		std::cout<<"   ";
		for (int i=0; i<width; i++)
		{
			if(i%5 == 0)
				wcout<<_T('|');

			index = i+j;
			wcout<<mapData[index];
		}
		wcout<<_T('|');
		std::cout<<endl;	
	}
	std::cout<<"   ----------------------------------"<<endl;
}