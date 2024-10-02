#include "Header.h"

void IntroScreen()
{
    PlaySound(TEXT("INTRO.wav"), NULL, SND_ASYNC);
    ShowConsoleCursor(0);
    char c;
    c = 220;
    for (int i = 0; i < screenWidth; i++)
    {
        gotoxy(i, 0);
        cout << c;
        Sleep(5); //5
    }

    c = 222;
    for (int i = 1; i < screenHeight; i++)
    {
        gotoxy(screenWidth - 1, i);
        cout << c;
        Sleep(10); //10
    }

    c = 223;
    for (int i = screenWidth - 1; i >= 0; i--)
    {
        gotoxy(i, screenHeight);
        cout << c;
        Sleep(5); //5
    }

    c = 221;
    for (int i = screenHeight - 1; i > 0; i--)
    {
        gotoxy(0, i);
        cout << c;
        Sleep(10); //5
    }
    for (int i = 1; i < 14; i++)
    {
        TextColor(i);
        displayLogo(18, 8);
        Sleep(400);
    }
    TextColor(YELLOW);
    displayLogo(18, 8);
}

void loginScreen(vector <Player*>& list, int& playerPos)
{
    //outputInfoPlayerBin(list, "Player.bin");
    loadInfoPlayerBin(list, "Player.bin");
    int choice = 1;
    bool loop = true;
    while (loop)
    {
        displayMenuScreen();

        if (choice == 1)
            TextColor(YELLOW);
        displayBox(50, 21, 3, 20, "NEW PLAYER");
        TextColor(WHITE);

        if (choice == 2)
            TextColor(YELLOW);
        displayBox(50, 25, 3, 20, "RETURNING PLAYER");
        TextColor(WHITE);

        if (choice == 3)
            TextColor(YELLOW);
        displayBox(53, 29, 3, 14, "EXIT");
        TextColor(WHITE);

        int input = _getch();

        switch (input)
        {
        case KEY_UP:
            choice--;
            if (choice < 1)
                choice = 3;
            break;

        case KEY_DOWN:
            choice++;
            if (choice > 3)
                choice = 1;
            break;

        case KEY_ENTER: case SPACE_BAR:
            PlaySound(TEXT("SELECT.wav"), NULL, SND_ASYNC);

            deleteBox(50, 21, 3, 20);
            deleteBox(50, 25, 3, 20);
            deleteBox(53, 29, 3, 14);

            gotoxy(5, 20);
            displayPokeball(1, 17, RED);
            displayPokeball(11, 22, BLUE);
            displayPokeball(93, 17, BLUE);
            displayPokeball(83, 22, RED);

            bool flag = true;
            while (flag)
            {
                if (choice == 3)
                {
                    system("cls");
                    exit(0);
                }
                else
                {
                    gotoxy(48, 33);
                    cout << "Enter 'back' to get back";
                    displayBox(46, 21, 3, 28, "ENTER YOUR NAME (MAX 15)");
                    displayBox(46, 24, 3, 28, "");
                    gotoxy(48, 25);
                    ShowConsoleCursor(1);
                    string userName;
                    getline(cin, userName);

                    if (userName == "back")
                    {
                        system("cls");
                        flag = false;
                        break;
                    }


                    if (userName.length() > 15)
                    {
                        PlaySound(TEXT("MISTAKE.wav"), NULL, SND_ASYNC);
                        TextColor(RED);
                        deleteBox(48, 25, 1, 25);
                        gotoxy(53, 27);
                        cout << "Invalid name!";
                        ShowConsoleCursor(0);
                        Sleep(1000);
                        deleteBox(53, 27, 1, 15);
                        TextColor(WHITE);
                    }

                    else
                    {
                        if (choice == 1) //add new player
                        {
                            if (!checkAvailableUserName(list, userName)) //new player
                            {
                                PlaySound(TEXT("SELECT.wav"), NULL, SND_ASYNC);
                                addNewPlayerToList(list, userName);
                                playerPos = posPlayerInList(list, userName);
                                flag = false;
                                loop = false;
                                system("cls");
                            }
                            else
                            {
                                PlaySound(TEXT("MISTAKE.wav"), NULL, SND_ASYNC);
                                deleteBox(48, 25, 1, 25);
                                gotoxy(34, 27);
                                TextColor(LIGHT_RED);
                                cout << "This name already exists, please choose another name";
                                ShowConsoleCursor(0);
                                Sleep(1000);
                                deleteBox(34, 27, 1, 55);
                                TextColor(WHITE);
                            }
                        }

                        else if (choice == 2)
                        {
                            if (checkAvailableUserName(list, userName)) //exist player
                            {
                                PlaySound(TEXT("SELECT.wav"), NULL, SND_ASYNC);
                                playerPos = posPlayerInList(list, userName);
                                ShowConsoleCursor(0);
                                deleteBox(46, 21, 3, 28);
                                deleteBox(46, 24, 3, 28);
                                TextColor(YELLOW);
                                displayBox(46, 21, 6, 28, list[playerPos]->userName);
                                gotoxy(54, 23);
                                cout << "WELCOME BACK";
                                Sleep(2000);
                                TextColor(WHITE);

                                flag = false;
                                loop = false;
                                system("cls");
                            }
                            else
                            {
                                PlaySound(TEXT("MISTAKE.wav"), NULL, SND_ASYNC);
                                deleteBox(48, 25, 1, 25);
                                gotoxy(43, 27);
                                TextColor(LIGHT_RED);
                                cout << "Can not find your name, try again!";
                                ShowConsoleCursor(0);
                                Sleep(2000);
                                deleteBox(43, 27, 1, 40);
                                TextColor(WHITE);
                            }
                        }
                    }

                }
            }
            ShowConsoleCursor(0);

        }
    }
}

