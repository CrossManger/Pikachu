#include "Header.h"

void createBoard(int**& board, Board gameBoard)
{
    board = new int* [gameBoard.row + 2];
    for (int i = 0; i < gameBoard.row + 2; i++)
    {
        board[i] = new int[gameBoard.col + 2];
        for (int j = 0; j < gameBoard.col + 2; j++)
        {
            board[i][j] = 0;
        }
    }
}

void createPoint(int**& board, Board gameBoard)
{
    if ((gameBoard.row * gameBoard.col) % 2 == 1) //use for custom mode
    {
        int x = rand() % gameBoard.row + 1;
        int y = rand() % gameBoard.col + 1;
        board[x][y] = 1;
    }

    for (int i = 1; i < gameBoard.row + 1; i++)
    {
        for (int j = 1; j < gameBoard.col + 1; j++)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = rand() % 15 + 65;
                int x = rand() % gameBoard.row + 1;
                int y = rand() % gameBoard.col + 1;
                while (board[x][y] != 0 || (i == x && j == y))
                {
                    x = rand() % gameBoard.row + 1;
                    y = rand() % gameBoard.col + 1;
                }
                board[x][y] = board[i][j];
            }
        }
    }
}

void deletePoint(int** board, Pokemon p1, Pokemon p2, int mode) // delete element if it can connect
{
    board[p1.i][p1.j] = 0;
    board[p2.i][p2.j] = 0;
    if (mode == 0) //EASY MODE
        return;

    //HARD MODE
    for (int i = p1.i; i >= 1; i--)
    {
        board[i][p1.j] = board[i - 1][p1.j];
    }
    if (p1.j == p2.j && p1.i > p2.i)
        p2.i++;
    for (int i = p2.i; i >= 1; i--)
    {
        board[i][p2.j] = board[i - 1][p2.j];
    }
}

bool samePoint(int** board, Pokemon p1, Pokemon p2)
{
    if (board[p1.i][p1.j] != board[p2.i][p2.j])
        return false;
    if (p1.i == p2.i && p1.j == p2.j)
        return false;
    return true;
}

bool matchingI(int** board, Pokemon p1, Pokemon p2)
{
    if (p1.i == p2.i)
    {
        if (p1.j > p2.j) swap(p1.j, p2.j);
        for (int j = p1.j + 1; j < p2.j; j++)
        {
            if (board[p1.i][j] != 0)
                return false;
        }
        return true;
    }
    if (p1.j == p2.j)
    {
        if (p1.i > p2.i) swap(p1.i, p2.i);
        for (int i = p1.i + 1; i < p2.i; i++)
        {
            if (board[i][p1.j] != 0)
                return false;
        }
        return true;
    }
    return false;
}

bool matchingL(int** board, Pokemon p1, Pokemon p2, Pokemon& corner)
{
    // 2 corner cells
    Pokemon temp1, temp2;
    temp1.i = p1.i, temp1.j = p2.j;
    temp2.i = p2.i, temp2.j = p1.j;
    if (board[temp1.i][temp1.j] != 0 && board[temp2.i][temp2.j] != 0) // new condition
        return false;
    // check matching I for two cases of L matching
    bool path_1_1 = matchingI(board, p1, temp1);
    bool path_1_2 = matchingI(board, p2, temp1);

    bool path_2_1 = matchingI(board, p1, temp2);
    bool path_2_2 = matchingI(board, p2, temp2);

    if (path_1_1 && path_1_2 && board[temp1.i][temp1.j] == 0)
    {
        corner = temp1;
        corner.x = 4 + (corner.j - 1) * 10;
        corner.y = 3 + (corner.i - 1) * 5;
        return true;
    }
    if (path_2_1 && path_2_2 && board[temp2.i][temp2.j] == 0)
    {
        corner = temp2;
        corner.x = 4 + (corner.j - 1) * 10;
        corner.y = 3 + (corner.i - 1) * 5;
        return true;
    }

    return false;
}

