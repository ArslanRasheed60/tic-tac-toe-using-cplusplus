#include "TicTacToe.h";
#include <iostream>
#include <fstream>
using namespace std;

void menu()
{
	int initial_choice = 0;

	cout << "\n***************************************************************************";
	cout << "\n**                                                                       **";
	cout << "\n**                              TicTacToe                                **";
	cout << "\n**                                                                       **";
	cout << "\n***************************************************************************";

	cout << "\n\n******  1:  Load previous Game:  ******";
	cout << "\n\n****** 2: New game:  *******";
	cout << "\n\n****** -1: To exit: ******";
	cout << "\n\nEnter choice       ";
	cin >> initial_choice;
	//if input is invalid then enter again.
	while (initial_choice != -1 && initial_choice != 1 && initial_choice != 2)
	{
		cout << "\n\n.........Invalid choice........Enter again:   ";
		cin >> initial_choice;
	}
	if (initial_choice == 1)
	{
		//from count we will examine that which player exit the game and from which player the game will start
		int count = 1;
		int win = 0;
		ticTacToe board_file;
		board_file.readdata(count, board_file);
		cout << "\n****** Game Started *******";
		cout << "\n^^^^^^^ PLAYER 1 character   (X) ^^^^^^^^";
		cout << "\n^^^^^^^ Player 2 character   (O) ^^^^^^^^";

		if (count % 2 == 1)						//it shows that next turn is of 1st player 
		{
			while (true)
			{
				cout << endl;
				cout << board_file;
				char temp = '\0';
				cout << "\nPLAYER 1 turn: ";
				board_file.getting_move('X');						//getting move for first player.

				if (ticTacToe::exit == -1)					//player exits check
				{
					break;
				}

				cout << board_file;
				if (board_file.win_check() == true)					//winning check
				{
					cout << "\n\n  -[ Player 1 Wins ]- \n";
					win = 1;
					break;
				}
				if (board_file.draw_check() == true)					//draw check
				{
					cout << "\n\n *********** -[ >> Draw << ]- **********\n";
					win = 1;
					break;
				}

				cout << "\nPLAYER 2 turn: ";
				board_file.getting_move('O');					//getting move for second player.

				if (ticTacToe::exit == -1)				//player exits check
				{
					break;
				}

				cout << board_file;
				if (board_file.win_check() == true)			//winning check
				{
					cout << "\n\n  -[ Player 2 Wins ]- \n";
					win = 1;
					break;
				}
				if (board_file.draw_check() == true)					//draw check
				{
					cout << "\n\n *********** -[ >> Draw << ]- **********\n";
					win = 1;
					break;
				}

			}
			if (win != 1)
			{
				char save;
				cout << "\n\nPress s to save the game or press any key to exit: \n";
				cin >> save;
				if (save == 's' || save == 'S')
				{
					board_file.savedata(board_file);						//save data in file
					cout << "\n********Game Save Successfully. *********";
				}
				else
				{
					cout << "\n********** EXITED **********\n";
				}
			}
		}
		else if (count % 2 == 0)						//next turn . player 2
		{
			while (true)
			{
				cout << endl;
				cout << board_file;
				char temp = '\0';
				cout << "\nPLAYER 2 turn: ";
				board_file.getting_move('O');					//getting move for second player.

				if (ticTacToe::exit == -1)				//player exits check
				{
					break;
				}

				cout << board_file;
				if (board_file.win_check() == true)
				{
					cout << "\n\n  -[ Player 2 Wins ]- \n";
					win = 1;
					break;
				}
				if (board_file.draw_check() == true)					//draw check
				{
					cout << "\n\n *********** -[ >> Draw << ]- **********\n";
					win = 1;
					break;
				}

				cout << "\nPLAYER 1 turn: ";
				board_file.getting_move('X');						//getting move for first player.

				if (ticTacToe::exit == -1)					//player exits check
				{
					break;
				}

				cout << board_file;
				if (board_file.win_check() == true)
				{
					cout << "\n\n  -[ Player 1 Wins ]- \n";
					win = 1;
					break;
				}
				if (board_file.draw_check() == true)					//draw check
				{
					cout << "\n\n *********** -[ >> Draw << ]- **********\n";
					win = 1;
					break;
				}
			}
			if (win != 1)
			{
				char save;
				cout << "\n\nPress s to save the game or press any key to exit: \n";
				cin >> save;
				if (save == 's' || save == 'S')
				{
					board_file.savedata(board_file);						//save data in file
					cout << "\n********Game Save Successfully. *********";
				}
				else
				{
					cout << "\n********** EXITED **********\n";
				}
			}
		}

	}
	else if (initial_choice == 2)
	{
		int win = 0;
		int choice = 0;
		cout << "\n*****  1: Default board size: *****";
		cout << "\n*****  2: Make your own board: *****";

		cout << "\nEnter choice:    ";
		cin >> choice;
		while (choice != 1 && choice != 2)							//if input is invalid then enter again
		{
			cout << "\n.........Invalid choice.........Enter again:  ";
			cin >> choice;
		}

		if (choice == 1)
		{
			ticTacToe board_1;								//default board
			cout << board_1;
			cout << "\n^^^^^^^^^^^^ GAME STARTED ^^^^^^^^^^^^^^\n";
			cout << "\n^^^^^^^ PLAYER 1 character   (X) ^^^^^^^^";
			cout << "\n^^^^^^^ Player 2 character   (O) ^^^^^^^^";
			while (choice != -1)
			{
				char temp = '\0';
				cout << "\nPLAYER 1 turn: ";
				board_1.getting_move('X');						//getting move for first player.

				if (ticTacToe::exit == -1)				//player exits check
				{
					break;
				}

				cout << board_1;
				if (board_1.win_check() == true)
				{
					cout << "\n\n  -[ Player 1 Wins ]- \n";
					win = 1;
					break;
				}
				if (board_1.draw_check() == true)					//draw check
				{
					cout << "\n\n *********** -[ >> Draw << ]- **********\n";
					win = 1;
					break;
				}

				cout << "\nPLAYER 2 turn: ";
				board_1.getting_move('O');					//getting move for second player.

				if (ticTacToe::exit == -1)					//player exits check
				{
					break;
				}

				cout << board_1;
				if (board_1.win_check() == true)
				{
					cout << "\n\n  -[ Player 2 Wins ]- \n";
					win = 1;
					break;
				}
				if (board_1.draw_check() == true)					//draw check
				{
					cout << "\n\n *********** -[ >> Draw << ]- **********\n";
					win = 1;
					break;
				}
			}
			if (win != 1)
			{
				char save;
				cout << "\n\nPress s to save the game or press any key to exit: \n";
				cin >> save;
				if (save == 's' || save == 'S')
				{
					board_1.savedata(board_1);							//save data in file
					cout << "\n********Game Save Successfully. *********";
				}
				else
				{
					cout << "\n********** EXITED **********\n";
				}
			}
		}
		else if (choice == 2)
		{
			int n = 0;
			cout << "\nEnter size of your Board (greater than or equal to 3): ";
			cin >> n;
			while (n < 3)
			{
				cout << "\n****** You enterend InValid input: ****** Enter again: ";
				cin >> n;
			}
			ticTacToe board_2(n);							//paramitized board
			cout << board_2;
			cout << "\n^^^^^^^^^^^^ GAME STARTED ^^^^^^^^^^^^^^\n";
			cout << "\n^^^^^^^ PLAYER 1 character   (X) ^^^^^^^^";
			cout << "\n^^^^^^^ Player 2 character   (O) ^^^^^^^^";
			while (choice != -1)
			{
				char temp = '\0';
				cout << "\nPLAYER 1 turn: ";
				board_2.getting_move('X');						//getting move for first player.

				if (ticTacToe::exit == -1)					//player exits check
				{
					break;
				}

				cout << board_2;
				if (board_2.win_check() == true)
				{
					cout << "\n\n  -[ Player 1 Wins ]- \n";
					win = 1;
					break;
				}
				if (board_2.draw_check() == true)					//draw check
				{
					cout << "\n\n *********** -[ >> Draw << ]- **********\n";
					win = 1;
					break;
				}

				cout << "\nPLAYER 2 turn: ";
				board_2.getting_move('O');					//getting move for second player.

				if (ticTacToe::exit == -1)				//player exits check
				{
					break;
				}

				cout << board_2;
				if (board_2.win_check() == true)
				{
					cout << "\n\n  -[ Player 2 Wins ]- \n";
					win = 1;
					break;
				}
				if (board_2.draw_check() == true)					//draw check
				{
					cout << "\n\n *********** -[ >> Draw << ]- **********\n";
					win = 1;
					break;
				}
			}
			if (win != 1)
			{
				char save;
				cout << "\n\nPress s to save the game or press any key to exit: \n";
				cin >> save;
				if (save == 's' || save == 'S')
				{
					board_2.savedata(board_2);						//save data in file
					cout << "\n********Game Save Successfully. *********";
				}
				else
				{
					cout << "\n********** EXITED **********\n";
				}
			}
		}
	}
	else if (initial_choice == -1)
	{
		cout << "\n\n...........Game Exited............\n";
	}
}

int main()
{
	menu();
}