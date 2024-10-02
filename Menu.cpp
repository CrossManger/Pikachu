#include "Header.h"

void interactWithMenu(vector <Player*> list, int playerPos)
{
    int** board = NULL;

BACK_TO_MENU:
    TextColor(WHITE);
    displayMenuScreen();
    bool hackFile = false;
    Board gameBoard;
    int choice = 1;
    bool menuLoop = true;
    while (menuLoop)
    {
        if (choice == 1)
            TextColor(YELLOW);
        displayBox(53, 17, 3, 14, "PLAY");
        TextColor(WHITE);

        if (choice == 2)
            TextColor(YELLOW);
        displayBox(53, 21, 3, 14, "RANK");
        TextColor(WHITE);

        if (choice == 3)
            TextColor(YELLOW);
        displayBox(53, 25, 3, 14, "HELP");
        TextColor(WHITE);

        if (choice == 4)
            TextColor(YELLOW);
        displayBox(53, 29, 3, 14, "EXIT");
        TextColor(WHITE);

        int input = _getch();

        switch (input)
        {
        case KEY_UP:
            choice--;
            if (choice < 1) choice = 4; // if the user goes past the first option, loop back to the last option
            break;

        case KEY_DOWN:
            choice++;
            if (choice > 4) choice = 1; // if the user goes past the last option, loop back to the first option
            break;

        case KEY_ENTER: case SPACE_BAR:
            PlaySound(TEXT("SELECT.wav"), NULL, SND_ASYNC);
            switch (choice)
            {
            case 1: // play
                choice = 1;
                deleteBox(53, 29, 3, 14);
                while (menuLoop)
                {
                    if (choice == 1)
                        TextColor(YELLOW);
                    displayBox(53, 17, 3, 14, "EASY");
                    TextColor(WHITE);

                    if (choice == 2)
                        TextColor(YELLOW);
                    displayBox(53, 21, 3, 14, "HARD");
                    TextColor(WHITE);

                    if (choice == 3)
                        TextColor(YELLOW);
                    displayBox(53, 25, 3, 14, "CUSTOM");
                    TextColor(WHITE);

                    if (choice == 4)
                        TextColor(YELLOW);
                    displayBox(53, 29, 3, 14, "BACK");
                    TextColor(WHITE);

                    int input = _getch();

                    switch (input)
                    {
                    case KEY_UP:
                        choice--;
                        if (choice < 1) choice = 4;
                        break;

                    case KEY_DOWN:
                        choice++;
                        if (choice > 4) choice = 1;
                        break;

                    case KEY_ENTER: case SPACE_BAR:

                        PlaySound(TEXT("SELECT.wav"), NULL, SND_ASYNC);
                        

                        switch (choice)
                        {
                        case 1: //EASY MODE                               
                            Gameplay(board, 0, gameBoard, list, playerPos);
                            deleteBoard(board, gameBoard);

                            system("cls");
                            goto BACK_TO_MENU;

                        case 2: // HARD MODE                         
                            Gameplay(board, 1, gameBoard, list, playerPos);
                            deleteBoard(board, gameBoard);

                            system("cls");
                            goto BACK_TO_MENU;

                        case 3: //CUSTOM MODE
                            int mode;
                            if (!hackFile)
                                customScreen(mode, gameBoard);
                            else
                                mode = 0;
                            GameplayCustom(board, mode, gameBoard, list, playerPos, hackFile);
                            deleteBoard(board, gameBoard);

                            system("cls");
                            goto BACK_TO_MENU;

                        case 4: // BACK
                            deleteBox(53, 25, 3, 14);
                            goto BACK_TO_MENU;
                            break;
                        }
                    }
                }
                gotoxy(0, 40);
                system("pause");
                menuLoop = false;
                break;

            case 2: // LEADERBOARD
                system("cls");
                displayScreen();
                leaderboardScreen(list);
                goto BACK_TO_MENU;
                break;

            case 3: //HELP
                system("cls");
                displayScreen();
                helpScreen();
                goto BACK_TO_MENU;
                break;

            case 4: //EXIT
                outputInfoPlayerBin(list, "Player.bin");
                system("cls");
                exit(0);
                break;
            }
        }
    }
}
