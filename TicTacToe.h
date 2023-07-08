#pragma once

#include <iostream>
#include <fstream>
using namespace std;

class ticTacToe
{
	char** arr;
	int size;
public:
	static int exit;
	static int counter;
	ticTacToe();							//default constuctor
	ticTacToe(int N);						//paramitized constuctor
	ticTacToe(const ticTacToe&);			//copy constuctor
	friend ostream& operator<<(ostream&, const ticTacToe&);				//ouput 
	void getting_move(char ch);
	void check_move(int& check);
	bool win_check();
	bool draw_check();
	int get_size();
	char get_arr(int a, int b);
	friend ofstream& operator<<(ofstream&, const ticTacToe&);				//write in file
	friend ifstream& operator>>(ifstream&, ticTacToe&);					//read from file
	void savedata(ticTacToe& board);
	void readdata(int& count, ticTacToe& board);
	~ticTacToe();							//destructor
};
