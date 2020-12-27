#include<iostream>
#include<Windows.h>
#include"bullet.h"
using namespace std;

bullet::bullet(double x, double y) {
	this->x = x;
	this->y = y;
}
void bullet::gotoxy(double x,double y) {
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x; // start from 0
	dwPos.Y = y; // start from 0
	SetConsoleCursorPosition(hCon, dwPos);
}
double bullet::X() {
	return x;
}
double bullet::Y() {
	return y;
}
void bullet::print() {
	gotoxy(x, y);
	cout << "^";
}
void bullet::erase() {
	gotoxy(x, y);
	cout << " ";
}
void bullet::move() {
	erase();
	y -= speed;
	print();
}
bool bullet::isout() {
	if (y <= border) {
		return true;
	}
	else return false;
}