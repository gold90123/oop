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
    tools::gotoxy(40, y + 9); cout << " 開發人員 :高琉瑜";
    tools::gotoxy(31, y+12); cout << "Press R/r to see game guide. Press other keys to play.";
}

void Interface::GuideMessage()
{
    tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 44;
    int y = 2;
    tools::gotoxy(x,y); cout << " 遊戲指引  |  Game Guide " ;
    y = 5;
    tools::gotoxy(50, y  ); cout << "    前言    ";
    x=35;
    tools::gotoxy(x, y+2); cout << "小傑是一位大學生，正在面臨被當掉的危機。";
    tools::gotoxy(x, y+4); cout << "因為開始懊悔自己怎麼這麼虛度時光，所以決定開始發憤圖強。        ";
    tools::gotoxy(x, y+6); cout << "俗話說的好:「君子報仇，三年不晚。」         ";
    tools::gotoxy(x, y+8); cout << "讓我們一起幫助小傑，然後大家一起手牽手畢業吧 ! ";
    tools::gotoxy(48, y+10); cout << "    遊戲玩法    ";
    tools::gotoxy(x, y+12); cout << "你是小傑，面臨著HEN多59分的考卷，你需要發射'及格'去消滅那些萬惡的59";
    tools::gotoxy(x, y+14); cout <<"發射方式 : 按下鍵盤的空白鍵    移動方式 : 按下鍵盤的方向鍵 ";
    tools::gotoxy(x, y+16); cout <<"計分方式 : 每消滅一個59分即得" << GET_GAME_POINT << "分，若被59分打到，倒扣" << LOSE_GAME_POINT << "分";
    tools::gotoxy(x, y+18); cout <<"遊戲時間共" << TIME_LIMIT << "秒，在時間內打到" << VICTORY_GATE << "分即可PASS。若無請明年再來一次!";
    tools::gotoxy(x, y+20); cout <<"按下任意鍵開始遊戲";
}
void Interface::GameModeMessage()
{
    tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 40;
    int y = 10;
    tools::gotoxy(x,y  ); cout << "   _______       ";
    tools::gotoxy(x,y+1); cout << "  /       \\   請選擇遊戲難度:";
    tools::gotoxy(x,y+2); cout << " / _    _  \\    ";
    tools::gotoxy(x,y+3); cout << "| / \\  / \\  |  簡單：按 E/e";
    tools::gotoxy(x,y+4); cout << "|  _______  |    ";
    tools::gotoxy(x,y+5); cout << " \\ \\_____/ /   困難：按 H/h";
    tools::gotoxy(x,y+6); cout << "  \\_______/     "; 
}
 
void Interface::GameModeMessage()
{
    tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 40;
    int y = 10;
    tools::gotoxy(x,y  ); cout << "   _______       ";
    tools::gotoxy(x,y+1); cout << "  /       \\   請選擇遊戲難度:";
    tools::gotoxy(x,y+2); cout << " / _    _  \\    ";
    tools::gotoxy(x,y+3); cout << "| / \\  / \\  |  簡單：按 E/e";
    tools::gotoxy(x,y+4); cout << "|  _______  |    ";
    tools::gotoxy(x,y+5); cout << " \\ \\_____/ /   困難：按 H/h";
    tools::gotoxy(x,y+6); cout << "  \\_______/     "; 
}
 
