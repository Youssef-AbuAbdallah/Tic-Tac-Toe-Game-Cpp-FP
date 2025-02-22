# include <iostream>
# include <iomanip>
# include <cmath>
# include <string>

using namespace std;

enum enGameMode { Player = 1, Computer = 2 };
enum enChoiceXorO { X=1 , O=2};
enum enGamedWinner {Player1=1 , Computer2=2 , Draw=3};

struct stRoundInfo
{
	int NumberOfTurns;
	enGameMode enGameMode;
	enChoiceXorO enPlayerChoice;
	enChoiceXorO enComputerChoice;
	enGamedWinner enWinner;
	char PlayerChoicech, ComputerChoicech;
	/*string WinnerName, Player1, Player2;*/
};

int RandomNumber(int From , int To)
{
	int Number;
	Number = rand() % (To - From + 1) + From;
	return Number;
}
int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
	cout << Message;
	cin >> Number;
	} while (Number<0);
	return Number;
}
char ReadXorO(string Message)
{
	char Mychar;
	do
	{
		cout << Message;
		cin >> Mychar;
	} while (toupper(Mychar) != 'X' && toupper(Mychar) != 'O');
	return(toupper(Mychar));
}



enGameMode EnterGameMode()
{
	enGameMode enGameOptioons[] = { enGameMode::Player , enGameMode::Computer };
	return enGameOptioons[ReadPositiveNumber("Please choose Game Mode  [1]VS Friend   ,   [2]VS Computer   :  ") - 1];
}

enChoiceXorO EnterPlayWithXorO(stRoundInfo &player)
{
	player.PlayerChoicech = ReadXorO("Please choose symbol to player1   [ X or O ]  ?     ");
	
	switch (player.PlayerChoicech)
	{
	case ('X'):
	{
		player.ComputerChoicech = 'O';
		return enChoiceXorO::X;
		break;
	}
	case ('O'):
	{
		player.ComputerChoicech = 'X';
		return enChoiceXorO::O;
		break;
	}
	}
}

enChoiceXorO HandleComputerChoice(enChoiceXorO PlayerChoice)
{
	return ((PlayerChoice== enChoiceXorO::X) ? enChoiceXorO::O : enChoiceXorO::X);
}


bool IsThereaBlankSpaces(char arr[5][12])
{
	
	return(arr[0][1] == ' ' || arr[0][5] == ' ' || arr[0][9] == ' '
		|| arr[2][1] == ' ' || arr[2][5] == ' ' || arr[2][9] == ' '
		|| arr[4][1] == ' ' || arr[4][5] == ' ' || arr[4][9] == ' ');	
}

void PlayOneTurn(char arr[5][12] , char Choice)
{

EnterPositionAgain :	int Number = ReadPositiveNumber("\nPlease enter position ");

		switch (Number)
		{
		case(1):
		{
			if (arr[0][1] == ' ')
			{
			arr[0][1] = Choice;
			break;
			}
			else
			{
				goto EnterPositionAgain;
			}
		}
		case (2):
		{
			if (arr[0][5] == ' ')
			{
			arr[0][5] = Choice;
			break;
			}
			else
			{
				goto EnterPositionAgain;
			}

		}
		case (3):
		{
			if (arr[0][9] == ' ')
			{
			arr[0][9] = Choice;
			break;
			}
			else
			{
				goto EnterPositionAgain;
			}
		}
		case(4):
		{
			if (arr[2][1] == ' ')
			{
			arr[2][1] = Choice;
			break;
			}
			else
			{
				goto EnterPositionAgain;
			}
		}
		case(5):
		{
			if (arr[2][5] == ' ')
			{
			arr[2][5] = Choice;
			break;
			}
			else
			{
				goto EnterPositionAgain;
			}
		}
		case(6):
		{
			if (arr[2][9] == ' ')
			{
			arr[2][9] = Choice;
			break;
			}
			else
			{
				goto EnterPositionAgain;
			}
		}
		case(7):
		{
			if (arr[4][1] == ' ')
			{
			arr[4][1] = Choice;
			break;
			}
			else
			{
				goto EnterPositionAgain;
			}
		}
		case(8):
		{
			if (arr[4][5] == ' ')
			{
			arr[4][5] = Choice;
			break;
			}
			else
			{
				goto EnterPositionAgain;
			}
		}
		case(9):
		{
			if (arr[4][9] == ' ')
			{
			arr[4][9] = Choice;
			break;
			}
			else
			{
				goto EnterPositionAgain;
			}
		}
		default :
		{
			cout << "\n Only enter positions from 1 to 9 \n";
				goto EnterPositionAgain;
		}
		}
}

