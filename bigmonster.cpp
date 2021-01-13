#include<iostream>
#include"bigmonster.h"
#include"tools.h"
#include<graphics.h>
using namespace std;

#define SPEED_SCORE59_EASY 3
#define SPEED_SCORE59_HARD 6
#define BORDER_DOWN 300
#define BORDER_UP 10

bigmonster::bigmonster(double x, double y):monster(x, y) {
	this->x = x;
	this->y = y;
	isback = false;
}
void bigmonster::Draw()
{
	setbkmode(TRANSPARENT);
	outtextxy(x, y, _T("★"));
}

void bigmonster::Erase()
{
	setbkmode(TRANSPARENT);
	outtextxy(x, y, _T("  "));
}

void bigmonster::Move()
{
	Erase();

	if (gameMode == 1)
		y += SPEED_SCORE59_EASY; // move a SPEED_SCORE59 unit downward
	else
		y += SPEED_SCORE59_HARD;

	Draw();
}

      
bool bigmonster::isOut()
{
	if (y > BORDER_DOWN||isback)
		return true;
	else
		return false;
}

bool bigmonster::gameMode = 1; // the user play the game in easy mode by default

void bigmonster::setGameMode(bool level)
{
	gameMode = level;
}

void bigmonster::Moveback()
{
	Erase();
	isback = true;

	if (gameMode == 1)
		y -= SPEED_SCORE59_EASY; // move a SPEED_SCORE59 unit downward
	else
		y -= SPEED_SCORE59_HARD;

	Draw();
}
bool bigmonster::isreallyOut() {
	if (y < BORDER_UP + 1 && isback) {
		isback = false;
		return true;
	}
	else
		return false;
}