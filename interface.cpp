#include<iostream>
#include<windows.h>
#include"interface.h"
#include"tools.h"
using namespace std;

#define BORDER_RIGHT_WIDE 115 
#define BORDER_DOWN 28
#define BORDER_RIGHT 73 
#define BORDER_LEFT_WIDE 2
#define BORDER_UP 2
#define VICTORY_GATE 60
#define TIME_LIMIT 30
#define GET_GAME_POINT 2
#define LOSE_GAME_POINT 5

void Interface::WelcomeMessage()
{
    tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 31;
    int y = 10;
    tools::gotoxy(x, y  ); cout <<"  _____ _           _     _       ";
    tools::gotoxy(x, y+1); cout <<" / ____| |         | |   (_)      ";
    tools::gotoxy(x, y+2); cout <<"| (___ | |__   ___ | |_   _ _ ____ ";
    tools::gotoxy(x, y+3); cout <<" \\___  '_ \\ / _ \\ __| | | |_ _  \\";
    tools::gotoxy(x, y+4); cout <<" ____) | | | | (_) | |_  | | | | | |  ";
    tools::gotoxy(x, y+5); cout <<"|_____/|_| |_|\\___/ \\__| |_|_| |_|";
	//○■□ぁ☆★ⅢⅤ┌  can be used
	
	tools::gotoxy(32,y+8); cout  <<"┌───────────────────────────────────────────────┐";
    tools::gotoxy(31,y +9);cout << "〈  ";
	tools::SetColor(27);
	cout<<"Operators:  A1085528    A1085513    A1085535";
	tools::SetColor();
	cout<<"  〉";
    tools::gotoxy(32,y+10); cout <<"└───────────────────────────────────────────────┘";
	
    tools::gotoxy(x, y+12); cout << "Press R/r to see game guide. Press other keys to play.";
}
//
void Interface::GuideMessage()
{
	tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
	int x = 30;
	int y = 5;
	tools::SetColor(11);
	tools::gotoxy(x,y); cout << "How To Play";
	tools::SetColor();
	tools::gotoxy(x,y + 1); cout<< "You have to shoot down as much stars as you can while not getting hit";
	tools::gotoxy(x,y + 2); cout<< "press arrow keys to move";
	tools::gotoxy(x,y + 3); cout<< "press space to shoot";
	

	

}
void Interface::GameModeMessage()
{
	tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
	int x = 40;
	int y = 10;
	tools::gotoxy(x, y); cout << "";
	tools::gotoxy(x, y + 1); cout << "Choose Gamemode:"<<endl;
	tools::gotoxy(x, y + 2); cout << "Easy(e)";
	tools::gotoxy(x, y + 3); cout << "Hard(h)";

}

void Interface::VictoryMessage()
{
	tools::DrawWhiteSpace(BORDER_LEFT_WIDE, BORDER_UP, BORDER_RIGHT_WIDE, BORDER_DOWN+15);
	int x = 25;
	int y = 10;
	tools::SetColor(14);
	tools::gotoxy(x, y); cout << "            88                                                                  ";
	tools::gotoxy(x, y + 1); cout << "            \"\"              ,d                                            ";
	tools::gotoxy(x, y + 2); cout << "                            88                                              ";
	tools::gotoxy(x, y + 3); cout << "8b       d8 88  ,adPPYba, MM88MMM ,adPPYba,  8b,dPPYba, 8b       d8         ";
	tools::gotoxy(x, y + 4); cout << "`8b     d8' 88 a8\"     \"\"   88   a8\"     \"8a 88P'   \"Y8 `8b      d8'  ";
	tools::gotoxy(x, y + 5); cout << " `8b   d8'  88 8b          88   8b       d8 88          `8b   d8'           ";
	tools::gotoxy(x, y + 6); cout << "  `8b,d8'   88 \"8a, , aa   88, \"8a,   ,a8\" 88           `8b,d8'          ";
	tools::gotoxy(x, y + 7); cout << "    \"8\"     88  `\"Ybbd8\"'   \"Y888 `\"YbbdP\"'  88             Y88'     ";
	tools::gotoxy(x, y + 8); cout << "                                                            d8'             ";
	tools::gotoxy(x, y + 9); cout << "                                                           d8'              ";
	tools::SetColor();
}

