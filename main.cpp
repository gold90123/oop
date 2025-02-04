#include<windows.h>
#include<conio.h>
#include"tools.h"
#include"interface.h"
#include"game.h"
#include<graphics.h>
#pragma warning(disable:4996)

#define BORDER_RIGHT_WIDE 533
#define BORDER_DOWN 300
#define SHOW_MSG_LONG 1500

int main()
{
	initgraph(640, 360);
	IMAGE img;
	bool a = 1;

	loadimage(&img, L"C:\\Users\\Username\\Desktop\\starburst2.jpg", 640, 360, a);
	putimage(0, 0, &img);

    tools::Initialize(); // some background settings 
    
    Interface::WelcomeMessage();
    char guideKey = getch();
    
    if (guideKey == 'r' || guideKey == 'R') // press R/r to see the game guide
    {
        Interface::GuideMessage();
        getch(); // press any key to play the game
    }
    
    bool playAgain = true;
    
    while (playAgain)
    {
        game::ChooseGameMode();
        
        bool gameVictory = true;
        gameVictory = game::StartGame();  
        
        if (gameVictory)
        {
            Interface::VictoryMessage();
            Sleep(SHOW_MSG_LONG); // make sure the user can see this message clearly
        }
        
        else
        {
            Interface::DefeatMessage();
            Sleep(SHOW_MSG_LONG); // make sure the user can see this message clearly    
        }
        
        playAgain = game::PlayAgainOrNot();
    }
    
    Interface::GoodbyeMessage();
    Sleep(SHOW_MSG_LONG);
    tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    
    return 0;
}