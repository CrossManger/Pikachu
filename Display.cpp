#include "Header.h"

void displayBox(int x, int y, int boxHeight, int boxWidth, string s) //input the corner coordinate of the box and box's size
{
	char c;
	c = 205;
	for (int i = 0; i < boxWidth; i++) //box's width
	{
		gotoxy(x + i, y);
		cout << c;
		gotoxy(x + i, y + boxHeight - 1);
		cout << c;
	}


	c = 186;
	for (int i = 0; i < boxHeight; i++)
	{
		gotoxy(x + boxWidth - 1, y + i);
		cout << c;
		gotoxy(x, y + i);
		cout << c;
	}

	c = 188;
	gotoxy(x + boxWidth - 1, y + boxHeight - 1);
	cout << c;

	c = 201;
	gotoxy(x, y);
	cout << c;

	c = 187;
	gotoxy(x + boxWidth - 1, y);
	cout << c;

	c = 200;
	gotoxy(x, y + boxHeight - 1);
	cout << c;

	gotoxy(x + (boxWidth - s.length()) / 2, y + boxHeight / 2);
	cout << s;
}

void displayScreen()
{
	char c = 220;
	for (int i = 0; i < screenWidth; i++)
	{
		gotoxy(i, 0);
		cout << c;
	}

	c = 222;
	for (int i = 1; i < screenHeight; i++)
	{
		gotoxy(screenWidth - 1, i);
		cout << c;
	}

	c = 223;
	for (int i = screenWidth - 1; i >= 0; i--)
	{
		gotoxy(i, screenHeight);
		cout << c;
	}

	c = 221;
	for (int i = screenHeight - 1; i > 0; i--)
	{
		gotoxy(0, i);
		cout << c;
	}
}

void displayLogo(int x, int y)
{
	gotoxy(x, y);
	cout << "  ______     __       __  __       ______       ______       __  __       __  __  "; gotoxy(x, ++y);
	cout << " /\\  == \\   /\\ \\     /\\ \\/ /      /\\  __ \\     /\\  ___\\     /\\ \\_\\ \\     /\\ \\/\\ \\ "; gotoxy(x, ++y);
	cout << " \\ \\  _-/   \\ \\ \\    \\ \\  _'-.    \\ \\  __ \\    \\ \\ \\____    \\ \\  __ \\    \\ \\ \\_\\ \\ "; gotoxy(x, ++y);
	cout << "  \\ \\_\\      \\ \\_\\    \\ \\_\\ \\_\\    \\ \\_\\ \\_\\    \\ \\_____\\    \\ \\_\\ \\_\\    \\ \\_____\\ "; gotoxy(x, ++y);
	cout << "   \\/_/       \\/_/     \\/_/\\/_/     \\/_/\\/_/     \\/_____/     \\/_/\\/_/     \\/_____/"; gotoxy(x, ++y);

}

void displayMenuScreen()
{
	TextColor(WHITE);
	displayScreen();
	TextColor(GRAY);
	gotoxy(51, 2);
	cout << "23127427 - 23127517";
	gotoxy(46, 3);
	cout << "VU HOANG MINH - NGUYEN NAM VIET";
	TextColor(YELLOW);
	displayLogo(18, 8);
	TextColor(WHITE);
}

void displayGameBox(int x, int y, int boxHeight, int boxWidth, int** board, Board gameBoard) // print up to down, then left to right
{
	for (int w = 0, j = 1; j < gameBoard.col + 1; w += 10, j++)
	{
		for (int l = 0, i = 1; i < gameBoard.row + 1; l += 5, i++)
		{
			if (board[i][j] != 0)
				displayBoxChar(x + w, y + l, 5, 10, (char)board[i][j]);
			if (board[i][j] == 1)
				displayBox(x + w, y + l, 5, 10, "BLOCK");
		}
	}
}

void displayPokeball(int x, int y, int ball_color)
{
	TextColor(ball_color);
	gotoxy(x, y);
	gotoxy(x + 7, y); cout << "///////////* "; gotoxy(x, ++y);
	gotoxy(x + 4, y);  cout << "/////////////////* "; gotoxy(x, ++y);
	gotoxy(x + 1, y); cout << " /////////////////////* "; gotoxy(x, ++y);
	cout << " //////////     ////////* "; gotoxy(x, ++y);
	cout << " ///////"; TextColor(7); cout << "   @@@@@   "; TextColor(ball_color); cout << "/////*"; gotoxy(x, ++y);
	TextColor(7);
	cout << "          @@@@@@@        "; gotoxy(x, ++y);
	cout << " @@@@@@@   @@@@@   @@@@@&"; gotoxy(x, ++y);
	cout << " @@@@@@@@@       @@@@@@@&"; gotoxy(x, ++y);
	cout << "  @@@@@@@@@@@@@@@@@@@@@&"; gotoxy(x, ++y);
	cout << "    @@@@@@@@@@@@@@@@@& "; gotoxy(x, ++y);
	cout << "       @@@@@@@@@@@&  "; gotoxy(x, ++y);
}

