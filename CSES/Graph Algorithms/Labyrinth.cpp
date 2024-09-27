/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: Labyrinth
	Link: https://cses.fi/problemset/task/1193
	Online Judge: CSES
	Idea: Full use of a BFS on a matrix, keeping track of the previous square visited for each step.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define i64 unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define M_PI 2.0 * acos(0)
#define endl "\n"
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e18;
const int mod = 1e9 + 7;
const int lim = 1e3 + 5;


int N, M;


int mt[lim][lim];
// Parenthood matrix
pii pi[lim][lim];
// Distance 
int dist[lim][lim];
// Visited
bool visited[lim][lim];

// movement arrays
int xs [4] = {1, -1, 0, 0};
int ys [4] = {0, 0, -1, 1};

// starting position
pii st;
// finishing position
pii fin;

// Checks if a cell is valid to be visited
bool valid(int x, int y)
{
	return x >= 0 && x < N && y >= 0 && y < M;
}

// Function to determine which movement was made from position "from" to position "to"
char invMovement(pii from, pii to)
{
	if(from.first == to.first)
	{
		if(from.second > to.second)		
			return 'L';		
		return 'R';
	}
	else
	{
		if(from.first > to.first)
			return 'U';
		return 'D';
	}
}

void solve()
{
	cin >> N >> M;
	string str;
	for(int i = 0; i < N; i++)
	{
		cin >> str;
		for(int j = 0; j < M; j++)
		{
			if(str[j] == '#')
				mt[i][j] = 1;
			if(str[j] == 'A')
			{
				st.first = i;
				st.second = j;
			}
			else if(str[j] == 'B')
			{
				fin.first = i;
				fin.second = j;
			}
		}
	}

	// BFS

	// Set starting point's values
	visited[st.first][st.second] = true;
	dist[fin.first][fin.second] = -1;


	queue<pii> q;
	q.push(st);

	while(q.size() > 0)
	{
		pii curr = q.front(); q.pop();

		int x = curr.first;
		int y = curr.second;


		for(int i = 0; i < 4; i++)
		{
			int nx = x + xs[i];
			int ny = y + ys[i];

			if(valid(nx, ny) && mt[nx][ny] != 1 && visited[nx][ny] == false)
			{
				visited[nx][ny] = true;
				q.push(mkp(nx, ny));
				pi[nx][ny] = curr;
				dist[nx][ny] = dist[x][y] + 1;
			}
		}		
	}
	// BFS


	int d = dist[fin.first][fin.second];

	if(d == -1)
	{
		cout << "NO" << endl;
		return;
	}
	
	string answ;

	stack<char> stk;

	pii curr = fin;

	while(curr.first != st.first || curr.second != st.second)
	{
		pii fr = pi[curr.first][curr.second];

		char c = invMovement(fr, curr);
		stk.push(c);

		curr = fr;
	}

	while(stk.size() > 0)
	{
		char c = stk.top(); stk.pop();
		answ += c;
	}

	cout << "YES" << endl << d << endl << answ << endl;
}
 
void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}
 
void IO()
{
	const char * route = "c:\\Users\\LUISMO\\lmo.in";

	if(fopen(route, "r") != NULL)
	{
		freopen(route,"r",stdin);
	}
}
 
int main()
{
	IO();
 
	fastIO();
 
	solve();
}