void PrintArray(char arr[5][12])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			cout << arr[i][j];
		}
	}
	cout << "\n\n";
}

enGamedWinner WhoWinTheRound(char arr[5][12] , stRoundInfo &Round)
{
	if (arr[0][1] == Round.PlayerChoicech && arr[0][5] == Round.PlayerChoicech && arr[0][9] == Round.PlayerChoicech)
	{
		return enGamedWinner::Player1;	
	}
	else if (arr[2][1] == Round.PlayerChoicech && arr[2][5] == Round.PlayerChoicech && arr[2][9] == Round.PlayerChoicech)
	{
		return enGamedWinner::Player1;
	}
	else if (arr[4][1] == Round.PlayerChoicech && arr[4][5] == Round.PlayerChoicech && arr[4][9] == Round.PlayerChoicech)
	{
		return enGamedWinner::Player1;
	}
	else if (arr[0][1] == Round.PlayerChoicech && arr[2][1] == Round.PlayerChoicech && arr[4][1] == Round.PlayerChoicech)
	{
		return enGamedWinner::Player1;
	}
	else if (arr[0][5] == Round.PlayerChoicech && arr[2][5] == Round.PlayerChoicech && arr[4][5] == Round.PlayerChoicech)
	{
		return enGamedWinner::Player1;
	}
	else if (arr[0][9] == Round.PlayerChoicech && arr[2][9] == Round.PlayerChoicech && arr[4][9] == Round.PlayerChoicech)
	{
		return enGamedWinner::Player1;
	}
	else if (arr[0][1] == Round.PlayerChoicech && arr[2][5] == Round.PlayerChoicech && arr[4][9] == Round.PlayerChoicech)
	{
		return enGamedWinner::Player1;
	}
	else if (arr[0][9] == Round.PlayerChoicech && arr[2][5] == Round.PlayerChoicech && arr[4][1] == Round.PlayerChoicech)
	{
		return enGamedWinner::Player1;
	}

	///////////////////////////////////////////////////////////////////////////
	else if (arr[0][1] == Round.ComputerChoicech && arr[0][5] == Round.ComputerChoicech && arr[0][9] == Round.ComputerChoicech)
	{
		return enGamedWinner::Computer2;
	}
	else if (arr[2][1] == Round.ComputerChoicech && arr[2][5] == Round.ComputerChoicech && arr[2][9] == Round.ComputerChoicech)
	{
		return enGamedWinner::Computer2;
	}
	else if (arr[4][1] == Round.ComputerChoicech && arr[4][5] == Round.ComputerChoicech && arr[4][9] == Round.ComputerChoicech)
	{
		return enGamedWinner::Computer2;
	}
	else if (arr[0][1] == Round.ComputerChoicech && arr[2][1] == Round.ComputerChoicech && arr[4][1] == Round.ComputerChoicech)
	{
		return enGamedWinner::Computer2;
	}
	else if (arr[0][5] == Round.ComputerChoicech && arr[2][5] == Round.ComputerChoicech && arr[4][5] == Round.ComputerChoicech)
	{
		return enGamedWinner::Computer2;
	}
	else if (arr[0][9] == Round.ComputerChoicech && arr[2][9] == Round.ComputerChoicech && arr[4][9] == Round.ComputerChoicech)
	{
		return enGamedWinner::Computer2;
	}
	else if (arr[0][1] == Round.ComputerChoicech && arr[2][5] == Round.ComputerChoicech && arr[4][9] == Round.ComputerChoicech)
	{
		return enGamedWinner::Computer2;
	}
	else if (arr[0][9] == Round.ComputerChoicech && arr[2][5] == Round.ComputerChoicech && arr[4][1] == Round.ComputerChoicech)
	{
		return enGamedWinner::Computer2;
	}
	/////////////////////////////////////////////////////////////////////////////
	else
	{
		return enGamedWinner::Draw;
	}

}

