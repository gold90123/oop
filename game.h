#include<chrono>
using namespace std;

class game
{
public:
    void ChooseGameMode();
    bool StartGame();
    bool Collision(double x1, double y1, double x2, double y2);  
    void UpdateInfoBar(int gameScore, std::chrono::seconds leftTime);
    bool PlayAgainOrNot();
};