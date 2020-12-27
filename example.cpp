#include <iostream>
#include <cstdlib> // generate random number 
#include <cmath>
#include <ctime> // random number seed
#include <chrono> // timing
#include <list> // use dynamic list as a container for 59s and passes("及格") in the game
#include <conio.h> //  input from keyboard to terminal
#include <windows.h> // control terminal
using namespace std;
 
#define KEY_UP    72 // arrow keys' ascii numbers
#define KEY_DOWN  80
#define KEY_LEFT  75
#define KEY_RIGHT 77
#define BORDER_UP 2 // border for the objects in the game
#define BORDER_DOWN 28
#define BORDER_LEFT 43  
#define BORDER_LEFT_WIDE 2  
#define BORDER_RIGHT 73 
#define BORDER_RIGHT_WIDE 115 
#define STUDENT_INITIAL_X 58.5 // the position of student at the beginning of the game
#define STUDENT_INITIAL_Y 25
#define EQUALITY_GAP_X 1.5 // for checking whether 59s bump into the student
#define EQUALITY_GAP_Y 1
#define CUR_SCORE_POS_X 50 // the position of game information during the game
#define CUR_SCORE_POS_Y 0  
#define HIS_SCORE_POS_X 80
#define HIS_SCORE_POS_Y 0 
#define TIME_POS_X 20 
#define TIME_POS_Y 0 
#define SPEED_STUDENT 1.1 // the speed of student
#define SPEED_SCORE59_EASY 0.1 // the speed of 59 in easy mode
#define SPEED_SCORE59_HARD 0.5 // the speed of 59 in hard mode
#define SPEED_PASS 0.5 // the speed of pass 
#define TIME_LIMIT 30 // time limit for the game
#define INTERVAL_BETWEEN_EACH_LOOP 20 // the interval between each while loop during the game
#define SHOW_MSG_SHORT 100 // Sleep() is in the unit of ms
#define SHOW_MSG_LONG 1500
#define SCORE59_CNT 10 // the number of 59s that appear in the game 
#define GET_GAME_POINT 2
#define LOSE_GAME_POINT 5
#define VICTORY_GATE 60
 
void gotoxy(double x, double y); // allows to move inside the terminal using coordinates // the type is double, so objects can move less than 1 unit 
void DrawWhiteSpace(int a_x, int a_y, int b_x, int b_y); // to clean a certain space in the terminal 
void Initialize(); // set console title and hide console cursor 
void ChooseGameMode(); // choose the level of the game
bool StartGame(); // the shooting game itself 
bool Collision(double x1, double y1, double x2, double y2); // check whether 59 bumps into any passes / student 
void UpdateInfoBar(int gameScore, std::chrono::seconds leftTime); // update the scores and timing during the game
bool PlayAgainOrNot(); // ask whether the user plays the game again or not
void WelcomeMessage(); // the following are some messages for the user during different stages of the program
void GuideMessage();
void GameModeMessage();
void VictoryMessage();
void DefeatMessage();
void PlayAgainMessage();
void GoodbyeMessage();
 
int HISTORY_HIGH_SCORE = 0; // used to record the highest scores during the whole program
 

class Student //主角
{
private:
    double x; // x coordinate
    double y; // y coordinate 
public:
    Student(double x, double y) { this->x = x; this->y = y; }
    double X() { return x; } 
    double Y() { return y; }
    void Draw(); // show the current position of student in the terminal
    void Erase(); // clear the current position of student in the terminal 
    void Move(); // move student (Erase()+Draw())
};
 
void Student::Draw()
{
    gotoxy(x, y); cout << "🐒";
}
 
void Student::Erase()
{
    gotoxy(x, y); cout << " ";
}
 
void Student::Move()
{
    if(kbhit())
    {
        Erase();
        
        char key = getch();
        switch(key)
        {
            case KEY_LEFT: if(x - SPEED_STUDENT > BORDER_LEFT) { x -= SPEED_STUDENT; break; }
            case KEY_RIGHT: if (x + SPEED_STUDENT < BORDER_RIGHT) { x += SPEED_STUDENT; break; }
            case KEY_UP: if (y - SPEED_STUDENT > BORDER_UP) { y -= SPEED_STUDENT; break; }
            case KEY_DOWN: if (y + SPEED_STUDENT < BORDER_DOWN) { y += SPEED_STUDENT; break; } 
        }
    }
    
    Draw(); // wheter the user press key, there is always a student in the terminal     
}
 