void helpScreen()
{
    gotoxy(40, 3);
    TextColor(YELLOW);
    cout << " __  __     ______     __         ______ "; gotoxy(40, 4);
    cout << "/\\ \\_\\ \\   /\\  ___\\   /\\ \\       /\\  == \\"; gotoxy(40, 5);
    cout << "\\ \\  __ \\  \\ \\  __\\   \\ \\ \\____  \\ \\  _-/ "; gotoxy(40, 6);
    cout << " \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\"; gotoxy(40, 7);
    cout << "  \\/_/\\/_/   \\/_____/   \\/_____/   \\/_/";
    TextColor(WHITE);

    displayBox(2, 10, 20, 38, "");
    gotoxy(19, 12);
    cout << "KEYS";
    gotoxy(5, 15);
    cout << "ARROW KEYS: MOVE BETWEEN POKEMONS";
    gotoxy(5, 17);
    cout << "SPACE: SELECT POKEMON";
    gotoxy(5, 19);
    cout << "F: SHUFFLE THE BOARD";
    gotoxy(5, 21);
    cout << "H: HINT (MOVE SUGGESTION)";
    gotoxy(5, 23);
    cout << "S: SAVE GAME";
    gotoxy(5, 25);
    cout << "ESC: QUIT GAME, BACK TO MENU";

    displayBox(41, 10, 20, 38, "");
    gotoxy(55, 12);
    cout << "GAME RULES";
    gotoxy(43, 15);
    cout << "  . YOUR OBJECTIVE IN THIS GAME ";
    gotoxy(43, 16);
    cout << "IS FINDING A PAIR OF POKEMON AND";
    gotoxy(43, 17);
    cout << "MATCHING THEM!";
    gotoxy(43, 19);
    cout << "  . TWO IDENTICAL POKEMONS ARE";
    gotoxy(43, 20);
    cout << "MATCHED BY I, U, L, Z LINE AND";
    gotoxy(43, 21);
    cout << "THERE MUST BE NO OBSTACLES BETWEEN";
    gotoxy(43, 22);
    cout << "THEM.";
    gotoxy(43, 24);
    cout << "  . YOU WILL WIN THE GAME WHEN";
    gotoxy(43, 25);
    cout << "THERE IS NO POKEMON LEFT.";

    displayBox(80, 10, 20, 38, "");
    gotoxy(96, 12);
    cout << "SCORES";
    gotoxy(90, 15);
    cout << "MATCHING I: 1 POINT";
    gotoxy(90, 17);
    cout << "MATCHING L: 3 POINT";
    gotoxy(90, 19);
    cout << "MATCHING U: 5 POINT";
    gotoxy(90, 21);
    cout << "MATCHING Z: 5 POINT";
    gotoxy(90, 23);
    cout << "SHUFFLE   : -3 POINT";
    gotoxy(90, 25);
    cout << "HINT      : -7 POINT";

    TextColor(YELLOW);
    displayBox(57, 31, 3, 8, "BACK");
    TextColor(WHITE);

RETURN:
    int input = _getch();

    if (input == SPACE_BAR || input == KEY_ESC || input == KEY_ENTER)
    {
        PlaySound(TEXT("SELECT.wav"), NULL, SND_ASYNC);
        system("cls");
        displayMenuScreen();
    }
    else
    {
        goto RETURN;
    }
}

