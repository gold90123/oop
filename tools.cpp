#include<iostream>
#include"tools.h"
#include<windows.h>
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
    for(int i = a_x; i <= b_x; i++)
    {
        for(int j = a_y; j <= b_y; j++)
        {
            tools::gotoxy(i,j); 
            cout << " ";
        }
    }
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