class Score59 //怪物
{
private:
    double x; // x coordinate
    double y; // y coordinate 
    static bool gameMode;
public:
    static void setGameMode(bool level); // true(1) is the easy mode while false(0) is the hard mode
    Score59(double x, double y) { this->x = x; this->y = y; }
    double X() { return x; } 
    double Y() { return y; }
    void Draw(); // show the current position of 59 in the terminal
    void Erase(); // clear the current position of student in the terminal
    void Move(); // move 59 
    bool isOut(); // detect whether 59 is out of the boundry
};
 
void Score59::Draw()
{
    gotoxy(x, y); cout << "59"; 
}
 
void Score59::Erase()
{
    gotoxy(x, y); cout << "  ";  
}
 
void Score59::Move()
{
    Erase();
    
    if (gameMode == 1)
        y += SPEED_SCORE59_EASY; // move a SPEED_SCORE59 unit downward
    else
        y += SPEED_SCORE59_HARD;
        
    Draw(); 
}
 
bool Score59::isOut()
{
    if (y > BORDER_DOWN)
        return true;
    else
        return false;
}
 
bool Score59::gameMode = 1; // the user play the game in easy mode by default
 
void Score59::setGameMode(bool level)
{
    gameMode = level;
}
 
class Pass //子彈
{
private:
    int x; // x coordinate
    int y; // y coordinate 
public:
    Pass(double x, double y) { this->x = x; this->y = y; }
    double X() { return x; } 
    double Y() { return y; }
    void Draw(); // show the current position of pass in the terminal 
    void Erase(); // clear the current position of pass in the terminal
    void Move(); // move pass
    bool isOut(); // detect whether pass is out of the boundry
};
 
void Pass::Draw()
{
    gotoxy(x, y); cout << "🍌"; //  while (y - 1) means a row above y
   // gotoxy(x, y + 1); cout << "格"; // (y + 1) means a row below y
 
}
 
void Pass::Erase()
{
    gotoxy(x, y); cout << "  ";     
   // gotoxy(x, y + 1); cout << "  ";     
}
 
void Pass::Move()
{
    Erase();
    y -= SPEED_PASS; // move a SPEED_PASS unit upward
    Draw(); 
}
 
bool Pass::isOut()
{
    if (y < BORDER_UP)
        return true;
    else
        return false;
}
 
int main()
{
    Initialize(); // some background settings 
    
    WelcomeMessage();
    char guideKey = getch();
    
    if (guideKey == 'r' || guideKey == 'R') // press R/r to see the game guide
    {
        GuideMessage();
        getch(); // press any key to play the game
    }
    
    bool playAgain = true;
    
    while (playAgain)
    {
        ChooseGameMode();
        
        bool gameVictory = true;
        gameVictory = StartGame();  
        
        if (gameVictory)
        {
            VictoryMessage();
            Sleep(SHOW_MSG_LONG); // make sure the user can see this message clearly
        }
        
        else
        {
            DefeatMessage();
            Sleep(SHOW_MSG_LONG); // make sure the user can see this message clearly    
        }
        
        playAgain = PlayAgainOrNot();
    }
    
    GoodbyeMessage();
    Sleep(SHOW_MSG_LONG);
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    
    return 0;
}
 
void gotoxy(double x, double y) // allows to move inside the terminal using coordinates 
{   // the type is double, so objects can move less than 1 unit 
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x; // start from 0
    dwPos.Y = y; // start from 0
    SetConsoleCursorPosition(hCon, dwPos);
}
 
void DrawWhiteSpace(int a_x, int a_y, int b_x, int b_y) // to clean a certain space in the terminal 
{ 
    for(int i = a_x; i <= b_x; i++)
    {
        for(int j = a_y; j <= b_y; j++)
        {
            gotoxy(i,j); 
            cout << " ";
        }
    }
}
 
void Initialize() // set console title and hide console cursor
{
    // set console title
    
    // hide console cursor
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cci);
}
 
