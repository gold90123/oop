#pragma once
#include<iostream>
#define speed 3
#define border 2

class bullet {
private:
	int x;
	int y;
public:
	bullet(double x, double y);
	double X();
	double Y();
	void print();
	void erase();
	void move();
	bool isout();
	void gotoxy(double x,double y);
};