void displayBackground_1(int x, int y) //display the whole background
{
	TextColor(LIGHT_RED);
	gotoxy(x, y);
	cout << "                                                                                 "; gotoxy(x, ++y);
	cout << " ,*                                                                              "; gotoxy(x, ++y);
	cout << "     ,*                                                     */*.  .,             "; gotoxy(x, ++y);
	cout << "  ,      */                                            //,     ,, ,              "; gotoxy(x, ++y);
	cout << "             */            #%*###*-,                (*   , ,,,*,,                "; gotoxy(x, ++y);
	cout << "      , ,,,     (      ((##(#####(##%           ,(  ,,,,,,****/                  "; gotoxy(x, ++y);
	cout << "        ,,,,,     (   /#######%%%%###(&%,, ,  #   ,,,,******/                    "; gotoxy(x, ++y);
	cout << "          /  ,      ##########%%%%####((#&@,(     ,,,****(                       "; gotoxy(x, ++y);
	cout << "             ,/, ,*/########%%%%%%####(((/(#( *,,,,*((                           "; gotoxy(x, ++y);
	cout << "                   #(,(####%%#%%(,( #((((///*,/,                                 "; gotoxy(x, ++y);
	cout << "                  ,/"; TextColor(LIGHT_RED); cout << "("; TextColor(LIGHT_RED); cout << "  ,###%%%##("; TextColor(LIGHT_RED); cout << " & "; TextColor(LIGHT_RED); cout << "  ((((//*/#                         "; TextColor(LIGHT_RED); cout << "*        "; TextColor(LIGHT_RED); gotoxy(x, ++y);
	cout << "                  /   *(##%%%##,    /(((/////#                        "; TextColor(LIGHT_RED); cout << ",%#"; TextColor(LIGHT_RED); cout << "        "; gotoxy(x, ++y);
	cout << "                  # , ###%%%%##/,  ,*#((////((   (%%%%#*  ,          "; TextColor(LIGHT_RED); cout << "&&%#*"; TextColor(LIGHT_RED); cout << "       "; gotoxy(x, ++y);
	cout << "                  #######/##%%###%%##(((/***/&&##(((((((("; TextColor(LIGHT_RED); cout << "#&&%###&&%%%%#((/"; TextColor(LIGHT_RED); cout << "       "; gotoxy(x, ++y);
	cout << "                  //((((((#(/##(#((((//**,*/((((####((((((("; TextColor(LIGHT_RED); cout << "#&&(//((##((/*,"; TextColor(LIGHT_RED); cout << "       "; gotoxy(x, ++y);
	cout << "                   ,*//*//////////****,***("; TextColor(LIGHT_RED); cout << "%@#"; TextColor(LIGHT_RED); cout << "//(///////////"; TextColor(LIGHT_RED); cout << "////*/(/*//**        "; gotoxy(x, ++y); TextColor(LIGHT_RED);
	cout << "                   ,"; TextColor(LIGHT_RED); cout << "%&%("; TextColor(LIGHT_RED); cout << "////*****//*****//"; TextColor(LIGHT_RED); cout << "(#&@&&("; TextColor(LIGHT_RED); cout << "#/**/////***"; TextColor(LIGHT_RED); cout << "*******/*,,         "; gotoxy(x, ++y);; TextColor(LIGHT_RED);
	cout << "                  "; TextColor(LIGHT_RED); cout << ",(##&%%%%%%%%%%#%#(#(%%&@&&&&#&#"; TextColor(LIGHT_RED); cout << "(#*,*****,,,*,,,,,,*           "; gotoxy(x, ++y);
	cout << "                   "; TextColor(LIGHT_RED); cout << "%#&&&@&@@@@@@@@&&@&&%&&&&%%"; TextColor(LIGHT_RED); cout << "####"; TextColor(LIGHT_RED); cout << "*/(,,,,,,,,,,,,,,,             "; gotoxy(x, ++y);
	cout << "                   "; TextColor(LIGHT_RED); cout << "((%%&&&&&&&&&&&%&&#%("; TextColor(LIGHT_RED); cout << "###"; TextColor(LIGHT_RED); cout << "(((///****/,,,,,,,,,,,                "; gotoxy(x, ++y);
	cout << "                    "; TextColor(LIGHT_RED); cout << ",(###%%%%%%%##"; TextColor(LIGHT_RED); cout << "###"; TextColor(LIGHT_RED); cout << "(/*/(/*/****,,,*/,,,,,,,,                   "; gotoxy(x, ++y);
	cout << "                      "; TextColor(LIGHT_RED); cout << "((((((((((((("; TextColor(LIGHT_RED); cout << "/**,** /*,* ,,,,,*                            "; gotoxy(x, ++y);
	cout << "                        ,///////**(/* ,,,,,*  ,  ,,,,/                           "; gotoxy(x, ++y);
	cout << "                          ///*,*   *,,,**,,        ,,/                           "; gotoxy(x, ++y);
	cout << "                          *///*,,  ////**,,       ,,,                            "; gotoxy(x, ++y);
	cout << "                          **/**,, ////**,*    ,   ,,*                            "; gotoxy(x, ++y);
	cout << "                         ,((/*,, */(((//*    ,,,  ,,                             "; gotoxy(x, ++y);
	cout << "                         **//*,  /////*,                                         "; gotoxy(x, ++y);
	cout << "                                                                                 "; gotoxy(x, ++y);
	cout << "                                                                                 "; gotoxy(x, ++y);
	TextColor(WHITE);
}

void deleteBox(int x, int y, int boxHeight, int boxWidth)
{
	gotoxy(x, y);
	for (int i = 0; i < boxHeight; i++)
	{
		for (int j = 0; j < boxWidth; j++)
		{
			cout << " ";
		}
		gotoxy(x, ++y);
	}
}

void displayBoxChar(int x, int y, int boxHeight, int boxWidth, char s) //input the corner coordinate of the box and box's size
{
	char c;
	c = 205;
	for (int i = 0; i < boxWidth; i++) //box's width
	{
		gotoxy(x + i, y);
		cout << c;
		gotoxy(x + i, y + boxHeight - 1);
		cout << c;
	}


	c = 186;
	for (int i = 0; i < boxHeight; i++)
	{
		gotoxy(x + boxWidth - 1, y + i);
		cout << c;
		gotoxy(x, y + i);
		cout << c;
	}

	c = 188;
	gotoxy(x + boxWidth - 1, y + boxHeight - 1);
	cout << c;

	c = 201;
	gotoxy(x, y);
	cout << c;

	c = 187;
	gotoxy(x + boxWidth - 1, y);
	cout << c;

	c = 200;
	gotoxy(x, y + boxHeight - 1);
	cout << c;

	for (int i = 1; i < boxHeight - 1; i++)
	{
		for (int j = 1; j < boxWidth - 1; j++)
		{
			gotoxy(x + j, y + i);
			cout << " ";
		}
	}

	if ((int)s != 0)
	{
		gotoxy(x + (boxWidth - 1) / 2, y + boxHeight / 2);
		cout << s;
	}
}

