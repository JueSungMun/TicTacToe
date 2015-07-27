#ifndef CONSOLE_UTIL_HEADER
#define CONSOLE_UTIL_HEADER

#include <Windows.h>
#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

enum KEY_ARRAY {ESC=27, NUM1=49, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9, VK_N=78, VK_n=110};
void SetWindowSize(int width, int height);
void GetCursorPosition();
void SetCursorPosition(int x,int y);
//bool GetKeyButtonDown(int vkey);

#endif