bool matchingUZ(int** board, Pokemon& p1, Pokemon& p2, Pokemon& corner1, Pokemon& corner2, Board gameBoard)
{
    //2 corners in the same row
    bool flag = false;
    int min = (gameBoard.row + 1) * 2;
    if (p1.i > p2.i)
        swap(p1, p2); //p1 higher than p2

    for (int i = p1.i + 1; i != p1.i; i++)
    {
        if (i > gameBoard.row + 1)
            i = 0;
        Pokemon temp1, temp2;
        temp1.i = i, temp1.j = p1.j;
        temp2.i = i, temp2.j = p2.j;
        if (board[temp1.i][temp1.j] == 0 && board[temp2.i][temp2.j] == 0)
        {
            bool path_1 = matchingI(board, p1, temp1);
            bool path_2 = matchingI(board, p2, temp2);
            bool path_3 = matchingI(board, temp1, temp2);

            if (path_1 && path_2 && path_3)
            {
                flag = true;
                if (abs(i - p1.i) + abs(i - p2.i) < min)
                {
                    min = abs(i - p1.i) + abs(i - p2.i);
                    corner1 = temp1;
                    corner1.x = 4 + (corner1.j - 1) * 10;
                    corner1.y = 3 + (corner1.i - 1) * 5;

                    corner2 = temp2;
                    corner2.x = 4 + (corner2.j - 1) * 10;
                    corner2.y = 3 + (corner2.i - 1) * 5;
                }
            }
        }
    }
    if (flag)
        return true;

    //(2 corners in the same column)
    flag = false;
    min = (gameBoard.col + 1) * 2;
    if (p1.j > p2.j)
        swap(p1, p2); //p1 on left side, p2 on right side

    for (int j = p1.j + 1; j != p1.j; j++)
    {
        if (j > gameBoard.col + 1)
            j = 0;
        Pokemon temp1, temp2;
        temp1.i = p1.i, temp1.j = j;
        temp2.i = p2.i, temp2.j = j;
        if (board[temp1.i][temp2.j] == 0 && board[temp2.i][temp2.j] == 0)
        {
            bool path_1 = matchingI(board, p1, temp1);
            bool path_2 = matchingI(board, p2, temp2);
            bool path_3 = matchingI(board, temp1, temp2);
            if (path_1 && path_2 && path_3)
            {
                flag = true;
                if (abs(j - p1.j) + abs(j - p2.j) < min)
                {
                    min = abs(j - p1.j) + abs(j - p2.j);
                    corner1 = temp1;
                    corner1.x = 4 + (corner1.j - 1) * 10;
                    corner1.y = 3 + (corner1.i - 1) * 5;

                    corner2 = temp2;
                    corner2.x = 4 + (corner2.j - 1) * 10;
                    corner2.y = 3 + (corner2.i - 1) * 5;
                }
            }
        }
    }
    if (flag)
        return true;
    return false;
}

bool checkMatching(int** board, Pokemon p1, Pokemon p2, int& point, Board gameBoard, bool display) //new function: adding point
{
    Pokemon corner;
    Pokemon corner1, corner2;
    bool same = samePoint(board, p1, p2);
    bool checkI = matchingI(board, p1, p2);
    bool checkL = matchingL(board, p1, p2, corner);
    bool checkUZ = matchingUZ(board, p1, p2, corner1, corner2, gameBoard);
    if (checkI && same)
    {
        point++;
        if (display)
        {
            PlaySound(TEXT("MATCHING.wav"), NULL, SND_ASYNC);
            Pokemon* ignore;
            displayMatchingLine(p1, p2, board, ignore, gameBoard, true);
        }
        return true;
    }
    else
    {
        if (checkL && same)
        {
            point += 3;
            if (display)
            {
                PlaySound(TEXT("MATCHING.wav"), NULL, SND_ASYNC);
                displayMatchingLineL(p1, p2, corner, board, gameBoard);
            }
            return true;
        }
        else if (checkUZ && same)
        {
            if (display)
            {
                PlaySound(TEXT("MATCHING.wav"), NULL, SND_ASYNC);
                matchingLineUZ(p1, p2, corner1, corner2, board, gameBoard);
            }

            point += 5;
            return true;
        }

        return false;
    }

    return false;
}

