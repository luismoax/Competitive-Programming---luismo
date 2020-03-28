/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem:
    Online Judge: COJ
    Idea: Backtrack
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
int marks[21][11];

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
					marks[row][col] = true; // mark as placed
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

			if(aux > 0)
			{
				if(mark[aux])
					return false;
				else mark[aux] = true;
			}
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

bool solveSudoku(int x, int y)
{
	if(x == 9)
		return true;

	// if marked -> go next
	if(marks[x][y])
	{
		int ny = y + 1;
		int nx = x;
		if(ny == 9)
		{
			ny = 0; nx++;
		}
		return solveSudoku(nx, ny);
	}
	else
	{
		// for each possible number to place
		for(int i = 1; i <= 9; i++)
		{
			sudoku[x][y] = i;
			// check cell
			if(checkCell(x, y))
			{
				int ny = y + 1;
				int nx = x;
				if(ny == 9)
				{
					ny = 0;
					nx++;
				}
				bool flag = solveSudoku(nx, ny);

				if(flag)
					return true;
			}
		}
		sudoku[x][y] = 0;
		return false;
	}
}

void solve()
{
	readSudoku();

	solveSudoku(0, 0);

	printSudoku();
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}
