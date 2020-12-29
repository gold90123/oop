#include<chrono>
using namespace std;

class game
{
public:
    static void ChooseGameMode();
    static bool StartGame();
    static bool Collision(double x1, double y1, double x2, double y2);  
    static void UpdateInfoBar(int gameScore, std::chrono::seconds leftTime);
    static bool PlayAgainOrNot();
};