bool checkContinue(int** board, Pokemon& p1, Pokemon& p2, Board gameBoard) //new function: adding pokemon p1, p2 for move sugestion
{
    int ignore;
    for (int i = 1; i < gameBoard.row + 1; i++)
    {
        for (int j = 1; j < gameBoard.col + 1; j++)
        {
            if (board[i][j] != 0)
            {
                for (int k = 1; k < gameBoard.row + 1; k++)
                {
                    for (int l = 1; l < gameBoard.col + 1; l++)
                    {
                        if (board[i][j] == board[k][l] && (i != k || j != l))
                        {
                            p1.i = i;
                            p1.j = j;
                            p2.i = k;
                            p2.j = l;
                            if (checkMatching(board, p1, p2, ignore, gameBoard, false))
                                return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void shuffleBoard(int**& board, Board gameBoard)
{   
    int cnt = 0;
    while (cnt <= gameBoard.row * gameBoard.col - 1) {
        Pokemon p1, p2;
        p1.i = rand() % gameBoard.row + 1;
        p1.j = rand() % gameBoard.col + 1;
        p2.i = rand() % gameBoard.row + 1;
        p2.j = rand() % gameBoard.col + 1;
        while (board[p1.i][p1.j] == board[p2.i][p2.j] || board[p1.i][p1.j] == 0 || board[p2.i][p2.j] == 0 || (p1.i == p2.i && p1.j == p2.j))
        {
            p1.i = rand() % gameBoard.row + 1;
            p1.j = rand() % gameBoard.col + 1;
            p2.i = rand() % gameBoard.row + 1;
            p2.j = rand() % gameBoard.col + 1;
        }
        swap(board[p1.i][p1.j], board[p2.i][p2.j]);
        if (checkContinue(board, p1, p2, gameBoard) == false)
            shuffleBoard(board, gameBoard);
        else cnt += 2;
    }

}

void Gameplay(int**& board, int mode, Board& gameBoard, vector <Player*> list, int playerPos)
{
NEW_GAME:
    gameBoard.col = 8;
    gameBoard.row = 6;
    gameBoard.width = gameBoard.col * 10;
    gameBoard.height = gameBoard.row * 5;

    int pokemon;
    int count_space_bar, mistake, point;
    int i = 1, j = 1, x = 4, y = 3; //x, y is the corner

    if (mode == 0 && list[playerPos]->Easy->board != NULL)
    {
        int choice;
        displayContinueGame(choice);
        if (choice == 1)
        {
            createBoard(board, gameBoard);
            copyBoard(board, list[playerPos]->Easy->board, gameBoard);
            point = list[playerPos]->Easy->point;
            count_space_bar = list[playerPos]->Easy->move * 2;
            mistake = list[playerPos]->Easy->mistake;
            pokemon = list[playerPos]->Easy->pokemon;
            deleteBoard(list[playerPos]->Easy->board, gameBoard);
        }
        else
        {
            deleteBoard(list[playerPos]->Easy->board, gameBoard);
            goto NEW_GAME;
        }
    }
    else if (mode == 1 && list[playerPos]->Hard->board != NULL)
    {
        int choice;
        displayContinueGame(choice);
        if (choice == 1)
        {
            createBoard(board, gameBoard);
            copyBoard(board, list[playerPos]->Hard->board, gameBoard);
            point = list[playerPos]->Hard->point;
            count_space_bar = list[playerPos]->Hard->move * 2;
            mistake = list[playerPos]->Hard->mistake;
            pokemon = list[playerPos]->Hard->pokemon;
            deleteBoard(list[playerPos]->Hard->board, gameBoard);
        }
        else
        {
            deleteBoard(list[playerPos]->Hard->board, gameBoard);
            list[playerPos]->Hard->board = NULL;
            goto NEW_GAME;
        }
    }
    else
    {
        createBoard(board, gameBoard);
        createPoint(board, gameBoard);
        pokemon = gameBoard.col * gameBoard.row;
        count_space_bar = 0;
        point = 0;
        mistake = 0;
    }


    bool playloop = true;

    system("cls");
    displayScreen();
    displayPlayerInfo(list, playerPos);
    displayGameStatistic();
    displayGameInstruction();
    displayBackground_1(5, 4);
    displayBox(2, 2, gameBoard.height + 2, gameBoard.width + 4, "");
    displayGameBox(4, 3, gameBoard.height, gameBoard.width, board, gameBoard);

    Pokemon pokemon1, pokemon2;
    pokemon1.x = -1; pokemon1.y = -1; pokemon1.i = -1; pokemon1.j = -1;
    pokemon2.x = -1; pokemon2.y = -1; pokemon2.i = -1; pokemon2.j = -1;

    int time_;
    time_ = time(0);

    while (playloop)
    {
        TextColor(YELLOW);
        displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);

        if (point < 0) point = 0;
        updateGameStatistic(point, count_space_bar / 2, mistake);

        int input = _getch();

        if (input == KEY_UP)
        {
            TextColor(WHITE);
            if (board[i][j] != 0)
                displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);

            else
            {
                Pokemon temp;
                temp.i = i;
                temp.j = j;
                temp.x = x + (j - 1) * 10;
                temp.y = y + (i - 1) * 5;
                background_1_upgrade(temp);
            }
            i--;
            if (i < 1)
                i = 6;
            if (i == pokemon1.i && j == pokemon1.j)
                i--;
            if (i < 1)
                i = 6;
        }

        else if (input == KEY_DOWN)
        {
            TextColor(WHITE);
            if (board[i][j] != 0)
                displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);

            else
            {
                Pokemon temp;
                temp.i = i;
                temp.j = j;
                temp.x = x + (j - 1) * 10;
                temp.y = y + (i - 1) * 5;
                background_1_upgrade(temp);
            }

            i++;
            if (i > 6)
                i = 1;
            if (i == pokemon1.i && j == pokemon1.j)
                i++;
            if (i > 6)
                i = 1;
        }

        else if (input == KEY_LEFT)
        {
            TextColor(WHITE);
            if (board[i][j] != 0)
                displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);

            else
            {
                Pokemon temp;
                temp.i = i;
                temp.j = j;
                temp.x = x + (j - 1) * 10;
                temp.y = y + (i - 1) * 5;
                background_1_upgrade(temp);
            }

            j--;
            if (j < 1)
                j = 8;
            if (i == pokemon1.i && j == pokemon1.j)
                j--;
            if (j < 1)
                j = 8;
        }

        else if (input == KEY_RIGHT)
        {
            TextColor(WHITE);
            if (board[i][j] != 0)
                displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);

            else
            {
                Pokemon temp;
                temp.i = i;
                temp.j = j;
                temp.x = x + (j - 1) * 10;
                temp.y = y + (i - 1) * 5;
                background_1_upgrade(temp);
            }

            j++;
            if (j > 8)
                j = 1;
            if (i == pokemon1.i && j == pokemon1.j)
                j++;
            if (j > 8)
                j = 1;
        }

        else if (input == SPACE_BAR && board[i][j] != 0)
        {
            count_space_bar++;
            if (count_space_bar % 2 == 1) //choose first pokemon
            {
                PlaySound(TEXT("SELECT.wav"), NULL, SND_ASYNC);

                pokemon1.x = x + (j - 1) * 10; //coordinate of the chosen pokemon on visible board
                pokemon1.y = y + (i - 1) * 5;

                pokemon1.i = i; // index of the chosen pokemon on virtual board
                pokemon1.j = j;

                TextColor(AQUA);
                displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);

                input = _getch();
                if (input == SPACE_BAR) //deselect
                {
                    TextColor(YELLOW);
                    displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);

                    pokemon1.i = -1;
                    pokemon1.j = -1;

                    count_space_bar--;
                }

                input = _getch(); //dont know why but _getch() 2 times will keep the blue box on screen

                if (input == KEY_UP)
                {
                    if (board[i][j] == 0)
                    {
                        Pokemon temp;
                        temp.i = i;
                        temp.j = j;
                        temp.x = x + (j - 1) * 10;
                        temp.y = y + (i - 1) * 5;
                        background_1_upgrade(temp);
                    }

                    i--;
                    if (i < 1) i = 6;
                }

                else if (input == KEY_DOWN)
                {
                    if (board[i][j] == 0)
                    {
                        Pokemon temp;
                        temp.i = i;
                        temp.j = j;
                        temp.x = x + (j - 1) * 10;
                        temp.y = y + (i - 1) * 5;
                        background_1_upgrade(temp);
                    }

                    i++;
                    if (i > 6) i = 1;
                }

                else if (input == KEY_LEFT)
                {
                    if (board[i][j] == 0)
                    {
                        Pokemon temp;
                        temp.i = i;
                        temp.j = j;
                        temp.x = x + (j - 1) * 10;
                        temp.y = y + (i - 1) * 5;
                        background_1_upgrade(temp);
                    }

                    j--;
                    if (j < 1) j = 8;
                }

                else if (input == KEY_RIGHT)
                {
                    if (board[i][j] == 0)
                    {
                        Pokemon temp;
                        temp.i = i;
                        temp.j = j;
                        temp.x = x + (j - 1) * 10;
                        temp.y = y + (i - 1) * 5;
                        background_1_upgrade(temp);
                    }

                    j++;
                    if (j > 8) j = 1;
                }
            }

            else //choose second pokemon
            {
                pokemon2.x = x + (j - 1) * 10; //coordinate of the chosen pokemon on visible board
                pokemon2.y = y + (i - 1) * 5;

                pokemon2.i = i; // coordinate of the chosen pokemon on virtual board
                pokemon2.j = j;

                TextColor(AQUA);
                displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);

                TextColor(WHITE);
                displayBoxChar(pokemon1.x, pokemon1.y, 5, 10, (char)board[pokemon1.i][pokemon1.j]);

                if (checkMatching(board, pokemon1, pokemon2, point, gameBoard, true)) // kiem tra matching va display
                {
                    if (mode == 0) //Easy mode
                    {
                        deletePoint(board, pokemon1, pokemon2, mode); // dung thi xoa point                
                        deleteBox(pokemon1.x, pokemon1.y, 5, 10);
                        deleteBox(pokemon2.x, pokemon2.y, 5, 10);
                        background_1_upgrade(pokemon1);
                        background_1_upgrade(pokemon2);
                    }
                    else if (mode == 1) //Hard mode
                    {
                        deletePoint(board, pokemon1, pokemon2, mode);
                        for (int i = 1, temp_y = 3; i < gameBoard.row + 1; i++, temp_y += 5)
                        {
                            if (board[i][pokemon1.j] != 0)
                            {
                                displayBoxChar(pokemon1.x, temp_y, 5, 10, board[i][pokemon1.j]);
                            }
                            else
                            {
                                Pokemon temp;
                                temp.i = i;
                                temp.j = pokemon1.j;
                                temp.x = 4 + (temp.j - 1) * 10;
                                temp.y = 3 + (temp.i - 1) * 5;
                                background_1_upgrade(temp);
                            }
                        }

                        if (pokemon1.j != pokemon2.j)
                        {
                            for (int i = 1, temp_y = 3; i < gameBoard.row + 1; i++, temp_y += 5)
                            {
                                if (board[i][pokemon2.j] != 0)
                                {
                                    displayBoxChar(pokemon2.x, temp_y, 5, 10, board[i][pokemon2.j]);
                                }
                                else
                                {
                                    Pokemon temp;
                                    temp.i = i;
                                    temp.j = pokemon2.j;
                                    temp.x = 4 + (temp.j - 1) * 10;
                                    temp.y = 3 + (temp.i - 1) * 5;
                                    background_1_upgrade(temp);
                                }
                            }
                        }
                    }

                    pokemon -= 2;

                    if (pokemon == 0) //END GAME
                    {
                        updateGameStatistic(point, count_space_bar / 2, mistake);
                        int choice;


                        if (mode == 0)
                        {
                            list[playerPos]->Easy->matches++;
                            list[playerPos]->Easy->board = NULL;

                            if (list[playerPos]->Easy->bestPoint < point)
                                list[playerPos]->Easy->bestPoint = point;

                            time_ = list[playerPos]->Easy->time + (time(0) - time_);

                            if (list[playerPos]->Easy->bestTime > time_ || list[playerPos]->Easy->bestTime == 0)
                                list[playerPos]->Easy->bestTime = time_;
                        }
                        else if (mode == 1)
                        {
                            list[playerPos]->Hard->matches++;
                            list[playerPos]->Hard->board = NULL;

                            if (list[playerPos]->Hard->bestPoint < point)
                                list[playerPos]->Hard->bestPoint = point;

                            time_ = list[playerPos]->Hard->time + (time(0) - time_);

                            if (list[playerPos]->Hard->bestTime > time_ || list[playerPos]->Hard->bestTime == 0)
                                list[playerPos]->Hard->bestTime = time_;
                        }

                        displayWinGame(time_, choice);
                        if (choice == 1)
                        {
                            deleteBoard(board, gameBoard);
                            goto NEW_GAME;
                        }
                        else
                            playloop = false;
                    }

                    Pokemon ignore1, ignore2;
                    if ((!checkContinue(board, ignore1, ignore2, gameBoard)) && pokemon != 0) //check continue after matching 2 points
                    {
                        shuffleBoard(board, gameBoard);
                        displayGameBox(4, 3, gameBoard.height, gameBoard.width, board, gameBoard);
                        deleteBox(87, 23, 11, 31);
                        TextColor(YELLOW);
                        displayBox(87, 23, 11, 31, "Out of moves, let's shufffle!");
                        Sleep(2000);
                        deleteBox(87, 23, 11, 31);
                        displayGameInstruction();
                    }
                }
                else
                {
                    PlaySound(TEXT("MISTAKE.wav"), NULL, SND_ASYNC);
                    mistake++;
                }

                pokemon1.i = -1; pokemon1.j = -1;
            }
        }

        else if (input == KEY_F)
        {
            shuffleBoard(board, gameBoard);
            TextColor(WHITE);
            displayGameBox(4, 3, gameBoard.height, gameBoard.width, board, gameBoard);
            deleteBox(87, 23, 11, 31);
            TextColor(YELLOW);
            displayBox(87, 23, 11, 31, "Let's shufffle!");
            Sleep(2000);
            point -= 3;
            deleteBox(87, 23, 11, 31);
            displayGameInstruction();
        }

        else if (input == KEY_H) //HINT
        {
            Pokemon temp1, temp2;

            checkContinue(board, temp1, temp2, gameBoard);
            temp1.x = 4 + (temp1.j - 1) * 10;
            temp1.y = 3 + (temp1.i - 1) * 5;
            temp2.x = 4 + (temp2.j - 1) * 10;
            temp2.y = 3 + (temp2.i - 1) * 5;

            for (int i = 0; i < 3; i++)
            {
                TextColor(LIGHT_GREEN);
                displayBoxChar(temp1.x, temp1.y, 5, 10, board[temp1.i][temp1.j]);
                displayBoxChar(temp2.x, temp2.y, 5, 10, board[temp2.i][temp2.j]);
                Sleep(500);
                TextColor(WHITE);
                displayBoxChar(temp1.x, temp1.y, 5, 10, board[temp1.i][temp1.j]);
                displayBoxChar(temp2.x, temp2.y, 5, 10, board[temp2.i][temp2.j]);
                Sleep(500);
            }
            point -= 7;
        }

        else if (input == KEY_S)
        {
            if (mode == 0)
            {
                createBoard(list[playerPos]->Easy->board, gameBoard);
                copyBoardEasy(list, playerPos, board, gameBoard);
                list[playerPos]->Easy->point = point;
                list[playerPos]->Easy->move = count_space_bar / 2;
                list[playerPos]->Easy->mistake = mistake;
                list[playerPos]->Easy->pokemon = pokemon;
                list[playerPos]->Easy->time += (time(0) - time_);
            }

            else if (mode == 1)
            {
                createBoard(list[playerPos]->Hard->board, gameBoard);
                copyBoardHard(list, playerPos, board, gameBoard);
                list[playerPos]->Hard->point = point;
                list[playerPos]->Hard->move = count_space_bar / 2;
                list[playerPos]->Hard->mistake = mistake;
                list[playerPos]->Hard->pokemon = pokemon;
                list[playerPos]->Hard->time += (time(0) - time_);
            }
            deleteBox(87, 23, 11, 31);
            TextColor(YELLOW);
            displayBox(87, 23, 11, 31, "Game Saved!!");
            Sleep(1000);
            deleteBox(87, 23, 11, 31);
            displayGameInstruction();
        }

        else if (input == KEY_ESC)
        {
            int choice;
            displayConfirmQuit(choice);
            if (choice == 1)
            {
                if (mode == 0)
                {
                    createBoard(list[playerPos]->Easy->board, gameBoard);
                    copyBoardEasy(list, playerPos, board, gameBoard);
                    list[playerPos]->Easy->point = point;
                    list[playerPos]->Easy->move = count_space_bar / 2;
                    list[playerPos]->Easy->mistake = mistake;
                    list[playerPos]->Easy->pokemon = pokemon;
                    list[playerPos]->Easy->time += (time(0) - time_);
                }

                else if (mode == 1)
                {
                    createBoard(list[playerPos]->Hard->board, gameBoard);
                    copyBoardHard(list, playerPos, board, gameBoard);
                    list[playerPos]->Hard->point = point;
                    list[playerPos]->Hard->move = count_space_bar / 2;
                    list[playerPos]->Hard->mistake = mistake;
                    list[playerPos]->Hard->pokemon = pokemon;
                    list[playerPos]->Hard->time += (time(0) - time_);
                }
            }

            playloop = false;
        }
    }
}