void RoundInfo(stRoundInfo Round)
{
	cout << "\n-------------------------[ Round Info ]-----------------------------------\n";
	cout << "Number of Turns  : " << setw(30) << Round.NumberOfTurns << endl;
	cout << "Player1 choice  : " << setw(30) << '[' << Round.PlayerChoicech << ']' << endl;
	if (Round.enGameMode == enGameMode::Computer)
	{
	cout << "Computer choice : " << setw(30) << '[' << Round.ComputerChoicech << ']' << endl;
		(Round.enWinner == enGamedWinner::Draw) ? cout << "Round Winner :  " << setw(30) << '[' << "It is a Draw" << ']' << endl : (Round.enWinner == enGamedWinner::Player1) ? cout << "Round Winner :  " << setw(30) << '[' << "Player" << ']' << endl :
			cout << "Round Winner :  \a" << setw(30) << '[' << "Computer" << ']' << endl;
		(Round.enWinner == enGamedWinner::Draw) ? system("color 6f") : (Round.enWinner == enGamedWinner::Player1) ? system("color 2f") : system("color 4f");
	}
	else if (Round.enGameMode == enGameMode::Player)
	{
	cout << "Player2 choice  : " << setw(30) << '[' << Round.ComputerChoicech << ']' << endl;
		(Round.enWinner == enGamedWinner::Draw) ? cout << "Round Winner :  " << setw(30) << '[' << "It is a Draw\a" << ']' << endl : (Round.enWinner == enGamedWinner::Player1) ? cout << "Round Winner :  " << setw(30) << '[' << "Player1" << ']' << endl :
			cout << "Round Winner :  " << setw(30) << '[' << "Player2" << ']' << endl;
		(Round.enWinner == enGamedWinner::Draw) ? system("color 6f") : system("color 2f") ;
	}


	cout << "\n--------------------------------------------------------------------------\n";

}

void ComputerTurn(char arr[5][12] , stRoundInfo Round)
{
	int Rows[] = { 0,2,4 };
	int Columns[] = {1 , 5 , 9};

	int row, col;
	do
	{
	 row = Rows[RandomNumber(0, 2)];
	 col = Columns[RandomNumber(0, 2)];
	} while (arr[row][col] != ' ');
	arr[row][col] = Round.ComputerChoicech;
}


stRoundInfo PlayGame(stRoundInfo Round)
{
	char arr[5][12] = { ' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','\n',
					   '-','-','-', '|','-', '-', '-', '|', '-' ,'-', '-', '\n',
						' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','\n',
					   '-','-','-', '|','-', '-', '-', '|', '-' ,'-', '-', '\n',
						' ',' ',' ','|',' ',' ',' ','|',' ',' ',' ','\n' };

	
	Round.enPlayerChoice = EnterPlayWithXorO(Round);
	Round.enComputerChoice = HandleComputerChoice(Round.enPlayerChoice);
	Round.NumberOfTurns = 0;
	Round.enWinner = WhoWinTheRound(arr, Round);
	int whofirst = RandomNumber(1, 2);
	//play game dash board
	while (IsThereaBlankSpaces(arr) && Round.enWinner == enGamedWinner::Draw)
	{
		++Round.NumberOfTurns;
		if ((whofirst % 2 == 0) && (Round.enGameMode == enGameMode::Computer))////////////////////////////////////////////////
		{
			whofirst++;
			ComputerTurn(arr, Round);
			Round.enWinner = WhoWinTheRound(arr, Round);
		}
		// play aganist freiends
		else if ((whofirst % 2 == 0) && (Round.enGameMode == enGameMode::Player))
		{
			cout << "round [ " << Round.NumberOfTurns << " ] starts  Player2 turn : \n\n";
			PrintArray(arr);
			cout << "\n\n";
			PlayOneTurn(arr, Round.ComputerChoicech);
			Round.enWinner = WhoWinTheRound(arr, Round);
			system("cls");
			whofirst++;
		}
		else
		{
		cout << "round [ " << Round.NumberOfTurns << " ] starts  Player1 turn : \n\n";
		PrintArray(arr);
		cout << "\n\n";
		PlayOneTurn(arr, Round.PlayerChoicech);///////////////////////////////////////////////////////////////////////////////////////////
		Round.enWinner = WhoWinTheRound(arr, Round);
		system("cls");
		whofirst++;
		}
	}
	cout << endl;
	PrintArray(arr);
	cout << "\n\n";
	return Round;
}


void YoussefElsaid()
{
	system("cls");
	system("color 0f");
	cout << "\n\n\n";
	cout << "\t\t------------------------------------------------------------------------------------\n\n";
	cout << "\t\t\t"<< "Thanks ,  I hope you enjoy playing.\n\n";
	cout << "\t\t\t" << "Created by Youssef Elsaid Mohamed Abu-AbdAllah .\n\n";
	cout << "\t\t------------------------------------------------------------------------------------";

	system("pause>0");
}



int main()
{
	srand((unsigned)time(NULL));
	char Question;
	do
	{
		system("cls");
		system("color 0f");
		stRoundInfo Round;
		Round.enGameMode = EnterGameMode();
		Round =PlayGame(Round);
		RoundInfo(Round);
		cout << "\n\nDo you want to play again   [Y/N]  ?  ";
		cin >> Question;
		Question = toupper(Question);
	} while (Question== 'Y');
	
	YoussefElsaid();
}
