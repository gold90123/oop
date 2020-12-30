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

class tools
{
public:
    static void gotoxy(double x, double y);
    static void DrawWhiteSpace(int a_x, int a_y, int b_x, int b_y);
    static void Initialize();
    static void WelcomeMessage(); 
};