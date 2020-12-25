class monster //怪物
{
private:
    double x; // x coordinate
    double y; // y coordinate 
    static bool gameMode;
public:
    static void setGameMode(bool level); // true(1) is the easy mode while false(0) is the hard mode
    monster(double x, double y) { this->x = x; this->y = y; }
    double X() { return x; } 
    double Y() { return y; }
    void Draw(); // show the current position of 59 in the terminal
    void Erase(); // clear the current position of student in the terminal
    void Move(); // move 59 
    bool isOut(); // detect whether 59 is out of the boundry
};