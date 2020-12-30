#include<iostream>
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
    int x = 20;
    int y = 10;
    tools::gotoxy(x, y  ); cout <<"  _____ _           _     _       ";
    tools::gotoxy(x, y+1); cout <<" / ____| |         | |   (_)      " ;
    tools::gotoxy(x, y+2); cout <<"| (___ | |__   ___ | |_   _ _ __  " ;
    tools::gotoxy(x, y+3); cout <<" \___ \| '_ \ / _ \| __| | | '_ \ ";
    tools::gotoxy(x, y+4); cout <<" ____) | | | | (_) | |_  | | | | |";
    tools::gotoxy(x, y+5); cout <<"|_____/|_| |_|\___/ \__| |_|_| |_|";
    tools::gotoxy(40, y + 9); cout << " 開發人員 ";
    tools::gotoxy(31, y+12); cout << "Press R/r to see game guide. Press other keys to play.";
}

void Interface::GuideMessage()
{
    tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 44;
    int y = 2;
    tools::gotoxy(x,y); cout << " 遊戲指引 "  ;
    y = 5;
    //tools::gotoxy(50, y  ); cout << "    前言    "
    x=35;
    tools::gotoxy(x, y+2); cout << "";
    tools::gotoxy(x, y+4); cout << "";
    tools::gotoxy(x, y+6); cout << "";
    tools::gotoxy(x, y+8); cout << "";
    tools::gotoxy(48, y+10); cout << "    遊戲玩法    ";
    tools::gotoxy(x, y+12); cout << "你是主角，很多怪物從天而降，你需要發射「子彈」去消滅那些怪物";
    tools::gotoxy(x, y+14); cout <<"發射方式 : 按下鍵盤的空白鍵    移動方式 : 按下鍵盤的方向鍵 ";
  //  tools::gotoxy(x, y+16); cout <<"計分方式 每消滅一個怪物即得" << GET_GAME_POINT << "分 若被怪物打到 扣" << LOSE_GAME_POINT << "分";
    tools::gotoxy(x, y+18); cout <<"遊戲時間共" << TIME_LIMIT << "秒，在時間內打到" << VICTORY_GATE << "分即可過關";
    tools::gotoxy(x, y+20); cout <<"按下任意鍵開始遊戲";
}
void Interface::GameModeMessage()
{
    tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 40;
    int y = 10;
    tools::gotoxy(x,y  ); cout << "";
    tools::gotoxy(x,y+1); cout << "請選擇遊戲難度:";
    tools::gotoxy(x,y+2); cout << "";
    tools::gotoxy(x,y+3); cout << "簡單：按 E/e";
    tools::gotoxy(x,y+4); cout << "";
    tools::gotoxy(x,y+5); cout << "困難：按 H/h";
    tools::gotoxy(x,y+6); cout << ""; 
}
 
