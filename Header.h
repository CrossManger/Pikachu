#pragma comment(lib, "winmm.lib")
#pragma warning(disable : 4996)
#include <iostream>
#include <Windows.h>
#include <conio.h.>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <mmsystem.h>
#include <cmath>
#include <cstring>
#include <ctime>
#include <string>
using namespace std;

// Save file hacking
#define PADDING 500
#define NAMESIZE 50
#define PASSSIZE 50
#define BOARDSIZE 999
#define URLSIZE 100

// COLOR CODE
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

// MOVEMENT
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27
#define SPACE_BAR 32
#define KEY_F 102
#define KEY_H 104
#define KEY_S 115

// SCREEN SIZE
#define screenWidth 120
#define screenHeight 35

struct State
{
    int p, q;
    int p_, q_;
    char board[BOARDSIZE];
    char file_background[URLSIZE];
};

struct Date
{
    int dd, mm, yy;
};

struct Record
{
    Date date;	// Date of completed record
    int points; // points achieved
    // 500 byte NULL
};

struct savefile
{
    char mask;
    char name[NAMESIZE];
    char password[PASSSIZE];
    //Player* list;
    Record record[5];
    State state[5];
};

struct Board {
    int col;
    int row;
    int width; //col * cell width
    int height; //row * cell Height
};

struct Pokemon {
    int i; //index
    int j;

    int x; //coordinate
    int y; // x = 4 + (j - 1) * 10, 3 + (i - 1) * 5
};

struct InforMatches
{
    int bestPoint = 0;
    int bestTime = 0;
    int matches = 0;
    int mistake = 0;
    int point = 0;
    int move = 0;
    int pokemon = 0;
    int time = 0;
    int** board = NULL;
};
struct Player
{
    char userName[20];
    InforMatches* Easy;
    InforMatches* Hard;
};


// Funcions in Function.cpp - doing basic functions for game UI
void gotoxy(int x, int y);                                               
void TextColor(int x);                                                   
void ShowConsoleCursor(bool showFlag); // 0: hide cursor, 1: show cursor  

// Function in Screen.cpp - display different screens
void IntroScreen();
void loginScreen(vector <Player*>& list, int& playerPos);
void helpScreen();
void leaderboardScreen(vector <Player*> list);
void customScreen(int& mode, Board& gameBoard);

// Function in Menu.cpp
void interactWithMenu(vector <Player*> list, int playerPos);

// Functions in Display.cpp - Draw image
void displayBox(int x, int y, int boxHeight, int boxWidth, string s);    
void displayScreen();
void displayLogo(int x, int y);
void displayMenuScreen();
void displayGameBox(int x, int y, int boxHeight, int boxWidth, int** board, Board gameBoard);
void displayPokeball(int x, int y, int ball_color);
void displayBackground_1(int x, int y);
void deleteBox(int x, int y, int boxHeight, int boxWidth);
void displayBoxChar(int x, int y, int boxHeight, int boxWidth, char s);
void displayPlayerInfo(vector <Player*> list, int playerPos);
void displayGameStatistic();
void displayGameInstruction();
void updateGameStatistic(int point, int move, int mistake);
void displayWinGame(int time, int& choice);
void displayConfirmQuit(int& choice);
void displayContinueGame(int& choice);
void matchingLineType(Pokemon p, int type);
void displayMatchingLine(Pokemon p1, Pokemon p2, int** board, Pokemon*& temp, Board gameBoard, bool display);
void displayMatchingLineL(Pokemon p1, Pokemon p2, Pokemon corner, int** board, Board gameBoard);
void matchingLineUZ(Pokemon p1, Pokemon p2, Pokemon corner1, Pokemon corner2, int** board, Board gameBoard);
void displayBackground_2(Pokemon p);
void background_1_upgrade(Pokemon p);

// Functions in Gameplay-Pointer.cpp - Main gameplay
void createBoard(int**& board, Board gameBoard); 
void createPoint(int**& board, Board gameBoard); 
void deletePoint(int** board, Pokemon p1, Pokemon p2, int mode);
bool samePoint(int** board, Pokemon p1, Pokemon p2);
bool matchingI(int** board, Pokemon p1, Pokemon p2);
bool matchingL(int** board, Pokemon p1, Pokemon p2, Pokemon& corner);
bool matchingUZ(int** board, Pokemon& p1, Pokemon& p2, Pokemon& corner1, Pokemon& corner2, Board gameBoard);
bool checkMatching(int** board, Pokemon p1, Pokemon p2, int& point, Board gameBoard, bool display);
bool checkContinue(int** board, Pokemon& p1, Pokemon& p2, Board gameBoard);
void shuffleBoard(int**& board, Board gameBoard);
void Gameplay(int**& board, int mode, Board& gameBoard, vector <Player*> list, int playerPos);
void GameplayCustom(int**& board, int mode, Board& gameBoard, vector <Player*> list, int playerPos, bool &hackFile);
void deleteBoard(int**& board, Board gameBoard);

// Functions in Player.cpp - Store and process players's data
bool checkAvailableUserName(vector <Player*> list, string userName);
void addNewPlayerToList(vector <Player*>& list, string userName);
int posPlayerInList(vector <Player*>& list, string userName);
void copyBoardEasy(vector <Player*> list, int pos, int** board, Board gameBoard);
void copyBoardHard(vector <Player*> list, int pos, int** board, Board gameBoard);
void copyBoard(int** mainBoard, int** board, Board gameBoard);
void outputInfoPlayerBin(vector <Player*> list, string nameFile);
void loadInfoPlayerBin(vector <Player*>& list, string nameFile);
void sortPlayerPointEasy(vector <Player*> list);
void sortPlayerPointHard(vector <Player*> list);
void sortPlayerTimeEasy(vector <Player*> list);
void sortPlayerTimeHard(vector <Player*> list);