void ChooseGameMode()
{
    GameModeMessage();
    
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
        Score59::setGameMode(1); // 1 (true) is easy mode                   
    }
    
    else
    {
        Score59::setGameMode(0); // 0 (false) is hard mode                  
    }
}
 
bool StartGame()
{   
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    
    std::chrono::seconds timeLimit(TIME_LIMIT); // transform int/double to seconds defined by chrono
    std::chrono::seconds duration(0); // calculate how long has the game since it started
    std::chrono::seconds leftTime(TIME_LIMIT); // calculate how many seconds are left
    auto start = chrono::steady_clock::now(); // record the start time
    int gameScore = 0; // the score of the game
    
    Student std = Student(STUDENT_INITIAL_X, STUDENT_INITIAL_Y); // the position of student in the beginning
    list<Score59> scores; // dynamic list for 59("五九")  
    list<Score59>::iterator s; // iterator for the list
    list<Pass> passes; // dynamic list for pass("及格") 
    list<Pass>::iterator p; // another iterator for this list 
    
    srand(time(nullptr)); // generate random number for the positions of 59s
    int mapWidth = BORDER_RIGHT - BORDER_LEFT + 1; // border included
    int mapLength = BORDER_DOWN - BORDER_UP + 1; // border included
    double rnX = 0;
    double rnY = 0; // initialize random number
    for (int i = 0; i < SCORE59_CNT; i++) // generate 59s
    {
        rnX = (rand() % mapWidth) + BORDER_LEFT;
        rnY = (rand() % (mapLength / 2)) + (BORDER_UP); //  (mapLength / 2) prevents 59s from being too low on the map at first
        scores.push_back(Score59(rnX, rnY));
    }
    
    while(duration < timeLimit) // while the game is not end
    {   
        for (p = passes.begin(); p != passes.end(); p++) // for every pass that in the list
        {
            p->Move(); // move a SPEED_PASS unit upward
            if (p->isOut()) // if the pass reaches the top of map
            {
                p->Erase(); // clear it in the terminal 
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
                scores.push_back(Score59(rnX, BORDER_UP)); // add a new 59 to the list to keep the number of 59s in the game the same
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
                    p->Erase(); // clear it in the terminal
                    s->Erase(); // clear it in the terminal  
                    p = passes.erase(p); // delete it in the list
                    s = scores.erase(s); // delete it in the list
                    
                    rnX = (rand() % mapWidth) + BORDER_LEFT;
                    scores.push_back(Score59(rnX, BORDER_UP)); // add a new 59 to the list to keep the number of 59s in the game the same
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
                scores.push_back(Score59(rnX, BORDER_UP)); // add a new 59 to the list to keep the number of 59s in the game the same
            }           
        }
                 
        if(kbhit())
        {
            char key = getch();
            if(key == ' ') // press the space bar, and add a pass to the pass list
            {
                passes.push_back(Pass(std.X(), std.Y() - 1));
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
    gotoxy(TIME_POS_X, TIME_POS_Y); cout << "剩餘時間: " << leftTime.count() << "   "; // update time 
    // because sometimes the digits of number are different, print some white spaces after the number to erase the digits from the previous number 
    gotoxy(CUR_SCORE_POS_X, CUR_SCORE_POS_Y); cout << "分數: " << gameScore << "  "; // update game score 
    gotoxy(HIS_SCORE_POS_X, HIS_SCORE_POS_Y); cout << "歷史高分: " << HISTORY_HIGH_SCORE; // update history high game score     
    if (gameScore >= HISTORY_HIGH_SCORE)
    {
        HISTORY_HIGH_SCORE = gameScore;
        gotoxy(HIS_SCORE_POS_X, HIS_SCORE_POS_Y); cout << "歷史高分: " << HISTORY_HIGH_SCORE; // update history high game score     
    }
}
 
bool PlayAgainOrNot()
{
    PlayAgainMessage();
    
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
 
void WelcomeMessage()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 20;
    int y = 10;
    gotoxy(x, y  ); cout <<"  _____    _       _    _   _      _   _   ___    __    __   ______    _    _    _   ";
    gotoxy(x, y+1); cout <<" |  ___|  | |     | |  | | |  \\   | | | | /  /    \\ \\  / /  |  __  |  | |  | |  | |      " ;
    gotoxy(x, y+2); cout <<" | |___   | |     | |  | | | |\\\\  | | | |/  /      \\ \\/ /   | |  | |  | |  | |  | |       " ;
    gotoxy(x, y+3); cout <<" |  ___|  | |     | |  | | | | \\\\ | | |    /        \\  /    | |  | |  | |  | |  | |          ";
    gotoxy(x, y+4); cout <<" | |      | |     | |  | | | |  \\\\| | | |\\ \\         | |    | |  | |  | |  | |  |_|      ";                             
    gotoxy(x, y+5); cout <<" | |      | |___  | |__| | | |   \\  | | | \\ \\        | |    | |__| |  | |__| |   _         ";
    gotoxy(x, y+6); cout <<" |_|      |_____| |______| |_|    \\_| |_|  \\_\\       |_|    |______|  |______|  |_|       ";
    gotoxy(40, y+9); cout <<" developed by 驚奇4超人 C++. - 2019";
    gotoxy(31, y+12); cout << "Press R/r to see game guide. Press other keys to play.";
}
 
void GuideMessage()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 44;
    int y = 2;
    gotoxy(x,y); cout << " 遊戲指引  |  Game Guide " ;
    y = 5;
    gotoxy(50, y  ); cout << "    前言    ";
    x=35;
    gotoxy(x, y+2); cout << "小傑是一位大學生，正在面臨被當掉的危機。";
    gotoxy(x, y+4); cout << "因為開始懊悔自己怎麼這麼虛度時光，所以決定開始發憤圖強。        ";
    gotoxy(x, y+6); cout << "俗話說的好:「君子報仇，三年不晚。」         ";
    gotoxy(x, y+8); cout << "讓我們一起幫助小傑，然後大家一起手牽手畢業吧 ! ";
    gotoxy(48, y+10); cout << "    遊戲玩法    ";
    gotoxy(x, y+12); cout << "你是小傑，面臨著HEN多59分的考卷，你需要發射'及格'去消滅那些萬惡的59";
    gotoxy(x, y+14); cout <<"發射方式 : 按下鍵盤的空白鍵    移動方式 : 按下鍵盤的方向鍵 ";
    gotoxy(x, y+16); cout <<"計分方式 : 每消滅一個59分即得" << GET_GAME_POINT << "分，若被59分打到，倒扣" << LOSE_GAME_POINT << "分";
    gotoxy(x, y+18); cout <<"遊戲時間共" << TIME_LIMIT << "秒，在時間內打到" << VICTORY_GATE << "分即可PASS。若無請明年再來一次!";
    gotoxy(x, y+20); cout <<"按下任意鍵開始遊戲";
}
 
void GameModeMessage()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 40;
    int y = 10;
    gotoxy(x,y  ); cout << "   _______       ";
    gotoxy(x,y+1); cout << "  /       \\   請選擇遊戲難度:";
    gotoxy(x,y+2); cout << " / _    _  \\    ";
    gotoxy(x,y+3); cout << "| / \\  / \\  |  簡單：按 E/e";
    gotoxy(x,y+4); cout << "|  _______  |    ";
    gotoxy(x,y+5); cout << " \\ \\_____/ /   困難：按 H/h";
    gotoxy(x,y+6); cout << "  \\_______/     "; 
}
 
void VictoryMessage()
{
    DrawWhiteSpace(BORDER_LEFT_WIDE, BORDER_UP, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 25;
    int y = 10;
    gotoxy(x, y  ); cout << " _______          ____          _______      _______         __      ";
    gotoxy(x, y+1); cout << "|  ___  \\        / __ \\        |  _____|    |  _____|       |  |       ";
    gotoxy(x, y+2); cout << "| |   | |       / /  \\ \\       | |          | |             |  |____  ";
    gotoxy(x, y+3); cout << "| |___| |      / /____\\ \\      | |_____     | |_____        |    ___|     ";
    gotoxy(x, y+4); cout << "|  _____/     /  ______  \\     |_____  |    |_____  |       |    ___|  ";
    gotoxy(x, y+5); cout << "| |          / /        \\ \\     _____| |     _____| |       |    ___|     ";
    gotoxy(x, y+6); cout << "|_|         /_/          \\_\\   |_______|    |_______|       |_______|    ";
    gotoxy(x, y+8); cout << " 恭喜!   你過了!!!!!!!! " ;
}
 
void DefeatMessage()
{
    DrawWhiteSpace(BORDER_LEFT_WIDE, BORDER_UP, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 25;
    int y = 10;
    gotoxy(x, y  ); cout << " _         _______    _______    _______    _______                       ";
    gotoxy(x, y+1); cout << "| |       |  ___  |  |  _____|  |  _____|  |  ___  \\               ";
    gotoxy(x, y+2); cout << "| |       | |   | |  | |        | |_____   | |___|  |     _____           ";
    gotoxy(x, y+3); cout << "| |       | |   | |  | |_____   |  _____|  |  ___  /     /     \\    _ ___     ";
    gotoxy(x, y+4); cout << "| |       | |   | |  |_____  |  | |        | |   \\ \\    |       | |/    /           ";
    gotoxy(x, y+5); cout << "| |____   | |___| |   _____| |  | |_____   | |    \\ \\   |       | |    /          ";
    gotoxy(x, y+6); cout << "|______|  |_______|  |_______|  |_______|  |_|     \\_\\   \\_____/  |   /____                 ";
    gotoxy(x, y+8); cout << " 明年再接再厲!! 好好加油!!! ";
}
 
void PlayAgainMessage()
{
    DrawWhiteSpace(0, 0, BORDER_RIGHT, BORDER_DOWN);
    int x = 10;
    int y = 10;
    gotoxy(x, y  ); cout << " _______    _                     _    _                      ________                _     _      _              ";
    gotoxy(x, y+1); cout << "|  ___  |  | |             /\\    \\ \\  / /            /\\      |  ____  |      /\\      | |   |  \\   | |               ";
    gotoxy(x, y+2); cout << "| |___| |  | |            //\\\\    \\ \\/ /            //\\\\     | |    |_|     //\\\\     | |   | |\\\\  | |                ";
    gotoxy(x, y+3); cout << "|  _____|  | |           //__\\\\    \\  /            //__\\\\    | |  ____     //__\\\\    | |   | | \\\\ | |               ";
    gotoxy(x, y+4); cout << "| |        | |          / ____ \\    | |           / ____ \\   | | |__  |   / ____ \\   | |   | |  \\\\| |             ";
    gotoxy(x, y+5); cout << "| |        | |_____    / /    \\ \\   | |          / /    \\ \\  | |____| |  / /    \\ \\  | |   | |   \\  |           ";
    gotoxy(x, y+6); cout << "|_|        |_______|  /_/      \\_\\  |_|         /_/      \\_\\ |________| /_/      \\_\\ |_|   |_|    \\_|                       ";
    gotoxy(x, y+8); cout << " 再玩一次請按 Y/y 結束請按 N/n ";
}
 
void GoodbyeMessage()
{ 
    DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 15;
    int y = 10;
    gotoxy(x,y  ); cout << "   _____       _______     _______     ______      ______   __      __    _______    __    __";
    gotoxy(x,y+1); cout << "  / ___ \\    ||  ___  |  ||  ___  |  ||  ___ \\   ||  ___ \\  \\ \\    / /  ||  _____|  |  |  |  |";
    gotoxy(x,y+2); cout << " / /   \\_\\   || |   | |  || |   | |  || |   \\ \\  || |___\\ |  \\ \\  / /   || |_____   |  |  |  |";
    gotoxy(x,y+3); cout << "/ /   ____   || |   | |  || |   | |  || |    \\ \\ ||  ___ /     \\\\//     ||  _____|  |  |  |  |";
    gotoxy(x,y+4); cout << "\\ \\  |__  /  || |   | |  || |   | |  || |    / / || |   \\ \\     | |     || |        |__|  |__|";
    gotoxy(x,y+5); cout << " \\ \\___/ /   || |___| |  || |___| |  || |___/ /  || |___/  |    | |     || |_____    __    __";
    gotoxy(x,y+6); cout << "  \\____ /    ||_______|  ||_______|  ||______/   ||_______/     |_|     ||_______|  |__|  |__|";
    gotoxy(x,y+8); cout << " Thanks for playing!";
}