void displayPlayerInfo(vector <Player*> list, int playerPos)
{
	TextColor(AQUA);
	displayBox(87, 2, 17, 31, "");
	gotoxy(97, 4);
	TextColor(YELLOW);
	cout << "PLAYER INFO";
	gotoxy(89, 6);
	TextColor(WHITE);
	cout << "NAME: ";
	cout << list[playerPos]->userName;

	gotoxy(89, 8);
	cout << "MATCHES PLAYED: ";
	cout << list[playerPos]->Easy->matches + list[playerPos]->Hard->matches;

	gotoxy(89, 10);
	cout << "BEST POINT";
	gotoxy(89, 11);
	cout << "- EASY MODE: ";
	cout << list[playerPos]->Easy->bestPoint;
	gotoxy(89, 12);
	cout << "- HARD MODE: ";
	cout << list[playerPos]->Hard->bestPoint;

	gotoxy(89, 14);
	cout << "BEST TIME: ";
	gotoxy(89, 15);
	cout << "- EASY MODE: ";
	cout << list[playerPos]->Easy->bestTime;
	gotoxy(89, 16);
	cout << "- HARD MODE: ";
	cout << list[playerPos]->Hard->bestTime;
}

void displayGameStatistic()
{
	TextColor(LIGHT_GREEN);
	displayBox(87, 19, 4, 11, "0");
	gotoxy(90, 20);
	cout << "POINT";

	TextColor(YELLOW);
	displayBox(97, 19, 4, 11, "0");
	gotoxy(100, 20);
	cout << "MOVES";

	TextColor(LIGHT_RED);
	displayBox(107, 19, 4, 11, "0");
	gotoxy(109, 20);
	cout << "MISTAKE";
}

void displayGameInstruction()
{
	TextColor(AQUA);
	displayBox(87, 23, 11, 31, "");
	gotoxy(99, 24);
	TextColor(YELLOW);
	cout << "PLAYER";
	gotoxy(97, 25);
	cout << "INSTRUCTION";
	gotoxy(89, 27);
	TextColor(WHITE);
	cout << "ARROW KEYS: MOVE";
	gotoxy(89, 28);
	cout << "SPACE: SELECT";
	gotoxy(89, 29);
	cout << "H: HINT (-7 PTS)";
	gotoxy(89, 30);
	cout << "F: SHUFFLE (-3 PTS)";
	gotoxy(89, 31);
	cout << "S: SAVE GAME";
	gotoxy(89, 32);
	cout << "ESC: BACK TO MENU";
	TextColor(WHITE);
}

void updateGameStatistic(int point, int move, int mistake)
{
	TextColor(LIGHT_GREEN);
	gotoxy(92, 21); // point
	cout << point;
	if (point < 10)
		cout << " ";

	TextColor(YELLOW);
	gotoxy(102, 21); //moves
	cout << move;

	TextColor(LIGHT_RED);
	gotoxy(112, 21); //mistake
	cout << mistake;

	TextColor(WHITE);
}

void displayWinGame(int time, int& choice)
{
	deleteBox(87, 23, 11, 31);
	TextColor(AQUA);
	displayBox(87, 23, 11, 31, "");
	gotoxy(96, 25);
	TextColor(YELLOW);
	cout << "GAME FINISHED";

	gotoxy(97, 27);
	TextColor(WHITE);
	cout << "TIME PLAYED";
	gotoxy(101, 28);
	cout << time << "s";

	choice = 1;
	bool loop = true;

	while (loop)
	{
		if (choice == 1)
			TextColor(YELLOW);
		gotoxy(91, 31);
		cout << "NEW GAME";
		TextColor(WHITE);

		if (choice == 2)
			TextColor(YELLOW);
		gotoxy(108, 31);
		cout << "BACK";
		TextColor(WHITE);

		int input = _getch();
		switch (input)
		{
		case KEY_RIGHT:
			choice++;
			if (choice > 2)
				choice = 2;
			break;

		case KEY_LEFT:
			choice--;
			if (choice < 1)
				choice = 1;
			break;

		case KEY_ENTER: case SPACE_BAR:
			PlaySound(TEXT("SELECT.wav"), NULL, SND_ASYNC);
			loop = false;
			break;
		}
	}
}

void displayContinueGame(int& choice)
{
	deleteBox(53, 17, 3, 14);
	deleteBox(53, 21, 3, 14);
	deleteBox(53, 25, 3, 14);
	deleteBox(53, 29, 3, 14);
	gotoxy(48, 18);
	cout << "CONTINUE YOUR LAST GAME?";
	choice = 1;
	bool flag = true;
	while (flag)
	{
		if (choice == 1)
			TextColor(YELLOW);
		displayBox(53, 21, 3, 14, "YES");
		TextColor(WHITE);

		if (choice == 2)
			TextColor(YELLOW);
		displayBox(53, 25, 3, 14, "NO");
		TextColor(WHITE);

		int input = _getch();

		switch (input)
		{
		case KEY_UP:
			choice--;
			if (choice < 1)
				choice = 1;
			break;

		case KEY_DOWN:
			choice++;
			if (choice > 2)
				choice = 2;
			break;

		case KEY_ENTER: case SPACE_BAR:
			PlaySound(TEXT("SELECT.wav"), NULL, SND_ASYNC);
			flag = false;
			break;
		}
	}
}

