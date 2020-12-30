#include<iostream>
#include<conio.h>
#include<windows.h>
#include<list>
#include"game.h"
#include"bullet.h"
#include"interface.h"
#include"monster.h"
#include"tools.h"
#include"PLane.h"
using namespace std;

#define BORDER_RIGHT_WIDE 115
#define BORDER_DOWN 28
#define TIME_LIMIT 30
#define BORDER_RIGHT 73
#define BORDER_LEFT 43  
#define BORDER_UP 2
#define SCORE59_CNT 10
#define STUDENT_INITIAL_X 58.5
#define STUDENT_INITIAL_Y 25
#define GET_GAME_POINT 2
#define LOSE_GAME_POINT 5
#define VICTORY_GATE 60
#define SHOW_MSG_SHORT 100
#define INTERVAL_BETWEEN_EACH_LOOP 20
#define EQUALITY_GAP_X 1.5
#define EQUALITY_GAP_Y 1
#define TIME_POS_X 20 
#define TIME_POS_Y 0
#define CUR_SCORE_POS_X 50
#define CUR_SCORE_POS_Y 0  
#define HIS_SCORE_POS_X 80
#define HIS_SCORE_POS_Y 0 

int HISTORY_HIGH_SCORE = 0;

void game::ChooseGameMode()
{
    Interface::GameModeMessage();
    
    char gameModeKey = '0'; 
    bool VaildKeyForGameMode = false;
    
    while (!VaildKeyForGameMode) // prevent the user from pressing inappropriate keys
    {
        gameModeKey = getch();  
        
        if (gameModeKey == 'e' || gameModeKey == 'E' || gameModeKey == 'h' || gameModeKey == 'H')
        {
            VaildKeyForGameMode = true;
        }       
    }
    
    if (gameModeKey == 'e' || gameModeKey == 'E')
    {
        monster::setGameMode(1); // 1 (true) is easy mode                   
    }
    
    else
    {
        monster::setGameMode(0); // 0 (false) is hard mode                  
    }
}

