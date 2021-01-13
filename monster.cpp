#include<iostream>
#include"monster.h"
#include"tools.h"
#include<graphics.h>
using namespace std;

#define SPEED_SCORE59_EASY 3
#define SPEED_SCORE59_HARD 6
#define BORDER_DOWN 300

void monster::Draw()
{
	setbkmode(TRANSPARENT);
	outtextxy(x, y, _T("☆"));
}
 
void monster::Erase()
{
	setbkmode(TRANSPARENT);
	outtextxy(x, y, _T(" "));
}
 
void monster::Move()
{
    Erase();
    
    if (gameMode == 1)
        y += SPEED_SCORE59_EASY; // move a SPEED_SCORE59 unit downward
    else
        y += SPEED_SCORE59_HARD;
        
    Draw(); 
}
 
bool monster::isOut()
{
    if (y > BORDER_DOWN)
        return true;
    else
        return false;
}
 
bool monster::gameMode = 1; // the user play the game in easy mode by default
 
void monster::setGameMode(bool level)
{
    gameMode = level;
}