void displayConfirmQuit(int& choice)
{
	deleteBox(87, 23, 11, 31);
	TextColor(AQUA);
	displayBox(87, 23, 11, 31, "");

	gotoxy(96, 27);
	TextColor(YELLOW);
	cout << "DO YOU WANT TO";
	gotoxy(98, 28);
	cout << "SAVE GAME?";
	TextColor(WHITE);
	choice = 1;
	bool loop = true;

	while (loop)
	{
		if (choice == 1)
			TextColor(YELLOW);
		gotoxy(93, 31);
		cout << "YES";
		TextColor(WHITE);

		if (choice == 2)
			TextColor(YELLOW);
		gotoxy(109, 31);
		cout << "NO";
		TextColor(WHITE);

		int input = _getch();
		switch (input)
		{
		case KEY_RIGHT:
			choice++;
			if (choice > 2)
				choice = 2;
			break;

		case KEY_LEFT:
			choice--;
			if (choice < 1)
				choice = 1;
			break;

		case KEY_ENTER: case SPACE_BAR:
			PlaySound(TEXT("SELECT.wav"), NULL, SND_ASYNC);
			loop = false;
			break;
		}
	}
}

void matchingLineType(Pokemon p, int type)
{
	p.x = 4 + (p.j - 1) * 10;
	p.y = 3 + (p.i - 1) * 5;

	char c = 219;
	if (type == 1) // draw ====
	{
		for (int i = 0; i < 10; i++)
		{
			gotoxy(p.x + i, p.y + 2);
			cout << c;
		}
	}

	if (type == 2) // draw ||
	{
		for (int i = 0; i < 5; i++)
		{
			gotoxy(p.x + 5, p.y + i);
			cout << c;
		}
	}

	if (type == 3) // draw |-; |
	{
		for (int i = 0; i < 5; i++)
		{
			gotoxy(p.x + i, p.y + 2);
			cout << c;
		}
		for (int i = 0; i < 3; i++)
		{
			gotoxy(p.x + 5, p.y + 2 + i);
			cout << c;
		}
	}

	if (type == 4) // draw |-' |
	{
		for (int i = 0; i < 5; i++)
		{
			gotoxy(p.x + i, p.y + 2);
			cout << c;
		}
		for (int i = 0; i < 3; i++)
		{
			gotoxy(p.x + 5, p.y + i);
			cout << c;
		}
	}

	if (type == 5) // draw | ;-|
	{
		for (int i = 0; i < 5; i++)
		{
			gotoxy(p.x + 5 + i, p.y + 2);
			cout << c;
		}
		for (int i = 0; i < 3; i++)
		{
			gotoxy(p.x + 5, p.y + 2 + i);
			cout << c;
		}
	}

	if (type == 6) // | '-|
	{
		for (int i = 0; i < 5; i++)
		{
			gotoxy(p.x + 5 + i, p.y + 2);
			cout << c;
		}
		for (int i = 0; i < 3; i++)
		{
			gotoxy(p.x + 5, p.y + i);
			cout << c;
		}
	}
}

void displayMatchingLine(Pokemon p1, Pokemon p2, int** board, Pokemon*& temp, Board gameBoard, bool display)
{
	bool customMode = (gameBoard.row * gameBoard.col < 48);
	if (p1.i == p2.i) // same row
	{
		if (p2.j < p1.j)
			swap(p1, p2); //p1 < p2

		if (p2.j - p1.j - 1 > 0)
			temp = new Pokemon[p2.j - p1.j - 1];
		for (int k = 0; k < p2.j - p1.j - 1; k++)
		{
			temp[k].i = p1.i;
			temp[k].j = p1.j + k + 1;
			temp[k].x = p1.x + (k + 1) * 10;
			temp[k].y = p1.y;
		}

		if (display)
		{
			TextColor(GREEN);
			displayBoxChar(p1.x, p1.y, 5, 10, board[p1.i][p1.j]);
			displayBoxChar(p2.x, p2.y, 5, 10, board[p2.i][p2.j]);
			TextColor(WHITE);

			for (int k = 0; k < p2.j - p1.j - 1; k++)
			{
				TextColor(YELLOW);
				matchingLineType(temp[k], 1);
				TextColor(WHITE);
			}

			Sleep(300);
			for (int k = 0; k < p2.j - p1.j - 1; k++)
			{
				if (customMode)
					displayBackground_2(temp[k]);
				else
					background_1_upgrade(temp[k]);
			}
			if (p2.j - p1.j - 1 > 0)
				delete[] temp;
		}
	}

	if (p1.j == p2.j) // same column
	{
		if (p2.i < p1.i)
			swap(p1, p2); //p1 < p2

		if (p2.i - p1.i - 1 > 0)
			temp = new Pokemon[p2.i - p1.i - 1];
		for (int k = 0; k < p2.i - p1.i - 1; k++)
		{
			temp[k].i = p1.i + 1 + k;
			temp[k].j = p1.j;
			temp[k].x = p1.x;
			temp[k].y = p1.y + (k + 1) * 5;
		}

		if (display)
		{
			TextColor(GREEN);
			displayBoxChar(p1.x, p1.y, 5, 10, board[p1.i][p1.j]);
			displayBoxChar(p2.x, p2.y, 5, 10, board[p2.i][p2.j]);
			TextColor(WHITE);

			for (int k = 0; k < p2.i - p1.i - 1; k++)
			{
				TextColor(YELLOW);
				matchingLineType(temp[k], 2);
				TextColor(WHITE);
			}

			Sleep(300);
			for (int k = 0; k < p2.i - p1.i - 1; k++)
			{
				if (customMode)
					displayBackground_2(temp[k]);
				else
					background_1_upgrade(temp[k]);
			}
			if (p2.i - p1.i - 1 > 0)
				delete[] temp;
		}
	}
}

