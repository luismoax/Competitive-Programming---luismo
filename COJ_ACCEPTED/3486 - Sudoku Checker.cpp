/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem:
    Online Judge: COJ
    Idea: Ad-Hoc.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

int sudoku[21][11];

void printSudoku()
{
	// printing files
	for(int r = 0; r < 9; r++)
	{
		if(r > 0 && r % 3 == 0)
			cout << "------+-------+------\n";

		for(int c = 0; c < 9; c++)
		{
			if(c > 0)
			{
				if(c % 3 == 0)
					cout << " | ";
				else cout << " ";
			}
			cout << sudoku[r][c];
		}
		cout << "\n";
	}
}

// reading sudoku
void readSudoku()
{
	string str;
	int row = 0, col = 0;
	for(int r = 0; r < 11; r++)
	{
		// read the entire line
		getline(cin, str);
		if( r != 3 && r != 7)
		{
			col  = 0;

			for(int i = 0; i < str.length(); i++)
			{
				int diff = str[i] - '0';
				if(diff >= 1 && diff <= 9)
				{

					sudoku[row][col++] = diff;
				}
				else if(diff == '*' - '0')
					sudoku[row][col++] = 0;
			}

			row++;
		}
	}
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			if(sudoku[i][j] == -6)
				sudoku[i][j] = 0;
}

bool checkCell(int x, int y)
{
	// check row
	for(int c = 0; c < 9; c++)
		if(c != y && sudoku[x][c] == sudoku[x][y])
			return false;
	// check col
	for(int r = 0; r < 9; r++)
		if(r != x && sudoku[r][y] == sudoku[x][y])
			return false;
	// check subtable
	int stR = (x / 3) * 3;
	int stC = (y / 3) * 3;

	bool mark[10] = {0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0};
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
		{
			int aux = sudoku[stR + i][stC + j];
			if(mark[aux])
				return false;
			mark[aux] = true;
		}
	return true;
}

bool checkSudoku()
{
	for(int r = 0; r < 9; r++)
		for(int c= 0; c < 9; c++)
			if(!checkCell(r, c))
				return false;
	return true;
}

void solve()
{
	readSudoku();

	if(checkSudoku())
		cout << "CORRECT\n";
	else cout << "WRONG\n";

	// printSudoku();
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
