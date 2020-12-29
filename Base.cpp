#include "Base.h"
#include<iostream>
#include <windows.h>
#include "tools.h"
#include <conio.h>
using namespace std;

void Base::Draw()
{
    tools:: gotoxy(x, y); cout << "��";
}

void Base::Erase()
{
    tools::gotoxy(x, y); cout << "  ";
}

void Base::Move()
{
    Erase();
    Draw(); // wheter the user press key, there is always a student in the terminal     
}

