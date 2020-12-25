#include<iostream>
#include"interface.h"
#include"tools.h"
using namespace std;

#define BORDER_RIGHT_WIDE 115 
#define BORDER_DOWN 28

void Interface::GameModeMessage()
{
    tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 40;
    int y = 10;
    tools::gotoxy(x,y  ); cout << "   _______       ";
    tools::gotoxy(x,y+1); cout << "  /       \\   請選擇遊戲難度:";
    tools::gotoxy(x,y+2); cout << " / _    _  \\    ";
    tools::gotoxy(x,y+3); cout << "| / \\  / \\  |  簡單：按 E/e";
    tools::gotoxy(x,y+4); cout << "|  _______  |    ";
    tools::gotoxy(x,y+5); cout << " \\ \\_____/ /   困難：按 H/h";
    tools::gotoxy(x,y+6); cout << "  \\_______/     "; 
}