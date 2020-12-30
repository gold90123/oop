#ifndef BULLET_H
#define BULLET_H

#include<iostream>
#include"tools.h"
#include"interface.h"

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
};
#endif
//push