void Interface::DefeatMessage()
{
	tools::DrawWhiteSpace(BORDER_LEFT_WIDE, BORDER_UP, BORDER_RIGHT_WIDE, BORDER_DOWN+15);
	int x = 25;
	int y = 10;
	tools::SetColor(11);
	tools::gotoxy(x, y); cout << "         @@@ @@@   @@@@@@   @@@  @@@      @@@@@@   @@@@@@@   @@@@@@@@      ";
	tools::gotoxy(x, y + 1); cout << "         @@@ @@@  @@@@@@@@  @@@  @@@     @@@@@@@@  @@@@@@@@  @@@@@@@@  ";
	tools::gotoxy(x, y + 2); cout << "         @@! !@@  @@!  @@@  @@!  @@@     @@!  @@@  @@!  @@@  @@!       ";
	tools::gotoxy(x, y + 3); cout << "         !@! @!!  !@!  @!@  !@!  @!@     !@!  @!@  !@!  @!@  !@!       ";
	tools::gotoxy(x, y + 4); cout << "          !@!@!   @!@  !@!  @!@  !@!     @!@!@!@!  @!@!!@!   @!!!:!    ";
	tools::gotoxy(x, y + 5); cout << "           @!!!   !@!  !!!  !@!  !!!     !!!@!!!!  !!@!@!    !!!!!:    ";
	tools::gotoxy(x, y + 6); cout << "           !!:    !!:  !!!  !!:  !!!     !!:  !!!  !!: :!!   !!:       ";
	tools::gotoxy(x, y + 7); cout << "           :!:    :!:  !:!  :!:  !:!     :!:  !:!  :!:  !:!  :!:       ";
	tools::gotoxy(x, y + 8); cout << "            ::    ::::: ::  ::::: ::     ::   :::  ::   :::   :: ::::  ";
	tools::gotoxy(x, y + 9); cout << "            :      : :  :    : :  :       :   : :   :   : :  : :: ::   ";
	tools::gotoxy(x, y + 10); cout << "                                                                      ";
	tools::gotoxy(x, y + 11); cout << "                                                                      ";
	tools::gotoxy(x, y + 12); cout << "                    @@@        @@@@@@    @@@@@@   @@@@@@@             ";
	tools::gotoxy(x, y + 13); cout << "                    @@@       @@@@@@@@  @@@@@@@   @@@@@@@             ";
	tools::gotoxy(x, y + 14); cout << "                    @@!       @@!  @@@  !@@         @@!               ";
	tools::gotoxy(x, y + 15); cout << "                    !@!       !@!  @!@  !@!         !@!               ";
	tools::gotoxy(x, y + 16); cout << "                    @!!       @!@  !@!  !!@@!!      @!!               ";
	tools::gotoxy(x, y + 17); cout << "                    !!!       !@!  !!!   !!@!!!     !!!               ";
	tools::gotoxy(x, y + 18); cout << "                    !!:       !!:  !!!       !:!    !!:               ";
	tools::gotoxy(x, y + 19); cout << "                     :!:      :!:  !:!      !:!     :!:               ";
	tools::gotoxy(x, y + 20); cout << "                     :: ::::  ::::: ::  :::: ::      ::               ";
	tools::gotoxy(x, y + 21); cout << "                    : :: : :   : :  :   :: : :       :                ";
	tools::SetColor();

}

