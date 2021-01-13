#include<iostream>
#include<conio.h>
#include<windows.h>
#include<list>
#include"game.h"
#include"bullet.h"
#include"interface.h"
#include"monster.h"
#include"tools.h"
#include"Plane.h"
#include"bigmonster.h"
#include<graphics.h>
#pragma warning(disable:4996)
using namespace std;

#define BORDER_RIGHT_WIDE 533
#define BORDER_DOWN 300
#define TIME_LIMIT 30
#define BORDER_RIGHT 533
#define BORDER_LEFT 10 //43 //0  
#define BORDER_UP 10
#define SCORE59_CNT 10
#define STUDENT_INITIAL_X 260
#define STUDENT_INITIAL_Y 250
#define GET_GAME_POINT 2
#define LOSE_GAME_POINT 5
#define VICTORY_GATE -10
#define SHOW_MSG_SHORT 100
#define INTERVAL_BETWEEN_EACH_LOOP 20
#define EQUALITY_GAP_X 10
#define EQUALITY_GAP_Y 10
#define TIME_POS_X 20 
#define TIME_POS_Y 0
#define CUR_SCORE_POS_X 200
#define CUR_SCORE_POS_Y 0  
#define HIS_SCORE_POS_X 400
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
    list<monster> scores; // dynamic list
    list<monster>::iterator s; // iterator for the list
    list<bullet> passes; // dynamic list for pass("??????") 
    list<bullet>::iterator p; // another iterator for this list 
    list<bigmonster> bmons;
    list<bigmonster>::iterator bm;
    
    srand(time(nullptr)); // generate random number for the positions of 59s
    int mapWidth = BORDER_RIGHT - BORDER_LEFT + 1; // border included
    int mapLength = BORDER_DOWN - BORDER_UP + 1; // border included
    double rnX = 0;
    double rnY = 0; // initialize random number
    double rnbX = 0;
    double rnbY = 0;
    for (int i = 0; i < 10; i++) // generate 59s
    {
        rnX = (rand() % mapWidth) + BORDER_LEFT;
        rnY = (rand() % (mapLength / 2)) + (BORDER_UP);
        scores.push_back(monster(rnX, rnY));
        //bmons.push_back(bigmonster(rnbX,rnbY));
    }
    for (int i = 0; i < 3; i++) // generate 59s
    {
        rnbX = (rand() % mapWidth) + BORDER_LEFT;
        rnbY = (rand() % (mapLength / 2)) + (BORDER_UP); //  (mapLength / 2) prevents 59s from being too low on the map at first
        bmons.push_back(bigmonster(rnbX,rnbY));
    }
    
    while(duration < timeLimit) // while the game is not end
    {   
		IMAGE img;
		bool a = 1;
		loadimage(&img, L"C:\\Users\\Username\\Desktop\\background.jpg", 640, 360, a);
		putimage(0, 0, &img);

        for (p = passes.begin(); p != passes.end(); p++) // for every pass that in the list
        {
            p->move(); // move a SPEED_PASS unit upward
            if (p->isout()) // if the pass reaches the top of map
            {
                p->erase(); // clear it in the terminal 
                p = passes.erase(p); // delete it in the list
				break; //亂加的，結果真的有用
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
        for (bm = bmons.begin(); bm != bmons.end(); bm++) // for every 59 that in the list
        {  
            if(!bm->isOut()) {
                bm->Move();
            }
            else 
            {
                bm->Moveback();
            }          
            // move a SPEED_SCORE59_EASY /SPEED_SCORE59_HARD unit downward
            if (bm->isreallyOut()) // if the 59 reaches the bottom of map
            {
                bm->Erase(); // clear it in the terminal 
                bm = bmons.erase(bm); // delete it in the list
                
                rnbX = (rand() % mapWidth) + BORDER_LEFT;
                bmons.push_back(bigmonster(rnbX, BORDER_UP));
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
					break;
                }
            }
        } 
        
		for (bm = bmons.begin(); bm != bmons.end(); bm++) // for every 59 that in the list
		{
			// check whether 59 bumps into passes
			for (p = passes.begin(); p != passes.end(); p++) // for every pass that in the list
			{
				if (Collision(bm->X(), bm->Y(), p->X(), p->Y()))
				{
					gameScore += (GET_GAME_POINT+1);
					p->erase(); // clear it in the terminal
					bm->Erase(); // clear it in the terminal  
					p = passes.erase(p); // delete it in the list
					bm = bmons.erase(bm); // delete it in the list

					rnbX = (rand() % mapWidth) + BORDER_LEFT;
					bmons.push_back(bigmonster(rnbX, BORDER_UP)); // add a new 59 to the list to keep the number of 59s in the game the same
					break;
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
        for (bm = bmons.begin(); bm != bmons.end(); bm++) // for every 59 that in the list
        {
            // check whether 59 bumps into student
            if (Collision(bm->X(), bm->Y(), std.X(), std.Y())) 
            {
                gameScore -= LOSE_GAME_POINT-1;
                std.Erase(); // clear it in the terminal
                bm->Erase(); // clear it in the terminal  
                Sleep(SHOW_MSG_SHORT);
                bm = bmons.erase(bm); // delete it in the list
                
                rnbX = (rand() % mapWidth) + BORDER_LEFT;
                bmons.push_back(bigmonster(rnbX, BORDER_UP)); // add a new 59 to the list to keep the number of 59s in the game the same
				break; //實驗
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
bool game::Collision(double x1, double y1, double x2, double y2) // check whether 59 bumps into any passes
{
    if (abs(x1 -x2) < EQUALITY_GAP_X) // the width of 59 is not the same as the width of "???"   
    {
        if (abs(y1 -y2) < EQUALITY_GAP_Y) 
            return true;
        else
            return false;
    }
    
    return false; 
}
void game::UpdateInfoBar(int gameScore, std::chrono::seconds leftTime) // update game information to the user during the game
{
	//setbkmode(TRANSPARENT);
	outtextxy(TIME_POS_X, TIME_POS_Y, _T("time: "));
	outtextxy(TIME_POS_X + 50, TIME_POS_Y, (leftTime.count() / 10 + '0'));
	outtextxy(TIME_POS_X + 60, TIME_POS_Y, (leftTime.count() % 10 + '0'));
	// because sometimes the digits of number are different, print some white spaces after the number to erase the digits from the previous number 
	outtextxy(CUR_SCORE_POS_X, CUR_SCORE_POS_Y, _T("score: "));
	outtextxy(CUR_SCORE_POS_X + 40, CUR_SCORE_POS_Y, (gameScore / 10 + '0'));
	outtextxy(CUR_SCORE_POS_X + 50, CUR_SCORE_POS_Y, (gameScore % 10 + '0'));
	outtextxy(HIS_SCORE_POS_X, HIS_SCORE_POS_Y, _T("history high: "));
	outtextxy(HIS_SCORE_POS_X + 100, HIS_SCORE_POS_Y, (HISTORY_HIGH_SCORE / 10 + '0'));
	outtextxy(HIS_SCORE_POS_X + 110, HIS_SCORE_POS_Y, (HISTORY_HIGH_SCORE % 10 + '0'));

	if (gameScore >= HISTORY_HIGH_SCORE)
	{
		HISTORY_HIGH_SCORE = gameScore;
		outtextxy(HIS_SCORE_POS_X, HIS_SCORE_POS_Y, _T("history high: "));
		outtextxy(HIS_SCORE_POS_X + 100, HIS_SCORE_POS_Y, (HISTORY_HIGH_SCORE / 10 + '0'));
		outtextxy(HIS_SCORE_POS_X + 110, HIS_SCORE_POS_Y, (HISTORY_HIGH_SCORE % 10 + '0'));
	}
}
 
bool game::PlayAgainOrNot()
{
    Interface::PlayAgainMessage();
    
    char playAgainKey = '0';    
    bool VaildKeyForPlayAgain = false;  
    
    while (!VaildKeyForPlayAgain) // prevent the user from pressing inappropriate keys
    {
        playAgainKey = getchar(); //getch()
        
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
