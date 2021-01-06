#include<iostream>
#include<Windows.h>
#include"bullet.h"
#include"tools.h"
#define BORDER_UP 2
#define SPEED_BULLET 0.5
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
	tools::gotoxy(x, y);
	cout << "^";
}
void bullet::erase() {
	tools::gotoxy(x, y);
	cout << " ";
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