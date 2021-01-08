#pragma once
#ifndef BIGMONSTER_H
#define BIGMONSTER_H
#include"monster.h"
using namespace std;

class  bigmonster : public monster {
private:
	double x; // x coordinate
	double y; // y coordinate 
	static bool gameMode;
	bool isback;
public:
	static void setGameMode(bool level); // true(1) is the easy mode while false(0) is the hard mode
	bigmonster(double x, double y); 
	double X() { return x; }
	double Y() { return y; }
	void Draw(); // show the current position of 59 in the terminal
	void Erase(); // clear the current position of student in the terminal
	void Move(); // move 59 
	void Moveback();
	bool isreallyOut();
	bool isOut(); // detect whether 59 is out of the boundry
};
#endif // !BIGMONSTER_H
