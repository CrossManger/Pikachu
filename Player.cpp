#include "Header.h"

bool checkAvailableUserName(vector <Player*> list, string userName)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i]->userName == userName)
        {
            return true;
        }
    }
    return false;
}

void addNewPlayerToList(vector <Player*>& list, string userName)
{
    Player* newPlayer = new Player;
    strcpy(newPlayer->userName, userName.c_str());
    newPlayer->Easy = new InforMatches;
    newPlayer->Hard = new InforMatches;

    // tao xong chi can dung len "push_back" de add vo
    list.push_back(newPlayer);
}

int posPlayerInList(vector <Player*>& list, string userName)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i]->userName == userName)
            return i;
    }
    return 0;
}

void copyBoardEasy(vector <Player*> list, int pos, int** board, Board gameBoard)
{
    for (int i = 0; i < gameBoard.row + 2; i++)
    {
        for (int j = 0; j < gameBoard.col + 2; j++)
        {
            list[pos]->Easy->board[i][j] = board[i][j];
        }
    }
}

void copyBoardHard(vector <Player*> list, int pos, int** board, Board gameBoard)
{
    for (int i = 0; i < gameBoard.row + 2; i++)
    {
        for (int j = 0; j < gameBoard.col + 2; j++)
        {
            list[pos]->Hard->board[i][j] = board[i][j];
        }
    }
}

void copyBoard(int** mainBoard, int** board, Board gameBoard)
{
    for (int i = 0; i < gameBoard.row + 2; i++)
    {
        for (int j = 0; j < gameBoard.col + 2; j++)
        {
            mainBoard[i][j] = board[i][j];
        }
    }
}

void outputInfoPlayerBin(vector <Player*> list, string nameFile)
{
    ofstream outFile(nameFile, ios::binary);
    for (int i = 0; i < list.size(); i++)
    {
        outFile.write((char*)&list[i]->userName, 20);

        outFile.write((char*)&list[i]->Easy->bestPoint, 4);
        outFile.write((char*)&list[i]->Easy->bestTime, 4);
        outFile.write((char*)&list[i]->Easy->matches, 4);

        outFile.write((char*)&list[i]->Hard->bestPoint, 4);
        outFile.write((char*)&list[i]->Hard->bestTime, 4);
        outFile.write((char*)&list[i]->Hard->matches, 4);
    }
    outFile.close();
}

void loadInfoPlayerBin(vector <Player*>& list, string nameFile)
{
    ifstream inFile(nameFile, ios::binary);
    while (!inFile.eof())
    {
        Player* newPlayer = new Player;
        newPlayer->Easy = new InforMatches;
        newPlayer->Hard = new InforMatches;

        inFile.read((char*)&newPlayer->userName, 20);
        inFile.read((char*)&newPlayer->Easy->bestPoint, 4);
        inFile.read((char*)&newPlayer->Easy->bestTime, 4);
        inFile.read((char*)&newPlayer->Easy->matches, 4);

        inFile.read((char*)&newPlayer->Hard->bestPoint, 4);
        inFile.read((char*)&newPlayer->Hard->bestTime, 4);
        inFile.read((char*)&newPlayer->Hard->matches, 4);

        if (!inFile.eof())
            list.push_back(newPlayer);
    }
    inFile.close();
}

void sortPlayerPointEasy(vector <Player*> list)
{
    for (int i = 0; i < list.size() - 1; i++)
    {
        for (int j = i + 1; j < list.size(); j++)
        {
            if (list[i]->Easy->bestPoint < list[j]->Easy->bestPoint)
                swap(list[i], list[j]);
        }
    }
    for (int i = 0; i < 5 && i < list.size(); i++)
    {
        if (list[i]->Easy->bestPoint == 0)
            break;
        gotoxy(34, 18 + i * 2);
        cout << i + 1 << ". " << list[i]->userName;
        gotoxy(52, 18 + i * 2);
        cout << list[i]->Easy->bestPoint;
    }
}

void sortPlayerPointHard(vector <Player*> list)
{
    for (int i = 0; i < list.size() - 1; i++)
    {
        for (int j = i + 1; j < list.size(); j++)
        {
            if (list[i]->Hard->bestPoint < list[j]->Hard->bestPoint)
                swap(list[i], list[j]);
        }
    }
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i]->Hard->bestPoint == 0)
            break;
        gotoxy(92, 18 + i * 2);
        cout << i + 1 << ". " << list[i]->userName;
        gotoxy(110, 18 + i * 2);
        cout << list[i]->Hard->bestPoint;
    }
}

void sortPlayerTimeEasy(vector <Player*> list)
{
    int skip = 0;
    for (int i = 0; i < list.size() - 1; i++)
    {
        for (int j = i; j < list.size(); j++)
        {
            if (list[j]->Easy->bestTime == 0 && i == 0) // count value 0 in first loop
                skip++;
            if (list[i]->Easy->bestTime > list[j]->Easy->bestTime)
                swap(list[i], list[j]);
        }
    }
    // after sort, the players have time = 0 are at top of the list, for ex: 0 0 0 57 80 98
    // we just cout from the position 4, skip the 0 value, start at index 3 

    for (int i = skip; i < skip + 5 && i < list.size(); i++)
    {
        gotoxy(8, 18 + (i - skip) * 2);
        cout << i - skip + 1 << ". " << list[i]->userName;
        gotoxy(26, 18 + (i - skip) * 2);
        cout << list[i]->Easy->bestTime << "s";
    }
}

void sortPlayerTimeHard(vector <Player*> list)
{
    int skip = 0;
    for (int i = 0; i < list.size() - 1; i++)
    {
        for (int j = i; j < list.size(); j++)
        {
            if (list[j]->Hard->bestTime == 0 && i == 0)
                skip++;
            if (list[i]->Hard->bestTime > list[j]->Hard->bestTime)
                swap(list[i], list[j]);
        }
    }
    // after sort, the players have time = 0 are at top of the list, for ex: 0 0 0 57 80 98
    // we just cout from the position 4, skip the 0 value, start at index 3 

    for (int i = skip; i < skip + 5 && i < list.size(); i++)
    {
        gotoxy(66, 18 + (i - skip) * 2);
        cout << i - skip + 1 << ". " << list[i]->userName;
        gotoxy(84, 18 + (i - skip) * 2);
        cout << list[i]->Hard->bestTime << "s";
    }
}