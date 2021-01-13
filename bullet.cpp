#include<iostream>
#include<Windows.h>
#include"bullet.h"
#include"tools.h"
#include<graphics.h>
#define BORDER_UP 10
#define SPEED_BULLET 5
using namespace std;

bullet::bullet(double x, double y) {
	this->x = x;
	this->y = y;
}
double bullet::X() {
	return x;
}
double bullet::Y() {
	return y;
}
void bullet::print() {
	setbkmode(TRANSPARENT);
	int r = rand() % 2;
	if (r == 0) {
		COLORREF color = RGB(0, 0, 255);
		settextcolor(color);
	}
	else if (r == 1) {
		COLORREF color = RGB(0, 0, 0);
		settextcolor(color);
	}
	outtextxy(x, y, _T("^"));
	COLORREF color_white = RGB(255, 255, 255);
	settextcolor(color_white);
}
void bullet::erase() {
	setbkmode(TRANSPARENT);
	outtextxy(x, y, _T(" "));
}
void bullet::move() {
	erase();
    y-=SPEED_BULLET;
	print();
}
bool bullet::isout() {
	if (y <= BORDER_UP) {
		return true;
	}
	else return false;
}