void displayMatchingLineL(Pokemon p1, Pokemon p2, Pokemon corner, int** board, Board gameBoard)
{
	bool customMode = (gameBoard.row * gameBoard.col < 48);
	TextColor(GREEN);
	displayBoxChar(p1.x, p1.y, 5, 10, board[p1.i][p1.j]);
	displayBoxChar(p2.x, p2.y, 5, 10, board[p2.i][p2.j]);

	if (p1.i > p2.i)
		swap(p1, p2); // p1 higher than p2

	Pokemon* temp1 = NULL;
	Pokemon* temp2 = NULL;
	displayMatchingLine(p1, corner, board, temp1, gameBoard, false);
	displayMatchingLine(p2, corner, board, temp2, gameBoard, false);

	TextColor(YELLOW);
	if (p1.i == corner.i)
	{
		for (int k = 0; k < abs(corner.j - p1.j) - 1; k++)
		{
			matchingLineType(temp1[k], 1);
		}
		for (int k = 0; k < abs(corner.i - p2.i) - 1; k++)
		{
			matchingLineType(temp2[k], 2);
		}
		if (p1.j < corner.j)
			matchingLineType(corner, 3);
		else
			matchingLineType(corner, 5);

		//display background
		Sleep(300);
		for (int k = 0; k < abs(corner.j - p1.j) - 1; k++)
		{
			if (customMode)
				displayBackground_2(temp1[k]);
			else
				background_1_upgrade(temp1[k]);
		}
		for (int k = 0; k < abs(corner.i - p2.i) - 1; k++)
		{
			if (customMode)
				displayBackground_2(temp2[k]);
			else
				background_1_upgrade(temp2[k]);
		}
		if (customMode)
			displayBackground_2(corner);
		else
			background_1_upgrade(corner);
	}

	if (p1.j == corner.j)
	{
		for (int k = 0; k < abs(corner.i - p1.i) - 1; k++)
		{
			matchingLineType(temp1[k], 2);
		}
		for (int k = 0; k < abs(corner.j - p2.j) - 1; k++)
		{
			matchingLineType(temp2[k], 1);
		}
		if (p2.j < corner.j)
			matchingLineType(corner, 4);
		else
			matchingLineType(corner, 6);

		//display background
		Sleep(300);
		for (int k = 0; k < abs(corner.i - p1.i) - 1; k++)
		{
			if (customMode)
				displayBackground_2(temp1[k]);
			else
				background_1_upgrade(temp1[k]);
		}
		for (int k = 0; k < abs(corner.j - p2.j) - 1; k++)
		{
			if (customMode)
				displayBackground_2(temp2[k]);
			else
				background_1_upgrade(temp2[k]);
		}
		if (customMode)
			displayBackground_2(corner);
		else
			background_1_upgrade(corner);
	}
	if (temp1 != NULL)
		delete[] temp1;
	if (temp2 != NULL)
		delete[] temp2;
}