void Interface::VictoryMessage()
{
    tools::DrawWhiteSpace(BORDER_LEFT_WIDE, BORDER_UP, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 25;
    int y = 10;
    tools::gotoxy(x, y  ); cout << " _______          ____          _______      _______         __      ";
    tools::gotoxy(x, y+1); cout << "|  ___  \\        / __ \\        |  _____|    |  _____|       |  |       ";
    tools::gotoxy(x, y+2); cout << "| |   | |       / /  \\ \\       | |          | |             |  |____  ";
    tools::gotoxy(x, y+3); cout << "| |___| |      / /____\\ \\      | |_____     | |_____        |    ___|     ";
    tools::gotoxy(x, y+4); cout << "|  _____/     /  ______  \\     |_____  |    |_____  |       |    ___|  ";
    tools::gotoxy(x, y+5); cout << "| |          / /        \\ \\     _____| |     _____| |       |    ___|     ";
    tools::gotoxy(x, y+6); cout << "|_|         /_/          \\_\\   |_______|    |_______|       |_______|    ";
    tools::gotoxy(x, y+8); cout << " 恭喜!   你過了!!!!!!!! " ;
}
 
void Interface::DefeatMessage()
{
    tools::DrawWhiteSpace(BORDER_LEFT_WIDE, BORDER_UP, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 25;
    int y = 10;
    tools::gotoxy(x, y  ); cout << " _         _______    _______    _______    _______                       ";
    tools::gotoxy(x, y+1); cout << "| |       |  ___  |  |  _____|  |  _____|  |  ___  \\               ";
    tools::gotoxy(x, y+2); cout << "| |       | |   | |  | |        | |_____   | |___|  |     _____           ";
    tools::gotoxy(x, y+3); cout << "| |       | |   | |  | |_____   |  _____|  |  ___  /     /     \\    _ ___     ";
    tools::gotoxy(x, y+4); cout << "| |       | |   | |  |_____  |  | |        | |   \\ \\    |       | |/    /           ";
    tools::gotoxy(x, y+5); cout << "| |____   | |___| |   _____| |  | |_____   | |    \\ \\   |       | |    /          ";
    tools::gotoxy(x, y+6); cout << "|______|  |_______|  |_______|  |_______|  |_|     \\_\\   \\_____/  |   /____                 ";
    tools::gotoxy(x, y+8); cout << " 明年再接再厲!! 好好加油!!! ";
}
 
void Interface::PlayAgainMessage()
{
    tools::DrawWhiteSpace(0, 0, BORDER_RIGHT, BORDER_DOWN);
    int x = 10;
    int y = 10;
    tools::gotoxy(x, y  ); cout << " _______    _                     _    _                      ________                _     _      _              ";
    tools::gotoxy(x, y+1); cout << "|  ___  |  | |             /\\    \\ \\  / /            /\\      |  ____  |      /\\      | |   |  \\   | |               ";
    tools::gotoxy(x, y+2); cout << "| |___| |  | |            //\\\\    \\ \\/ /            //\\\\     | |    |_|     //\\\\     | |   | |\\\\  | |                ";
    tools::gotoxy(x, y+3); cout << "|  _____|  | |           //__\\\\    \\  /            //__\\\\    | |  ____     //__\\\\    | |   | | \\\\ | |               ";
    tools::gotoxy(x, y+4); cout << "| |        | |          / ____ \\    | |           / ____ \\   | | |__  |   / ____ \\   | |   | |  \\\\| |             ";
    tools::gotoxy(x, y+5); cout << "| |        | |_____    / /    \\ \\   | |          / /    \\ \\  | |____| |  / /    \\ \\  | |   | |   \\  |           ";
    tools::gotoxy(x, y+6); cout << "|_|        |_______|  /_/      \\_\\  |_|         /_/      \\_\\ |________| /_/      \\_\\ |_|   |_|    \\_|                       ";
    tools::gotoxy(x, y+8); cout << " 再玩一次請按 Y/y 結束請按 N/n ";
}
 
void Interface::GoodbyeMessage()
{ 
    tools::DrawWhiteSpace(0, 0, BORDER_RIGHT_WIDE, BORDER_DOWN);
    int x = 15;
    int y = 10;
    tools::gotoxy(x,y  ); cout << "   _____       _______     _______     ______      ______   __      __    _______    __    __";
    tools::gotoxy(x,y+1); cout << "  / ___ \\    ||  ___  |  ||  ___  |  ||  ___ \\   ||  ___ \\  \\ \\    / /  ||  _____|  |  |  |  |";
    tools::gotoxy(x,y+2); cout << " / /   \\_\\   || |   | |  || |   | |  || |   \\ \\  || |___\\ |  \\ \\  / /   || |_____   |  |  |  |";
    tools::gotoxy(x,y+3); cout << "/ /   ____   || |   | |  || |   | |  || |    \\ \\ ||  ___ /     \\\\//     ||  _____|  |  |  |  |";
    tools::gotoxy(x,y+4); cout << "\\ \\  |__  /  || |   | |  || |   | |  || |    / / || |   \\ \\     | |     || |        |__|  |__|";
    tools::gotoxy(x,y+5); cout << " \\ \\___/ /   || |___| |  || |___| |  || |___/ /  || |___/  |    | |     || |_____    __    __";
    tools::gotoxy(x,y+6); cout << "  \\____ /    ||_______|  ||_______|  ||______/   ||_______/     |_|     ||_______|  |__|  |__|";
    tools::gotoxy(x,y+8); cout << " Thanks for playing!";
}