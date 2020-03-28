/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2606 - Attacking Rooks
	Online Judge: COJ
	Idea: Min Vertex Cover Variation
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e2 + 7;
const int lim2 = 1e4 + 7;

int N;
string str;
int board[lim][lim];

// Auxiliars
int boardHor[lim][lim];
int boardVer[lim][lim];


// >> GRAPH
vector<int> adj[lim2];
// << GRAPH

void printH()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cout << boardHor[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}


void printV()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
            cout << boardVer[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}


// >> KUHN
int fsz = 0; // first set Size [1 -> fsz]
int cnt = 0;

int visited[lim2];
int match[lim2];

bool findIncremental(int v, int tm)
{
    if(visited[v] == tm)
        return false;

    visited[v] = tm;

    // for each
    for(int i = 0; i < adj[v].size(); i++)
    {
        int nxt = adj[v][i];
        // if not matched or can be rematched
        if(match[nxt] == 0 || findIncremental(match[nxt], tm))
        {
            match[nxt] = v;
            return true;
        }
    }
return false;
}

int Kuhn()
{
    for(int i = 1; i <= fsz; i++)
        findIncremental(i, i);

    int ret = 0;
    for(int i = fsz + 1; i <= cnt; i++)
        if(match[i] != 0)
            ret++;
    return ret;
}

// << KUHN

void solve()
{
    cin >> N;
    // reading the board
    for(int r = 0; r < N; r++)
    {
        cin >> str;
        for(int c = 0; c < str.length(); c++)
        {
            if(str[c] == 'X')
                board[r][c] = 1;

            if(board[r][c] == 0)
            {
                // if is the first column or the previous column has a pawn
                if(c == 0 || board[r][c - 1] == 1)
                    cnt++;
                // set the value
                boardHor[r][c] = cnt;
            }
        }
    }

    // setting the size of the first set
    fsz = cnt;
    //
    for(int c = 0; c < N; c++)
    {
        for(int r = 0; r < N; r++)
        {
            // if is the first row
            if(board[r][c] == 0)
            {
                // if is the first row or the previous cell has a pawn
                if(r == 0 || board[r - 1][c] == 1)
                    cnt++;
                // setting the edge
                int le = boardHor[r][c];
                adj[le].push_back(cnt);
            }
        }
    }

    int answ = Kuhn();

    cout << answ;
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
