
class Base
{
protected:
	double x; 
	double y;
public:
    Base(double x, double y) { this->x = x; this->y = y; }
    double X() { return x; }
    double Y() { return y; }
    void Draw(); // show the current position of student in the terminal
    void Erase(); // clear the current position of student in the terminal 
    void Move(); // move student (Erase()+Draw())
};

