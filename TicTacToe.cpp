#include "TicTacToe.h";
#include <iostream>
#include <fstream>
using namespace std;

int  ticTacToe::counter = 0;					//used  to evaluate the player turn after load game 
int ticTacToe::exit = 0;			//use to check if player wants to exit game or not

ticTacToe::ticTacToe()						//default constructor
{
	size = 3;
	arr = new char* [size];						//formation of deafult 3x3 board
	for (int i = 0; i < size; i++)
	{
		arr[i] = new char[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = '-';					//default storage of character  " - "
		}
	}
}

ticTacToe::ticTacToe(int N)						//parametized constructor:
{
	size = N;
	arr = new char* [size];						//input board size from user  
	for (int i = 0; i < size; i++)
	{
		arr[i] = new char[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = '-';					//default storage of character " - "
		}
	}
}

ticTacToe::ticTacToe(const ticTacToe& board)			//copy constructor
{
	size = board.size;						//copy size;
	arr = new char* [size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = new char[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = board.arr[i][j];					//copy data " - "
		}
	}
}

ostream& operator<<(ostream& out, const ticTacToe& board)				//output of board
{
	cout << endl;
	for (int i = 0; i < board.size; i++)
	{
		for (int j = 0; j < board.size; j++)
		{
			cout << " " << board.arr[i][j] << " ";
			if (j != board.size - 1)
			{
				cout << "| ";
			}
		}
		cout << endl;
		if (i != board.size - 1)
		{
			for (int k = 0; k < (board.size * 3 + board.size); k++)
			{

				cout << "~";
			}
		}

		cout << endl;
	}
	return out;
}

void ticTacToe::check_move(int& check)							//move validation check
{
	while (check <= 0 || check > size)
	{
		cout << "\n............Invalid input...........Enter again:  ";
		cin >> check;
	}
}

void ticTacToe::getting_move(char ch)						//getting move
{
	int row = 0, col = 0;
	bool flag = false;
	while (!flag)
	{
		cout << "\nEnter row #1,2,3...  |:| or -1 to exit:  ";
		cin >> row;
		if (row == -1)								//if player exits during game
		{
			ticTacToe::exit = -1;
			break;
		}
		check_move(row);									//move validation check
		row--;
		cout << "\nEnter column #1,2,3... : ";
		cin >> col;
		check_move(col);
		col--;
		if (arr[row][col] == '-')
		{
			flag = true;
		}
		else
		{
			cout << "\n************  Player already use this area ************* Enter again\n";
		}

	}
	if (ticTacToe::exit != -1)
	{
		arr[row][col] = ch;
	}
}

bool ticTacToe::win_check()
{
	int count = 1;
	for (int i = 0; i < size - 1; i++)					//forward diagonal check
	{
		if (arr[i][i] == arr[i + 1][i + 1] && arr[i][i] != '-')
			count++;
	}
	if (count == size)
		return true;

	count = 1;
	for (int i = 0; i < size - 1; i++)					//backward diagonal check
	{
		if (arr[i][size - 1 - i] == arr[i + 1][size - 2 - i] && arr[i][size - 1 - i] != '-')
			count++;
	}
	if (count == size)
		return true;

	for (int i = 0; i < size; i++)						//rows check
	{
		count = 1;
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[i][j] == arr[i][j + 1] && arr[i][j] != '-')
				count++;
		}
		if (count == size)
			return true;
	}

	for (int i = 0; i < size; i++)						//columns check
	{
		int count = 1;
		for (int j = 0; j < size - 1; j++)
		{
			if (arr[j][i] == arr[j + 1][i] && arr[j][i] != '-')
				count++;
		}
		if (count == size)
			return true;
	}

	return false;
}

bool ticTacToe::draw_check()
{
	int count_draw = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i][j] != '-')
				count_draw++;
		}
	}
	if (count_draw == size * size)
		return true;
	else
		return false;
}

int ticTacToe::get_size()
{
	return size;
}

char ticTacToe::get_arr(int a, int b)
{
	return arr[a][b];
}

ofstream& operator<<(ofstream& fout, ticTacToe& board)
{
	fout << board.get_size();
	for (int i = 0; i < board.get_size(); i++)
	{
		for (int j = 0; j < board.get_size(); j++)
		{
			fout << board.get_arr(i, j);
		}
	}
	return fout;
}

void ticTacToe::savedata(ticTacToe& board)
{
	ofstream fout;
	fout.open("BasicGame.txt");
	fout << board;
	fout.close();
}

ifstream& operator>>(ifstream& fin, ticTacToe& board)
{

	for (int i = 0; i < board.size; i++)					//deallocate old board
	{
		delete[]board.arr[i];
	}
	delete[]board.arr;
	fin >> board.size;
	board.arr = new char* [board.size];						//formation of new  board
	for (int i = 0; i < board.size; i++)
	{
		board.arr[i] = new char[board.size];
	}
	for (int i = 0; i < board.size; i++)
	{
		for (int j = 0; j < board.size; j++)
		{
			fin >> board.arr[i][j];					//input from file
			if (board.arr[i][j] == '-')
				ticTacToe::counter++;
		}
	}
	return fin;
}

void ticTacToe::readdata(int& count, ticTacToe& board)
{
	int s = 0;
	ifstream fin;
	fin.open("BasicGame.txt");
	if (!fin)
	{
		cout << "\n\nFile Not Exist: \n";
	}
	else
	{
		fin >> board;
		count = ticTacToe::counter;
	}
	fin.close();
}

ticTacToe::~ticTacToe()								//deallocation of board
{
	for (int i = 0; i < size; i++)
	{
		delete[]arr[i];
	}
	delete[]arr;
	arr = NULL;
	cout << "\n~Destructor Called: ";
}