void Interface::VictoryMessage()
{
    tools::DrawWhiteSpace(BORDER_LEFT_WIDE, BORDER_UP, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 25;
    int y = 10;
    tools::gotoxy(x, y  ); cout << "            88                                                       ";
    tools::gotoxy(x, y+1); cout << "            ""              ,d                                       ";
    tools::gotoxy(x, y+2); cout << "                            88                                       ";
    tools::gotoxy(x, y+3); cout << "8b       d8 88  ,adPPYba, MM88MMM ,adPPYba,  8b,dPPYba, 8b       d8  ";
    tools::gotoxy(x, y+4); cout << "`8b     d8' 88 a8\"     \"\"   88   a8\"     \"8a 88P'   \"Y8 `8b     d8'  ";
    tools::gotoxy(x, y+5); cout << " `8b   d8'  88 8b          88   8b       d8 88          `8b   d8'   ";
    tools::gotoxy(x, y+6); cout << "  `8b,d8'   88 \"8a, , aa   88, \"8a,   ,a8\" 88           `8b,d8'";
    tools::gotoxy(x, y+7); cout << "    \"8\"     88  `\"Ybbd8\"'   \"Y888 `\"YbbdP\"'  88             Y88'     " ;
    tools::gotoxy(x, y+8); cout << "                                                            d8' ";
    tools::gotoxy(x, y+9); cout << "                                                           d8'    ";



}
 
void Interface::DefeatMessage()
{
    tools::DrawWhiteSpace(BORDER_LEFT_WIDE, BORDER_UP, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 25;
    int y = 10;
    tools::gotoxy(x, y  ); cout << "         @@@ @@@   @@@@@@   @@@  @@@      @@@@@@   @@@@@@@   @@@@@@@@  ";
    tools::gotoxy(x, y+1); cout << "         @@@ @@@  @@@@@@@@  @@@  @@@     @@@@@@@@  @@@@@@@@  @@@@@@@@  ";
    tools::gotoxy(x, y+2); cout << "         @@! !@@  @@!  @@@  @@!  @@@     @@!  @@@  @@!  @@@  @@!       ";
    tools::gotoxy(x, y+3); cout << "         !@! @!!  !@!  @!@  !@!  @!@     !@!  @!@  !@!  @!@  !@!       ";
    tools::gotoxy(x, y+4); cout << "          !@!@!   @!@  !@!  @!@  !@!     @!@!@!@!  @!@!!@!   @!!!:!    ";
    tools::gotoxy(x, y+5); cout << "           @!!!   !@!  !!!  !@!  !!!     !!!@!!!!  !!@!@!    !!!!!:    ";
    tools::gotoxy(x, y+6); cout << "           !!:    !!:  !!!  !!:  !!!     !!:  !!!  !!: :!!   !!:       ";
    tools::gotoxy(x, y+7); cout << "           :!:    :!:  !:!  :!:  !:!     :!:  !:!  :!:  !:!  :!:       ";
    tools::gotoxy(x, y+8); cout << "            ::    ::::: ::  ::::: ::     ::   :::  ::   :::   :: ::::  ";
    tools::gotoxy(x, y+9); cout << "            :      : :  :    : :  :       :   : :   :   : :  : :: ::   ";
    tools::gotoxy(x, y+10); cout << "";
    tools::gotoxy(x, y+12); cout << "                    @@@        @@@@@@    @@@@@@   @@@@@@@  ";
    tools::gotoxy(x, y+13); cout << "                    @@@       @@@@@@@@  @@@@@@@   @@@@@@@  ";
    tools::gotoxy(x, y+14); cout << "                    @@!       @@!  @@@  !@@         @@!    ";
    tools::gotoxy(x, y+15); cout << "                    !@!       !@!  @!@  !@!         !@!    ";
    tools::gotoxy(x, y+16); cout << "                    @!!       @!@  !@!  !!@@!!      @!!    ";
    tools::gotoxy(x, y+17); cout << "                    !!!       !@!  !!!   !!@!!!     !!!    ";
    tools::gotoxy(x, y+18); cout << "                    !!:       !!:  !!!       !:!    !!:    ";
    tools::gotoxy(x, y+19); cout << "                     :!:      :!:  !:!      !:!     :!:   ";
    tools::gotoxy(x, y+20); cout << "                     :: ::::  ::::: ::  :::: ::      ::    ";
    tools::gotoxy(x, y+21); cout << "                    : :: : :   : :  :   :: : :       :   ";

}
 
void Interface::PlayAgainMessage()
{
    tools::DrawWhiteSpace(0, 0, BORDER_RIGHT, BORDER_DOWN);
    int x = 10;
    int y = 10;
    tools::gotoxy(x, y  ); cout << "         ___   _                                                    _   ";
    tools::gotoxy(x, y+1); cout << "        (  _`\(_ )                                        _       /'_`\ ";
    tools::gotoxy(x, y+2); cout << "        | |_) )| |    _ _  _   _       _ _    __     _ _ (_)  ___(_) ) |";
    tools::gotoxy(x, y+3); cout << "        | ,__/'| |  /'_` )( ) ( )    /'_` ) /'_ `\ /'_` )| |/' _ `\ /'/'";
    tools::gotoxy(x, y+4); cout << "        | |    | | ( (_| || (_) |   ( (_| |( (_) |( (_| || || ( ) ||_|";
    tools::gotoxy(x, y+5); cout << "        (_)   (___)`\__,_)`\__, |   `\__,_)`\__  |`\__,_)(_)(_) (_)(_) ";
    tools::gotoxy(x, y+6); cout << "                          ( )_| |          ( )_) |";
    tools::gotoxy(x, y+7); cout << "                          `\___/'           \___/' ";
    tools::gotoxy(x, y+9); cout << " 再玩一次請按 Y/y 結束請按 N/n ";
}
 
void Interface::GoodbyeMessage()
{ 
    tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 15;
    int y = 10;
    tools::gotoxy(x,y  ); cout << "     .___________. __    __       ___      .__   __.  __  ___      _______.";
    tools::gotoxy(x,y+1); cout << "     |           ||  |  |  |     /   \     |  \ |  | |  |/  /     /       |";
    tools::gotoxy(x,y+2); cout << "     `---|  |----`|  |__|  |    /  ^  \    |   \|  | |  '  /     |   (----`";
    tools::gotoxy(x,y+3); cout << "         |  |     |   __   |   /  /_\  \   |  . `  | |    <       \   \  ";
    tools::gotoxy(x,y+4); cout << "         |  |     |  |  |  |  /  _____  \  |  |\   | |  .  \  .----)   | ";
    tools::gotoxy(x,y+5); cout << "         |__|     |__|  |__| /__/     \__\ |__| \__| |__|\__\ |_______/ ";
    tools::gotoxy(x,y+6); cout << "                        _______   ______   .______      ";
    tools::gotoxy(x,y+7); cout << "                       |   ____| /  __  \  |   _  \   ";
    tools::gotoxy(x,y+8); cout << "                       |  |__   |  |  |  | |  |_)  | ";
    tools::gotoxy(x,y+9); cout << "                       |   __|  |  |  |  | |      /  ";
    tools::gotoxy(x,y+10); cout << "                       |  |     |  `--'  | |  |\  \----.";
    tools::gotoxy(x,y+11); cout << "                       |__|      \______/  | _| `._____|";
    tools::gotoxy(x,y+12); cout << "    .______    __          ___   ____    ____  __  .__   __.   _______  __ ";
    tools::gotoxy(x,y+13); cout << "    |   _  \  |  |        /   \  \   \  /   / |  | |  \ |  |  /  _____||  | ";
    tools::gotoxy(x,y+14); cout << "    |  |_)  | |  |       /  ^  \  \   \/   /  |  | |   \|  | |  |  __  |  |";
    tools::gotoxy(x,y+15); cout << "    |   ___/  |  |      /  /_\  \  \_    _/   |  | |  . `  | |  | |_ | |  | ";
    tools::gotoxy(x,y+16); cout << "    |  |      |  `----./  _____  \   |  |     |  | |  |\   | |  |__| | |__|";
    tools::gotoxy(x,y+17); cout << "    | _|      |_______/__/     \__\  |__|     |__| |__| \__|  \______| (__) ";
}
