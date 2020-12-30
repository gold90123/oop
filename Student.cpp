#include"Student.h"
#include "tools.h"
#include <conio.h>
#include<iostream>
using namespace std;

#define KEY_UP    72 // arrow keys' ascii numbers
#define KEY_DOWN  80
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define BORDER_UP 2 // border for the objects in the game
#define BORDER_DOWN 28
#define BORDER_LEFT 43  
#define BORDER_RIGHT 73 
#define SPEED_STUDENT 1.1

Student::Student(double x,double y){
    this->x = x; this->y = y;
    
}

double Student::X(){ return x; }
double Student::Y(){ return y; }

void Student::Draw()
{tools::
    gotoxy(x-2, y-1); cout << "|▅●▅|";
    gotoxy(x-2, y); cout << " └▇┘";
    gotoxy(x-2, y+1); cout << " ︻┴︻";
    
    
}

void Student::Erase()
{
    tools::gotoxy(x, y); cout << "  ";
}

void Student::Move()
{
    if (kbhit())
    {
        Erase();

        char key = getch();
        switch (key)
        {
        case KEY_LEFT: if (x - SPEED_STUDENT > BORDER_LEFT) { x -= SPEED_STUDENT; break; }
        case KEY_RIGHT: if (x + SPEED_STUDENT < BORDER_RIGHT) { x += SPEED_STUDENT; break; }
        case KEY_UP: if (y - SPEED_STUDENT > BORDER_UP) { y -= SPEED_STUDENT; break; }
        case KEY_DOWN: if (y + SPEED_STUDENT < BORDER_DOWN) { y += SPEED_STUDENT; break; }
        }
    }

    Draw(); // wheter the user press key, there is always a student in the terminal     
}
