#include<iostream>
#include"tools.h"
#include<windows.h>
#include <cstdlib> // generate random number 
#include <cmath>
#include <ctime> // random number seed
#include <chrono> // timing
#include <list> // use dynamic list as a container for 59s and passes("及格") in the game
#include <conio.h> 

void tools::gotoxy(double x, double y) // allows to move inside the terminal using coordinates 
{   // the type is double, so objects can move less than 1 unit 
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x; // start from 0
    dwPos.Y = y; // start from 0
    SetConsoleCursorPosition(hCon, dwPos);
}