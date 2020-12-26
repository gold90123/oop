
#include "Base.h"

class Student :public Base
{

public:
    Student(double , double );
    double X() { return x; }
    double Y() { return y; }
    void Draw(); // show the current position of student in the terminal
   // void Erase(); // clear the current position of student in the terminal 
    void Move(); // move student (Erase()+Draw())
}; 