void Interface::PlayAgainMessage()
{
	tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN+15);
	int x = 10;
	int y = 10;
	tools::gotoxy(x, y); cout << "             ____   _                                                      ___       ";
	tools::gotoxy(x, y + 1); cout << "        (  _ \\ ( )                                         _          / _ \\  ";
	tools::gotoxy(x, y + 2); cout << "        | |_) )| |   _ _   _   _      ____   ____   ____  (_)  _____ (_) ) |  ";
	tools::gotoxy(x, y + 3); cout << "        |  __/ | |  / _  )( ) ( )    / _  ) / _  \\ / _  \\ | | /  _  \\   / / ";
	tools::gotoxy(x, y + 4); cout << "        | |    | | ( (_| || (_) |   ( (_| |( (_) |( (_| | | | | ( ) |  |_|    ";
	tools::gotoxy(x, y + 5); cout << "        (_)   (___) \\__ _) \\__  |    \\___)\\_\\_ | | \\____)\\(_) (_) (_)  (_) ";
	tools::gotoxy(x, y + 6); cout << "                          ( )_| |          ( )_) |                        ";
	tools::gotoxy(x, y + 7); cout << "                           \\___/            \\___/                       ";
	tools::gotoxy(x, y + 9); cout << "Press (Y) to play again           press (n) to end the game"<<endl;
}

void Interface::GoodbyeMessage()
{
	tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN+15);
	int x = 15;
	int y = 10;
	system("Color F0");
	tools::gotoxy(x, y); cout << "          ___________  __    __       ___       __   __   __  ___      _______           ";
	tools::gotoxy(x, y + 1); cout << "     |           ||  |  |  |     /   \\     |  \\ |  | |  |/  /     /  _____|   ";
	tools::gotoxy(x, y + 2); cout << "     `---|  |----`|  |__|  |    /  ^  \\    |   \\|  | |  '  /     |  (__               ";
	tools::gotoxy(x, y + 3); cout << "         |  |     |   __   |   /  /_\\  \\   |       | |    <      \\__   \\          ";
	tools::gotoxy(x, y + 4); cout << "         |  |     |  |  |  |  /  _____  \\  |  |\\   | |  .  \\    ____)   |     ";
	tools::gotoxy(x, y + 5); cout << "         |__|     |__|  |__| /__/     \\__\\ |__| \\__| |__|\\__\\  |_______/     ";
	tools::gotoxy(x, y + 6); cout << "                        ______    ______     ______                               ";
	tools::gotoxy(x, y + 7); cout << "                       |   ___|  /  __  \\   |   _  \\                            ";
	tools::gotoxy(x, y + 8); cout << "                       |  |__   |  |  |  |  |  |_)  |                              ";
	tools::gotoxy(x, y + 9); cout << "                       |   __|  |  |  |  |  |      /                              ";
	tools::gotoxy(x, y + 10); cout << "                      |  |     |  `--'  |  |  |\\  \\__                      ";
	tools::gotoxy(x, y + 11); cout << "                      |__|      \\______/   |__| \\____|                        ";
	tools::gotoxy(x, y + 12); cout << "    .______    __          ___    ____    ____  __  .__    __.   _______   __       ";
	tools::gotoxy(x, y + 13); cout << "    |   _  \\  |  |        /   \\  \\   \\  /   / |  | |  \\  |  |  / ______| |  |   ";
	tools::gotoxy(x, y + 14); cout << "    |  |_)  | |  |       /  ^  \\  \\   \\/   /  |  | |   \\ |  | | |  ____  |  |   ";
	tools::gotoxy(x, y + 15); cout << "    |   ___/  |  |      /  /_\\  \\  \\_    _/   |  | |  . `   | | | |__  | |  |   ";
	tools::gotoxy(x, y + 16); cout << "    |  |      |  `----./  _____  \\   |  |     |  | |  |\\    | | |____| | |__|    ";
	tools::gotoxy(x, y + 17); cout << "    | _|      |_______/__/     \\__\\  |__|     |__| |__| \\___|  \\_______| (__)   ";
}