#include"Plane.h"
#include "tools.h"
#include <conio.h>
#include<iostream>
#include<graphics.h>
using namespace std;
#pragma warning(disable:4996)

#define KEY_UP    72 // arrow keys' ascii numbers
#define KEY_DOWN  80
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define BORDER_UP 10 // border for the objects in the game
#define BORDER_DOWN 300
#define BORDER_LEFT 10 //0
#define BORDER_RIGHT 533
#define SPEED_PLANE 20

Plane::Plane(double x,double y){
    this->x = x; this->y = y;
    
}

double Plane::X(){ return x; }
double Plane::Y(){ return y; }

void Plane::Draw()
{
	/*setbkmode(TRANSPARENT);
	outtextxy(x, y, _T("*"));*/

	IMAGE img;
	bool a = 1;

	loadimage(&img, L"C:\\Users\\Username\\Desktop\\Kirito.jpg", 50, 50, a);
	putimage(x - 20, y, &img);

}

void Plane::Erase()
{
	setbkmode(TRANSPARENT);
	outtextxy(x, y, _T(" "));
}

void Plane::Move()
{
    if (kbhit())
    {
        Erase();

        char key = getch();
        switch (key)
        {
        case KEY_LEFT: if (x - SPEED_PLANE > BORDER_LEFT) { x -= SPEED_PLANE; break; }
        case KEY_RIGHT: if (x + SPEED_PLANE < BORDER_RIGHT) { x += SPEED_PLANE; break; }
        case KEY_UP: if (y - SPEED_PLANE > BORDER_UP) { y -= SPEED_PLANE; break; }
        case KEY_DOWN: if (y + SPEED_PLANE < BORDER_DOWN) { y += SPEED_PLANE; break; }
        }
    }

    Draw(); // wheter the user press key, there is always a student in the terminal     
}