void matchingLineUZ(Pokemon p1, Pokemon p2, Pokemon corner1, Pokemon corner2, int** board, Board gameBoard)
{
	bool customMode = (gameBoard.row * gameBoard.col < 48);
	char c = 219;
	TextColor(GREEN);
	displayBoxChar(p1.x, p1.y, 5, 10, board[p1.i][p1.j]);
	displayBoxChar(p2.x, p2.y, 5, 10, board[p2.i][p2.j]);
	TextColor(WHITE);
	Pokemon* temp1 = NULL;
	Pokemon* temp2 = NULL;
	Pokemon* temp3 = NULL;
	displayMatchingLine(p1, corner1, board, temp1, gameBoard, false);
	displayMatchingLine(corner1, corner2, board, temp2, gameBoard, false);
	displayMatchingLine(p2, corner2, board, temp3, gameBoard, false);

	bool check1 = corner1.i == 0 || corner1.j == 0 || corner1.i == gameBoard.row + 1 || corner1.j == gameBoard.col + 1;
	bool check2 = corner2.i == 0 || corner2.j == 0 || corner2.i == gameBoard.row + 1 || corner2.j == gameBoard.col + 1;

	//if ((!check1) && (!check2))
	{
		if (corner1.i == corner2.i) //same row
		{
			int line; // use for case corner is out of board
			if (p1.j > p2.j)
			{
				swap(corner1, corner2);
				swap(p1, p2); // p1 < p2
				swap(temp1, temp3);
			}

			TextColor(YELLOW);
			for (int k = 0; k < abs(corner1.i - p1.i) - 1; k++)
			{
				matchingLineType(temp1[k], 2);
			}

			if (corner1.i == 0 || corner1.i == gameBoard.row + 1)
			{
				if (corner1.i == 0)
				{
					line = 1;
					for (int i = 0; i < 2; i++)
					{
						gotoxy(p1.x + 5, line + i);
						cout << c;
						gotoxy(p2.x + 5, line + i);
						cout << c;
					}
				}
				else
				{
					line = gameBoard.row * 5 + 4; // default 34
					for (int i = 0; i < 2; i++)
					{
						gotoxy(p1.x + 5, line - i);
						cout << c;
						gotoxy(p2.x + 5, line - i);
						cout << c;
					}
				}
				for (int i = p1.x + 5; i <= p2.x + 5; i++)
				{
					gotoxy(i, line);
					cout << c;
				}
			}
			else
			{
				for (int k = 0; k < abs(corner2.j - corner1.j) - 1; k++)
				{
					matchingLineType(temp2[k], 1);
				}
			}

			for (int k = 0; k < abs(corner2.i - p2.i) - 1; k++)
			{
				matchingLineType(temp3[k], 2);
			}

			if (corner1.i != 0 && corner1.i != gameBoard.row + 1)
			{
				if (corner1.i > p1.i)
					matchingLineType(corner1, 6);
				else
					matchingLineType(corner1, 5);

				if (corner2.i > p2.i)
					matchingLineType(corner2, 4);
				else
					matchingLineType(corner2, 3);
			}

			//display background
			Sleep(300);
			for (int k = 0; k < abs(corner1.i - p1.i) - 1 && temp1 != NULL; k++)
			{
				if (customMode)
					displayBackground_2(temp1[k]);
				else
					background_1_upgrade(temp1[k]);
			}

			if (corner1.i == 0 || corner1.i == gameBoard.row + 1)
			{
				TextColor(WHITE);
				displayBox(2, 2, gameBoard.row * 5 + 2, gameBoard.col * 10 + 4, "");
				deleteBox(p1.x + 5, line, 1, p2.x - p1.x + 1);
			}
			else
			{
				for (int k = 0; k < abs(corner2.j - corner1.j) - 1 && temp2 != NULL; k++)
				{
					if (customMode)
						displayBackground_2(temp2[k]);
					else
						background_1_upgrade(temp2[k]);
				}
				if (customMode)
				{
					displayBackground_2(corner1);
					displayBackground_2(corner2);
				}
				else
				{
					background_1_upgrade(corner1);
					background_1_upgrade(corner2);
				}
			}

			for (int k = 0; k < abs(corner2.i - p2.i) - 1 && temp3 != NULL; k++)
			{
				if (customMode)
					displayBackground_2(temp3[k]);
				else
					background_1_upgrade(temp3[k]);
			}

		}
		//////////////////////////////////////////////
		else if (corner1.j == corner2.j) //same column
		{
			if (p1.i > p2.i)
			{
				swap(corner1, corner2);
				swap(p1, p2); // p1 higher than p2
				swap(temp1, temp3);
			}

			int column;
			TextColor(YELLOW);
			for (int k = 0; k < abs(corner1.j - p1.j) - 1; k++)
			{
				matchingLineType(temp1[k], 1);
			}

			if (corner1.j == 0 || corner1.j == gameBoard.col + 1)
			{
				if (corner1.j == 0)
				{
					column = 1;
					for (int i = 0; i < 3; i++)
					{
						gotoxy(column + i, p1.y + 2);
						cout << c;
						gotoxy(column + i, p2.y + 2);
						cout << c;
					}
				}
				else
				{
					column = gameBoard.col * 10 + 6; //default: 86
					for (int i = 0; i < 3; i++)
					{
						gotoxy(column - i, p1.y + 2);
						cout << c;
						gotoxy(column - i, p2.y + 2);
						cout << c;
					}
				}
				for (int i = p1.y + 2; i <= p2.y + 2; i++)
				{
					gotoxy(column, i);
					cout << c;
				}
			}
			else
			{
				for (int k = 0; k < abs(corner2.i - corner1.i) - 1; k++)
				{
					matchingLineType(temp2[k], 2);
				}
			}

			for (int k = 0; k < abs(corner2.j - p2.j) - 1; k++)
			{
				matchingLineType(temp3[k], 1);
			}

			if (corner1.j != 0 && corner1.j != gameBoard.col + 1)
			{
				if (corner1.j < p1.j)
					matchingLineType(corner1, 5);
				else
					matchingLineType(corner1, 3);
				if (corner2.j < p2.j)
					matchingLineType(corner2, 6);
				else
					matchingLineType(corner2, 4);
			}


			Sleep(300);
			for (int k = 0; k < abs(corner1.j - p1.j) - 1 && temp1 != NULL; k++)
			{
				if (customMode)
					displayBackground_2(temp1[k]);
				else
					background_1_upgrade(temp1[k]);
			}

			if (corner1.j == 0 || corner1.j == gameBoard.col + 1)
			{
				TextColor(WHITE);
				displayBox(2, 2, gameBoard.row * 5 + 2, gameBoard.col * 10 + 4, "");
				deleteBox(column, p1.y + 2, p2.y - p1.y + 1, 1);
				if (corner1.j == 0)
					deleteBox(column + 2, p1.y + 2, p2.y - p1.y + 1, 1);
				else
					deleteBox(column - 2, p1.y + 2, p2.y - p1.y + 1, 1);
			}
			else
			{
				for (int k = 0; k < abs(corner2.i - corner1.i) - 1 && temp2 != NULL; k++)
				{
					if (customMode)
						displayBackground_2(temp2[k]);
					else
						background_1_upgrade(temp2[k]);
				}
				if (customMode)
				{
					displayBackground_2(corner1);
					displayBackground_2(corner2);
				}

				else
				{
					background_1_upgrade(corner1);
					background_1_upgrade(corner2);
				}
			}

			for (int k = 0; k < abs(corner2.j - p2.j) - 1 && temp3 != NULL; k++)
			{
				if (customMode)
					displayBackground_2(temp3[k]);
				else
					background_1_upgrade(temp3[k]);
			}
		}
	}
}

void displayBackground_2(Pokemon p)
{
	gotoxy(p.x, p.y);
	TextColor(YELLOW);
	cout << "          "; gotoxy(p.x, ++p.y);
	cout << "   /\\_/\\  "; gotoxy(p.x, ++p.y);
	cout << "  ( o.o ) "; gotoxy(p.x, ++p.y);
	cout << "   > ^ <  "; gotoxy(p.x, ++p.y);
	cout << "          ";
	TextColor(WHITE);
}

