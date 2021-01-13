#include<iostream>
#include<windows.h>
#include"interface.h"
#include"tools.h"
#include<graphics.h>
using namespace std;

#define BORDER_RIGHT_WIDE 533
#define BORDER_DOWN 300
#define BORDER_RIGHT 533
#define BORDER_LEFT_WIDE 2
#define BORDER_UP 10
#define VICTORY_GATE 60
#define TIME_LIMIT 30
#define GET_GAME_POINT 2
#define LOSE_GAME_POINT 5

void Interface::WelcomeMessage()
{
	tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
	int x = 20;
	int y = 10;
	IMAGE img;
	bool a = 1;

	loadimage(&img, L"C:\\Users\\Username\\Desktop\\starburst2.jpg", 640, 360, a);
	putimage(0, 0, &img);
	//setbkmode(TRANSPARENT);
	COLORREF tc = 0x000000,
		settextcolor(tc);
	//setfont(10);
	outtextxy(175, y + 90, _T("Producer: Kao, Lui, Yu"));
	outtextxy(175, y + 120, _T("Press R/r to see game guide. Press other keys to play."));
}
//
void Interface::GuideMessage()
{
	IMAGE img;
	bool a = 1;

	loadimage(&img, L"C:\\Users\\Username\\Desktop\\starburst2.jpg", 640, 360, a);
	putimage(0, 0, &img);

	int y = 10;

	outtextxy(120, y + 90, _T("How To Play"));
	outtextxy(120, y + 120, _T("You have to shoot down as much stars as you can while not getting hit"));
	outtextxy(120, y + 150, _T("press arrow keys to move"));
	outtextxy(120, y + 170, _T("press space to shoot"));
}
void Interface::GameModeMessage()
{
	tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
	int x = 200;
	int y = 50;
	outtextxy(x, y, _T(""));
	outtextxy(x, y + 10, _T("Please select the difficulty:"));
	outtextxy(x, y + 40, _T("EASY   press E/e"));
	outtextxy(x, y + 60, _T("HADY   press H/h"));
}

void Interface::VictoryMessage()
{
	IMAGE img;
	bool a = 1;

	loadimage(&img, L"C:\\Users\\Username\\Desktop\\congratulations.jpg", 640, 360, a);
	putimage(0, 0, &img);
}

void Interface::DefeatMessage()
{
	IMAGE img;
	bool a = 1;

	loadimage(&img, L"C:\\Users\\Username\\Desktop\\youlose.jpg", 640, 360, a);
	putimage(0, 0, &img);
}

void Interface::PlayAgainMessage()
{
	IMAGE img;
	bool a = 1;

	loadimage(&img, L"C:\\Users\\Username\\Desktop\\playagain.jpg", 640, 360, a);
	outtextxy(300, 400, _T("Play again or not ??"));
	outtextxy(300, 420, _T("Press Y to play again"));
	outtextxy(300, 420, _T("Press N to logout"));
	putimage(0, 0, &img);
}

void Interface::GoodbyeMessage()
{
	IMAGE img;
	bool a = 1;

	loadimage(&img, L"C:\\Users\\Username\\Desktop\\goodbye.jpg", 640, 360, a);
	putimage(0, 0, &img);
}