bool game::StartGame()
{
    tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    
    std::chrono::seconds timeLimit(TIME_LIMIT); // transform int/double to seconds defined by chrono
    std::chrono::seconds duration(0); // calculate how long has the game since it started
    std::chrono::seconds leftTime(TIME_LIMIT); // calculate how many seconds are left
    auto start = chrono::steady_clock::now(); // record the start time
    int gameScore = 0; // the score of the game
    
    Plane std = Plane(STUDENT_INITIAL_X, STUDENT_INITIAL_Y); // the position of student in the beginning
    list<monster> scores; // dynamic list for 59("五九")
    list<monster>::iterator s; // iterator for the list
    list<bullet> passes; // dynamic list for pass("及格") 
    list<bullet>::iterator p; // another iterator for this list 
    
    srand(time(nullptr)); // generate random number for the positions of 59s
    int mapWidth = BORDER_RIGHT - BORDER_LEFT + 1; // border included
    int mapLength = BORDER_DOWN - BORDER_UP + 1; // border included
    double rnX = 0;
    double rnY = 0; // initialize random number
    for (int i = 0; i < SCORE59_CNT; i++) // generate 59s
    {
        rnX = (rand() % mapWidth) + BORDER_LEFT;
        rnY = (rand() % (mapLength / 2)) + (BORDER_UP); //  (mapLength / 2) prevents 59s from being too low on the map at first
        scores.push_back(monster(rnX, rnY));
    }
    
    while(duration < timeLimit) // while the game is not end
    {   
        for (p = passes.begin(); p != passes.end(); p++) // for every pass that in the list
        {
            p->move(); // move a SPEED_PASS unit upward
            if (p->isout()) // if the pass reaches the top of map
            {
                p->erase(); // clear it in the terminal 
                p = passes.erase(p); // delete it in the list
            }
        }
        
        for (s = scores.begin(); s != scores.end(); s++) // for every 59 that in the list
        {           
            s->Move(); // move a SPEED_SCORE59_EASY /SPEED_SCORE59_HARD unit downward
            if (s->isOut()) // if the 59 reaches the bottom of map
            {
                s->Erase(); // clear it in the terminal 
                s = scores.erase(s); // delete it in the list
                
                rnX = (rand() % mapWidth) + BORDER_LEFT;
                scores.push_back(monster(rnX, BORDER_UP)); // add a new 59 to the list to keep the number of 59s in the game the same
            }   
        }
        
        for (s = scores.begin(); s != scores.end(); s++) // for every 59 that in the list
        {
            // check whether 59 bumps into passes
            for (p = passes.begin(); p != passes.end(); p++) // for every pass that in the list
            {
                if (Collision(s->X(), s->Y(), p->X(), p->Y())) 
                {
                    gameScore += GET_GAME_POINT;
                    p->erase(); // clear it in the terminal
                    s->Erase(); // clear it in the terminal  
                    p = passes.erase(p); // delete it in the list
                    s = scores.erase(s); // delete it in the list
                    
                    rnX = (rand() % mapWidth) + BORDER_LEFT;
                    scores.push_back(monster(rnX, BORDER_UP)); // add a new 59 to the list to keep the number of 59s in the game the same
                }
            }
        } 
        
        for (s = scores.begin(); s != scores.end(); s++) // for every 59 that in the list
        {
            // check whether 59 bumps into student
            if (Collision(s->X(), s->Y(), std.X(), std.Y())) 
            {
                gameScore -= LOSE_GAME_POINT;
                std.Erase(); // clear it in the terminal
                s->Erase(); // clear it in the terminal  
                Sleep(SHOW_MSG_SHORT);
                s = scores.erase(s); // delete it in the list
                
                rnX = (rand() % mapWidth) + BORDER_LEFT;
                scores.push_back(monster(rnX, BORDER_UP)); // add a new 59 to the list to keep the number of 59s in the game the same
            }           
        }
                 
        if(kbhit())
        {
            char key = getch();
            if(key == ' ') // press the space bar, and add a pass to the pass list
            {
                passes.push_back(bullet(std.X(), std.Y() - 1));
            }
        }
        
        std.Move(); // student move
        
        auto t1 = chrono::steady_clock::now(); // record the current time
        duration = std::chrono::duration_cast<std::chrono::seconds>(t1 - start); // calculate how long is the game going & convert the duration to the type of seconds
        leftTime = timeLimit - duration; // calculate how many seconds are left 
        
        UpdateInfoBar(gameScore, leftTime); // update game information to the user
 
        Sleep(INTERVAL_BETWEEN_EACH_LOOP); // ESSENTIAL, otherwise the game would be unplayble
    }
    
    if (gameScore >= VICTORY_GATE)
        return true;
    else 
        return false;
}
bool Collision(double x1, double y1, double x2, double y2) // check whether 59 bumps into any passes
{
    if (abs(x1 -x2) < EQUALITY_GAP_X) // the width of 59 is not the same as the width of "傑"   
    {
        if (abs(y1 -y2) < EQUALITY_GAP_Y) 
            return true;
        else
            return false;
    }
    
    return false; 
}
void UpdateInfoBar(int gameScore, std::chrono::seconds leftTime) // update game information to the user during the game
{
    tools::gotoxy(TIME_POS_X, TIME_POS_Y); cout << "剩餘時間: " << leftTime.count() << "   "; // update time 
    // because sometimes the digits of number are different, print some white spaces after the number to erase the digits from the previous number 
    tools::gotoxy(CUR_SCORE_POS_X, CUR_SCORE_POS_Y); cout << "分數: " << gameScore << "  "; // update game score 
    tools::gotoxy(HIS_SCORE_POS_X, HIS_SCORE_POS_Y); cout << "歷史高分: " << HISTORY_HIGH_SCORE; // update history high game score     
    if (gameScore >= HISTORY_HIGH_SCORE)
    {
        HISTORY_HIGH_SCORE = gameScore;
        tools::gotoxy(HIS_SCORE_POS_X, HIS_SCORE_POS_Y); cout << "歷史高分: " << HISTORY_HIGH_SCORE; // update history high game score     
    }
}
 
bool PlayAgainOrNot()
{
    Interface::PlayAgainMessage();
    
    char playAgainKey = '0';    
    bool VaildKeyForPlayAgain = false;  
    
    while (!VaildKeyForPlayAgain) // prevent the user from pressing inappropriate keys
    {
        playAgainKey = getch(); 
        
        if (playAgainKey == 'y' || playAgainKey == 'Y' || playAgainKey == 'n' || playAgainKey == 'N')
        {
            VaildKeyForPlayAgain = true;
        }       
    }
    
    if (playAgainKey == 'n' || playAgainKey == 'N')
        return false;                   
    else
        return true;
}