void GameplayCustom(int**& board, int mode, Board& gameBoard, vector <Player*> list, int playerPos, bool& hackFile)
{
NEW_GAME:

    system("cls");
    if (!hackFile) //hack file board not exist
    {
        createBoard(board, gameBoard);
        createPoint(board, gameBoard);
    }
    else
        hackFile = false;

    displayScreen();
    displayPlayerInfo(list, playerPos);
    displayGameStatistic();
    displayGameInstruction();
    displayBox(2, 2, gameBoard.height + 2, gameBoard.width + 4, "");
    displayGameBox(4, 3, gameBoard.height, gameBoard.width, board, gameBoard);

    int pokemon;
    int count_space_bar, mistake, point;
    int i = 1, j = 1, x = 4, y = 3; //x, y is the corner
    pokemon = gameBoard.col * gameBoard.row;
    count_space_bar = 0;
    point = 0;
    mistake = 0;
    bool playloop = true;

    Pokemon pokemon1, pokemon2;
    pokemon1.x = -1; pokemon1.y = -1; pokemon1.i = -1; pokemon1.j = -1;
    pokemon2.x = -1; pokemon2.y = -1; pokemon2.i = -1; pokemon2.j = -1;

    int time_;
    time_ = time(0);

    while (playloop)
    {
        TextColor(YELLOW);
        displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);
        if (board[i][j] == 1)
            displayBox(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, "BLOCK");

        if (point < 0) point = 0;
        updateGameStatistic(point, count_space_bar / 2, mistake);

        int input = _getch();

        if (input == KEY_UP)
        {
            TextColor(WHITE);
            if (board[i][j] != 0)
                displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);
            else
            {
                Pokemon temp;
                temp.i = i;
                temp.j = j;
                temp.x = x + (j - 1) * 10;
                temp.y = y + (i - 1) * 5;
                displayBackground_2(temp);
            }

            if (board[i][j] == 1)
                displayBox(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, "BLOCK");

            i--;
            if (i < 1)
                i = gameBoard.row;
            if (i == pokemon1.i && j == pokemon1.j)
                i--;
            if (i < 1)
                i = gameBoard.row;
        }

        else if (input == KEY_DOWN)
        {
            TextColor(WHITE);
            if (board[i][j] != 0)
                displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);
            else
            {
                Pokemon temp;
                temp.i = i;
                temp.j = j;
                temp.x = x + (j - 1) * 10;
                temp.y = y + (i - 1) * 5;
                displayBackground_2(temp);
            }

            if (board[i][j] == 1)
                displayBox(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, "BLOCK");

            i++;
            if (i > gameBoard.row)
                i = 1;
            if (i == pokemon1.i && j == pokemon1.j)
                i++;
            if (i > gameBoard.row)
                i = 1;
        }

        else if (input == KEY_LEFT)
        {
            TextColor(WHITE);
            if (board[i][j] != 0)
                displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);
            else
            {
                Pokemon temp;
                temp.i = i;
                temp.j = j;
                temp.x = x + (j - 1) * 10;
                temp.y = y + (i - 1) * 5;
                displayBackground_2(temp);
            }

            if (board[i][j] == 1)
                displayBox(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, "BLOCK");

            j--;
            if (j < 1)
                j = gameBoard.col;
            if (i == pokemon1.i && j == pokemon1.j)
                j--;
            if (j < 1)
                j = gameBoard.col;
        }

        else if (input == KEY_RIGHT)
        {
            TextColor(WHITE);
            if (board[i][j] != 0)
                displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);
            else
            {
                Pokemon temp;
                temp.i = i;
                temp.j = j;
                temp.x = x + (j - 1) * 10;
                temp.y = y + (i - 1) * 5;
                displayBackground_2(temp);
            }

            if (board[i][j] == 1)
                displayBox(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, "BLOCK");

            j++;
            if (j > gameBoard.col)
                j = 1;
            if (i == pokemon1.i && j == pokemon1.j)
                j++;
            if (j > gameBoard.col)
                j = 1;
        }

        else if (input == SPACE_BAR && board[i][j] != 0)
        {
            count_space_bar++;
            if (count_space_bar % 2 == 1) //choose first pokemon
            {
                PlaySound(TEXT("SELECT.wav"), NULL, SND_ASYNC);

                pokemon1.x = x + (j - 1) * 10; //coordinate of the chosen pokemon on visible board
                pokemon1.y = y + (i - 1) * 5;

                pokemon1.i = i; // index of the chosen pokemon on virtual board
                pokemon1.j = j;

                TextColor(AQUA);
                displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);
                if (board[i][j] == 1)
                    displayBox(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, "BLOCK");

                input = _getch();
                if (input == SPACE_BAR) //deselect
                {
                    TextColor(YELLOW);
                    displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);
                    if (board[i][j] == 1)
                        displayBox(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, "BLOCK");

                    pokemon1.i = -1;
                    pokemon1.j = -1;

                    count_space_bar--;
                }

                input = _getch(); //dont know why but _getch() 2 times will keep the blue box on screen

                if (input == KEY_UP)
                {
                    i--;
                    if (i < 1) i = gameBoard.row;
                }

                else if (input == KEY_DOWN)
                {
                    i++;
                    if (i > gameBoard.row) i = 1;
                }

                else if (input == KEY_LEFT)
                {
                    j--;
                    if (j < 1) j = gameBoard.col;
                }

                else if (input == KEY_RIGHT)
                {
                    j++;
                    if (j > gameBoard.col) j = 1;
                }
            }

            else //choose second pokemon
            {
                pokemon2.x = x + (j - 1) * 10; //coordinate of the chosen pokemon on visible board
                pokemon2.y = y + (i - 1) * 5;

                pokemon2.i = i; // coordinate of the chosen pokemon on virtual board
                pokemon2.j = j;

                TextColor(AQUA);
                displayBoxChar(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, (char)board[i][j]);
                if (board[i][j] == 1)
                    displayBox(x + (j - 1) * 10, y + (i - 1) * 5, 5, 10, "BLOCK");

                TextColor(WHITE);
                displayBoxChar(pokemon1.x, pokemon1.y, 5, 10, (char)board[pokemon1.i][pokemon1.j]);
                if (board[pokemon1.i][pokemon1.j] == 1)
                    displayBox(pokemon1.x, pokemon1.y, 5, 10, "BLOCK");

                if (checkMatching(board, pokemon1, pokemon2, point, gameBoard, true)) // kiem tra matching
                {
                    if (mode == 0) //Easy mode
                    {
                        deletePoint(board, pokemon1, pokemon2, mode); // dung thi xoa point                
                        displayBackground_2(pokemon1);
                        displayBackground_2(pokemon2);
                    }
                    else if (mode == 1) //Hard mode
                    {
                        deletePoint(board, pokemon1, pokemon2, mode);
                        for (int i = 1, temp_y = 3; i < gameBoard.row + 1; i++, temp_y += 5)
                        {
                            if (board[i][pokemon1.j] != 0)
                                displayBoxChar(pokemon1.x, temp_y, 5, 10, board[i][pokemon1.j]);
                            else
                            {
                                Pokemon temp;
                                temp.i = i;
                                temp.j = pokemon1.j;
                                temp.x = x + (temp.j - 1) * 10;
                                temp.y = y + (temp.i - 1) * 5;
                                displayBackground_2(temp);
                            }

                            if (board[i][pokemon1.j] == 1)
                                displayBox(pokemon1.x, temp_y, 5, 10, "BLOCK");

                        }

                        if (pokemon1.j != pokemon2.j)
                        {
                            for (int i = 1, temp_y = 3; i < gameBoard.row + 1; i++, temp_y += 5)
                            {
                                if (board[i][pokemon2.j] != 0)
                                    displayBoxChar(pokemon2.x, temp_y, 5, 10, board[i][pokemon2.j]);
                                else
                                {
                                    Pokemon temp;
                                    temp.i = i;
                                    temp.j = pokemon2.j;
                                    temp.x = x + (temp.j - 1) * 10;
                                    temp.y = y + (temp.i - 1) * 5;
                                    displayBackground_2(temp);
                                }

                                if (board[i][pokemon2.j] == 1)
                                    displayBox(pokemon2.x, temp_y, 5, 10, "BLOCK");

                            }
                        }
                    }

                    pokemon -= 2;

                    if (pokemon == 0 || pokemon == 1) //END GAME
                    {
                        updateGameStatistic(point, count_space_bar / 2, mistake);
                        int choice;
                        time_ = time(0) - time_;
                        displayWinGame(time_, choice);
                        if (choice == 1)
                        {
                            deleteBoard(board, gameBoard);
                            goto NEW_GAME;
                        }
                        else
                        {
                            playloop = false;
                            break;
                        }
                    }

                    Pokemon ignore1, ignore2;
                    if ((!checkContinue(board, ignore1, ignore2, gameBoard)) && pokemon != 0) //check continue after matching 2 points
                    {
                        shuffleBoard(board, gameBoard);
                        displayGameBox(4, 3, gameBoard.height, gameBoard.width, board, gameBoard);
                        deleteBox(87, 23, 11, 31);
                        TextColor(YELLOW);
                        displayBox(87, 23, 11, 31, "Out of moves, let's shufffle!");
                        Sleep(2000);
                        deleteBox(87, 23, 11, 31);
                        displayGameInstruction();
                    }
                }
                else
                {
                    PlaySound(TEXT("MISTAKE.wav"), NULL, SND_ASYNC);
                    mistake++;
                }

                pokemon1.i = -1; pokemon1.j = -1;
            }
        }

        else if (input == KEY_F)
        {
            shuffleBoard(board, gameBoard);
            TextColor(WHITE);
            displayGameBox(4, 3, gameBoard.height, gameBoard.width, board, gameBoard);
            deleteBox(87, 23, 11, 31);
            TextColor(YELLOW);
            displayBox(87, 23, 11, 31, "Let's shufffle!");
            Sleep(2000);
            point -= 3;
            deleteBox(87, 23, 11, 31);
            displayGameInstruction();
        }

        else if (input == KEY_H) //HINT
        {
            Pokemon temp1, temp2;
            checkContinue(board, temp1, temp2, gameBoard);
            temp1.x = 4 + (temp1.j - 1) * 10;
            temp1.y = 3 + (temp1.i - 1) * 5;
            temp2.x = 4 + (temp2.j - 1) * 10;
            temp2.y = 3 + (temp2.i - 1) * 5;

            for (int i = 0; i < 3; i++)
            {
                TextColor(LIGHT_GREEN);
                displayBoxChar(temp1.x, temp1.y, 5, 10, board[temp1.i][temp1.j]);
                displayBoxChar(temp2.x, temp2.y, 5, 10, board[temp2.i][temp2.j]);
                Sleep(500);
                TextColor(WHITE);
                displayBoxChar(temp1.x, temp1.y, 5, 10, board[temp1.i][temp1.j]);
                displayBoxChar(temp2.x, temp2.y, 5, 10, board[temp2.i][temp2.j]);
                Sleep(500);
            }
            point -= 7;
        }

        else if (input == KEY_S)
        {
            deleteBox(87, 23, 11, 31);
            TextColor(YELLOW);
            displayBox(87, 23, 11, 31, "Custom can't save game!");
            Sleep(1000);
            deleteBox(87, 23, 11, 31);
            displayGameInstruction();
        }

        else if (input == KEY_ESC)
        {
            deleteBox(87, 23, 11, 31);
            TextColor(YELLOW);
            displayBox(87, 23, 11, 31, "LEAVING GAME..");
            Sleep(1000);
            playloop = false;
        }
    }
}

void deleteBoard(int**& board, Board gameBoard) // xoa mang khi da choi xong
{
    for (int i = 0; i < gameBoard.row + 2; i++)
    {
        delete[] board[i];
    }
    delete[] board;
    board = NULL;
}
