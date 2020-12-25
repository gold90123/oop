#include<iostream>
#include"monster.h"
#include"tools.h"
using namespace std;

#define SPEED_SCORE59_EASY 0.1
#define SPEED_SCORE59_HARD 0.5
#define BORDER_DOWN 28

void monster::Draw()
{
    tools::gotoxy(x, y); cout << "59";
}
 
void monster::Erase()
{
    tools::gotoxy(x, y); cout << "  ";  
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