void leaderboardScreen(vector <Player*> list)
{
    TextColor(YELLOW);
    gotoxy(3, 3);
    cout << ".____     ___________   _____  ________  _______________________________ ________      _____ __________________ "; gotoxy(3, 4);
    cout << "|    |    \\_   _____/  /  _  \\ \\______ \\ \\_   _____/\\______   \\______   \\\\_____  \\    /  _  \\\\______   \\______ \\"; gotoxy(3, 5);
    cout << "|    |     |    __)_  /  /_\\  \\ |    |  \\ |    __)_  |       _/|    |  _/ /   |   \\  /  /_\\  \\|       _/|    |  \\"; gotoxy(3, 6);
    cout << "|    |___  |        \\/    |    \\|    `   \\|        \\ |    |   \\|    |   \\/    |    \\/    |    \\    |   \\|    `   \\"; gotoxy(3, 7);
    cout << "|_______ \\/_______  /\\____|__  /_______  /_______  / |____|_  /|______  /\\_______  /\\____|__  /____|_  /_______  /"; gotoxy(3, 8);

    TextColor(YELLOW);
    displayBox(57, 31, 3, 8, "BACK");
    TextColor(WHITE);
    displayBox(5, 12, 17, 52, "");
    displayBox(63, 12, 17, 52, "");

    TextColor(YELLOW);
    gotoxy(29, 14);
    cout << "EASY";
    gotoxy(87, 14);
    cout << "HARD";
    gotoxy(14, 16);
    cout << "BEST TIME";
    gotoxy(40, 16);
    cout << "BEST POINT";
    gotoxy(72, 16);
    cout << "BEST TIME";
    gotoxy(98, 16);
    cout << "BEST POINT";
    TextColor(WHITE);

    sortPlayerPointEasy(list);
    sortPlayerPointHard(list);
    sortPlayerTimeEasy(list);
    sortPlayerTimeHard(list);

RETURN:
    int input = _getch();

    if (input == SPACE_BAR || input == KEY_ESC || input == KEY_ENTER)
    {
        PlaySound(TEXT("SELECT.wav"), NULL, SND_ASYNC);
        system("cls");
        displayMenuScreen();
    }
    else
    {
        goto RETURN;
    }
}

void customScreen(int& mode, Board& gameBoard)
{
    system("cls");
    displayScreen();
    TextColor(YELLOW);
    gotoxy(26, 3);
    cout << " ____       __  __      ____        ______    _____"; gotoxy(26, 4);
    cout << "/\\  _`\\    /\\ \\/\\ \\    /\\  _`\\     /\\__  _\\  /\\  __`\\     /'\\_/`\\"; gotoxy(26, 5);
    cout << "\\ \\ \\/\\_\\  \\ \\ \\ \\ \\   \\ \\,\\L\\_\\   \\/_/\\ \\/  \\ \\ \\/\\ \\   /\\      \\"; gotoxy(26, 6);
    cout << " \\ \\ \\/_/_  \\ \\ \\ \\ \\   \\/_\\__ \\      \\ \\ \\   \\ \\ \\ \\ \\  \\ \\ \\__\\ \\"; gotoxy(26, 7);
    cout << "  \\ \\ \\L\\ \\  \\ \\ \\_\\ \\    /\\ \\L\\ \\     \\ \\ \\   \\ \\ \\_\\ \\  \\ \\ \\_/\\ \\"; gotoxy(26, 8);
    cout << "   \\ \\____/   \\ \\_____\\   \\ `\\____\\     \\ \\_\\   \\ \\_____\\  \\ \\_\\\\ \\_\\"; gotoxy(26, 9);
    cout << "    \\/___/     \\/_____/    \\/_____/      \\/_/    \\/_____/   \\/_/ \\/_/";

    bool loop = true;
    //if (board[0][0])
    while (loop)
    {
        TextColor(WHITE);
        gotoxy(41, 18);
        cout << "COLUMN (MAX 8): ";
        ShowConsoleCursor(1);
        cin >> gameBoard.col;
        if (gameBoard.col > 8 || gameBoard.col < 1)
        {
            gotoxy(57, 18);
            TextColor(RED);
            cout << "Invalid number";
            ShowConsoleCursor(0);
            Sleep(300);
            deleteBox(57, 18, 1, 15);
        }
        else
        {
            ShowConsoleCursor(0);
            break;
        }
    }

    while (loop)
    {
        TextColor(WHITE);
        gotoxy(41, 22);
        cout << "ROW (MAX 6)   : ";
        ShowConsoleCursor(1);
        cin >> gameBoard.row;
        if (gameBoard.row < 1 || gameBoard.row > 6)
        {
            gotoxy(57, 22);
            TextColor(RED);
            cout << "Invalid number";
            ShowConsoleCursor(0);
            Sleep(300);
            deleteBox(57, 22, 1, 15);
        }
        else
        {
            ShowConsoleCursor(0);
            break;
        }
    }


    gotoxy(41, 26);
    cout << "MODE  :";
    int choice = 1;
    while (loop)
    {
        if (choice == 1)
            TextColor(YELLOW);
        gotoxy(52, 26);
        cout << "EASY";
        TextColor(WHITE);

        if (choice == 2)
            TextColor(YELLOW);
        gotoxy(59, 26);
        cout << "HARD";
        TextColor(WHITE);

        int input = _getch();

        switch (input)
        {
        case KEY_LEFT:

            choice--;
            if (choice < 1)
                choice = 2;
            break;

        case KEY_RIGHT:
            choice++;
            if (choice > 2)
                choice = 1;
            break;

        case KEY_ENTER: case SPACE_BAR:
            PlaySound(TEXT("SELECT.wav"), NULL, SND_ASYNC);
            switch (choice)
            {
            case 1:
                mode = 0;
                break;

            case 2:
                mode = 1;
                break;
            }
            gameBoard.width = gameBoard.col * 10;
            gameBoard.height = gameBoard.row * 5;
            loop = false;
            break;
        }

    }
}