void background_1_upgrade(Pokemon p) //display one part of the background based on the cell location 
{
	if (p.i == 1 && p.j == 1)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << " ,*       "; gotoxy(p.x, ++p.y);
		cout << "     ,*   "; gotoxy(p.x, ++p.y);
		cout << "  ,      *"; gotoxy(p.x, ++p.y);
		cout << "          ";
		TextColor(WHITE);
	}

	else if (p.i == 1 && p.j == 2)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "/         "; gotoxy(p.x, ++p.y);
		cout << "   */     ";
		TextColor(WHITE);
	}
	else if (p.i == 1 && p.j == 3)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "       #%*";
		TextColor(WHITE);
	}
	else if (p.i == 1 && p.j == 4)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "###*-,    ";
		TextColor(WHITE);
	}
	else if (p.i == 1 && p.j == 6)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "     //,  "; gotoxy(p.x, ++p.y);
		cout << "  (*   , ,";
		TextColor(WHITE);
	}
	else if (p.i == 1 && p.j == 7)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "*/*.  .,  "; gotoxy(p.x, ++p.y);
		cout << "   ,, ,   "; gotoxy(p.x, ++p.y);
		cout << ",,*,,     ";
		TextColor(WHITE);
	}
	else if (p.i == 2 && p.j == 1)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "      , ,,"; gotoxy(p.x, ++p.y);
		cout << "        ,,"; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          ";
		TextColor(WHITE);
	}
	else if (p.i == 2 && p.j == 2)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << ",     (   "; gotoxy(p.x, ++p.y);
		cout << ",,,     ( "; gotoxy(p.x, ++p.y);
		cout << "/  ,      "; gotoxy(p.x, ++p.y);
		cout << "   ,/, ,*/"; gotoxy(p.x, ++p.y);
		cout << "         #";
		TextColor(WHITE);
	}
	else if (p.i == 2 && p.j == 3)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "   ((##(##"; gotoxy(p.x, ++p.y);
		cout << "  /#######"; gotoxy(p.x, ++p.y);
		cout << "##########"; gotoxy(p.x, ++p.y);
		cout << "########%%"; gotoxy(p.x, ++p.y);
		cout << "(,(####%%#";
		TextColor(WHITE);
	}
	else if (p.i == 2 && p.j == 4)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "###(##%   "; gotoxy(p.x, ++p.y);
		cout << "%%%%###(&%"; gotoxy(p.x, ++p.y);
		cout << "%%%%####(("; gotoxy(p.x, ++p.y);
		cout << "%%%%####(("; gotoxy(p.x, ++p.y);
		cout << "%%(,( #(((";
		TextColor(WHITE);
	}
	else if (p.i == 2 && p.j == 5)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "        ,("; gotoxy(p.x, ++p.y);
		cout << ",, ,  #   "; gotoxy(p.x, ++p.y);
		cout << "#&@,(     "; gotoxy(p.x, ++p.y);
		cout << "(/(#( *,,,"; gotoxy(p.x, ++p.y);
		cout << "(///*,/,  ";
		TextColor(WHITE);
	}
	else if (p.i == 2 && p.j == 6)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "  ,,,,,,**"; gotoxy(p.x, ++p.y);
		cout << ",,,,******"; gotoxy(p.x, ++p.y);
		cout << ",,,****(  "; gotoxy(p.x, ++p.y);
		cout << ",*((      "; gotoxy(p.x, ++p.y);
		cout << "          ";
		TextColor(WHITE);
	}
	else if (p.i == 2 && p.j == 7)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "**/       "; gotoxy(p.x, ++p.y);
		cout << "/         "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          ";
		TextColor(WHITE);
	}
	else if (p.i == 3 && p.j == 2)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "        ,/"; gotoxy(p.x, ++p.y);
		cout << "        / "; gotoxy(p.x, ++p.y);
		cout << "        # "; gotoxy(p.x, ++p.y);
		cout << "        ##"; gotoxy(p.x, ++p.y);
		cout << "        //";
		TextColor(WHITE);
	}
	else if (p.i == 3 && p.j == 3)
	{
		gotoxy(p.x, p.y);
		TextColor(WHITE);
		cout << "(  "; TextColor(LIGHT_RED); cout << ",###%%%"; gotoxy(p.x, ++p.y);
		cout << "  *(##%%%#"; gotoxy(p.x, ++p.y);
		cout << ", ###%%%%#"; gotoxy(p.x, ++p.y);
		cout << "#####/##%%"; gotoxy(p.x, ++p.y);
		cout << "((((((#(/#";
		TextColor(WHITE);
	}
	else if (p.i == 3 && p.j == 4)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "##( "; TextColor(WHITE); cout << "&   "; TextColor(LIGHT_RED); cout << "(("; gotoxy(p.x, ++p.y);
		cout << "#,    /((("; gotoxy(p.x, ++p.y);
		cout << "#/,  ,*#(("; gotoxy(p.x, ++p.y);
		cout << "###%%##((("; gotoxy(p.x, ++p.y);
		cout << "#(#((((//*";
		TextColor(WHITE);
	}
	else if (p.i == 3 && p.j == 5)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "((//*/#   "; gotoxy(p.x, ++p.y);
		cout << "/////#    "; gotoxy(p.x, ++p.y);
		cout << "////((    "; gotoxy(p.x, ++p.y);
		cout << "/***/&&##("; gotoxy(p.x, ++p.y);
		cout << "*,*/((((##";
		TextColor(WHITE);
	}
	else if (p.i == 3 && p.j == 6)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "%%%%#*  , "; gotoxy(p.x, ++p.y);
		cout << "((((((("; TextColor(WHITE); cout << "#&&"; TextColor(LIGHT_RED); gotoxy(p.x, ++p.y);
		cout << "##((((((("; TextColor(WHITE); cout << "#";
	}
	else if (p.i == 3 && p.j == 7)
	{
		gotoxy(p.x, p.y);
		TextColor(WHITE);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "         &"; gotoxy(p.x, ++p.y);
		cout << "%###&&%%%%"; gotoxy(p.x, ++p.y);
		cout << "&&(//((##(";
	}
	else if (p.i == 3 && p.j == 8)
	{
		gotoxy(p.x, p.y);
		TextColor(WHITE);
		cout << "  *       "; gotoxy(p.x, ++p.y);
		cout << ",%#       "; gotoxy(p.x, ++p.y);
		cout << "&%#*      "; gotoxy(p.x, ++p.y);
		cout << "#((/      "; gotoxy(p.x, ++p.y);
		cout << "(/*,      ";
	}
	else if (p.i == 4 && p.j == 2)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "         ,"; gotoxy(p.x, ++p.y);
		cout << "         ,"; gotoxy(p.x, ++p.y);
		TextColor(WHITE);
		cout << "        ,("; gotoxy(p.x, ++p.y);
		cout << "         %"; gotoxy(p.x, ++p.y);
		cout << "         (";
	}
	else if (p.i == 4 && p.j == 3)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "*//*//////"; gotoxy(p.x, ++p.y);
		TextColor(WHITE);
		cout << "%&%("; TextColor(LIGHT_RED); cout << "////**"; gotoxy(p.x, ++p.y);
		TextColor(WHITE);
		cout << "##&%%%%%%%"; gotoxy(p.x, ++p.y);
		cout << "#&&&@&@@@@"; gotoxy(p.x, ++p.y);
		cout << "(%%&&&&&&&";
	}
	else if (p.i == 4 && p.j == 4)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "////****,*"; gotoxy(p.x, ++p.y);
		cout << "***//*****"; gotoxy(p.x, ++p.y);
		TextColor(WHITE);
		cout << "%%%#%#(#(%"; gotoxy(p.x, ++p.y);
		cout << "@@@@&&@&&%"; gotoxy(p.x, ++p.y);
		cout << "&&&&%&&#%(";
	}
	else if (p.i == 4 && p.j == 5)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "**("; TextColor(WHITE); cout << "%@#"; TextColor(LIGHT_RED); cout << "//(/"; gotoxy(p.x, ++p.y);
		cout << "//"; TextColor(WHITE); cout << "(#&@&&("; TextColor(LIGHT_RED); cout << "#"; gotoxy(p.x, ++p.y);
		TextColor(WHITE);
		cout << "%&@&&&&#&#"; gotoxy(p.x, ++p.y);
		cout << "&&&&%%"; TextColor(GRAY); cout << "####"; gotoxy(p.x, ++p.y);
		cout << "###"; TextColor(LIGHT_RED); cout << "(((///*";
		TextColor(WHITE);
	}
	else if (p.i == 4 && p.j == 6)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "//////////"; gotoxy(p.x, ++p.y);
		cout << "/**/////**"; gotoxy(p.x, ++p.y);
		cout << "(#*,*****,"; gotoxy(p.x, ++p.y);
		cout << "*/(,,,,,,,"; gotoxy(p.x, ++p.y);
		cout << "***/,,,,,,";
		TextColor(WHITE);
	}
	else if (p.i == 4 && p.j == 7)
	{
		gotoxy(p.x, p.y);
		TextColor(GRAY);
		cout << "////*/(/*/"; gotoxy(p.x, ++p.y); TextColor(LIGHT_RED);
		cout << "*"; TextColor(GRAY); cout << "*******/*"; gotoxy(p.x, ++p.y); TextColor(LIGHT_RED);
		cout << ",,*,,,,,,*"; gotoxy(p.x, ++p.y);
		cout << ",,,,,,,,  "; gotoxy(p.x, ++p.y);
		cout << ",,,,,     ";
		TextColor(WHITE);
	}
	else if (p.i == 4 && p.j == 8)
	{
		gotoxy(p.x, p.y);
		TextColor(GRAY);
		cout << "/**       "; gotoxy(p.x, ++p.y);
		cout << ",,        "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          ";
		TextColor(WHITE);
	}
	else if (p.i == 5 && p.j == 3)
	{
		gotoxy(p.x, p.y);
		TextColor(WHITE);
		cout << ",(###%%%%%"; gotoxy(p.x, ++p.y);
		TextColor(GRAY);
		cout << "  (((((((("; gotoxy(p.x, ++p.y);
		TextColor(LIGHT_RED);
		cout << "    ,/////"; gotoxy(p.x, ++p.y);
		cout << "      ///*"; gotoxy(p.x, ++p.y);
		cout << "      *///";
		TextColor(WHITE);
	}
	else if (p.i == 5 && p.j == 4)
	{
		gotoxy(p.x, p.y);
		TextColor(WHITE);
		cout << "%%##"; TextColor(GRAY); cout << "###"; TextColor(LIGHT_RED); cout << "(/*"; gotoxy(p.x, ++p.y);
		TextColor(GRAY);
		cout << "((((("; TextColor(LIGHT_RED); cout << "/**,*"; gotoxy(p.x, ++p.y);
		cout << "//**(/* ,,"; gotoxy(p.x, ++p.y);
		cout << ",*   *,,,*"; gotoxy(p.x, ++p.y);
		cout << "*,,  ////*";
		TextColor(WHITE);
	}
	else if (p.i == 5 && p.j == 5)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "/(/*/****,"; gotoxy(p.x, ++p.y);
		cout << "* /*,* ,,,"; gotoxy(p.x, ++p.y);
		cout << ",,,*  ,  ,"; gotoxy(p.x, ++p.y);
		cout << "*,,       "; gotoxy(p.x, ++p.y);
		cout << "*,,       ";
		TextColor(WHITE);
	}
	else if (p.i == 5 && p.j == 6)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << ",,*/,,,,,,"; gotoxy(p.x, ++p.y);
		cout << ",,*       "; gotoxy(p.x, ++p.y);
		cout << ",,,/      "; gotoxy(p.x, ++p.y);
		cout << " ,,/      "; gotoxy(p.x, ++p.y);
		cout << ",,,       ";
		TextColor(WHITE);
	}
	else if (p.i == 5 && p.j == 7)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << ",,        "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          ";
		TextColor(WHITE);
	}
	else if (p.i == 6 && p.j == 3)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "      **/*"; gotoxy(p.x, ++p.y);
		cout << "     ,((/*"; gotoxy(p.x, ++p.y);
		cout << "     **//*"; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          ";
		TextColor(WHITE);
	}
	else if (p.i == 6 && p.j == 4)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << "*,, ////**"; gotoxy(p.x, ++p.y);
		cout << ",, */(((//"; gotoxy(p.x, ++p.y);
		cout << ",  /////*,"; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          ";
		TextColor(WHITE);
	}
	else if (p.i == 6 && p.j == 5)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << ",*    ,   "; gotoxy(p.x, ++p.y);
		cout << "*    ,,,  "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          ";
		TextColor(WHITE);
	}
	else if (p.i == 6 && p.j == 6)
	{
		gotoxy(p.x, p.y);
		TextColor(LIGHT_RED);
		cout << ",,*       "; gotoxy(p.x, ++p.y);
		cout << ",,        "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          ";
		TextColor(WHITE);
	}
	else
	{
		gotoxy(p.x, p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          "; gotoxy(p.x, ++p.y);
		cout << "          ";
	}
}
