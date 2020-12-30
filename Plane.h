#ifndef PLANE_H
#define PLANE_H

class Plane
{

public:
    Plane(double , double );
    double X();
    double Y();
    void Draw(); // show the current position of student in the terminal
    void Erase(); // clear the current position of student in the terminal
    void Move(); // move student (Erase()+Draw())
private:
    double x; // x coordinate
    double y;
}; 
#endif
