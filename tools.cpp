#include<iostream>
#include"tools.h"
#include<windows.h>
#include<graphics.h>
using namespace std;



void tools::gotoxy(double x, double y) // allows to move inside the terminal using coordinates 
{   // the type is double, so objects can move less than 1 unit 
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x; // start from 0
    dwPos.Y = y; // start from 0
    SetConsoleCursorPosition(hCon, dwPos);
}
void tools::DrawWhiteSpace(int a_x, int a_y, int b_x, int b_y) // to clean a certain space in the terminal 
{ 
	IMAGE img;
	loadimage(&img, L"C:\\Users\\Username\\Desktop\\starburst2.jpg", 640, 360);
	putimage(0, 0, &img);
}
void tools::Initialize() // set console title and hide console cursor
{
    // set console title
    //SetConsoleTitle("Flunk You"); 
    
    // hide console cursor
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cci);
}
void tools::SetColor(int color)
{
    HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}