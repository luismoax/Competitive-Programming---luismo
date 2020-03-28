/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3021 - Perimeter
	Online Judge: COJ
	Idea: BFS. Run a BFS on the cells where no bales are, always leavin an extra row and columm to fill all the sourrounding aree
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 100 + 2;

int N, ai, bi;
bool mt[200][200];
bool visited[200][200];

bool valid(int x, int y)
{
	return x >= 0 && x <= lim && y >= 0 && y <= lim;
}

int xs[]{1, -1, 0, 0};
int ys[]{0, 0, 1, -1};

struct pr
{
	int x, y;
	pr(){}
	pr(int xx, int yy){x = xx; y = yy;}
};



void solve()
{
	cin >> N;
	// reading hay bales
	for(int i = 0; i < N; i++)
	{
		cin >>ai >> bi;
		mt[ai][bi] = true;
	}

	// BFS
	queue<pr> q;
	q.push(pr(0, 0));
	visited[0][0] = true;

	int answ = 0;

	while(q.size() > 0)
	{
		//cout << q.size() << "\n";
		pr curr = q.front(); // current point
		q.pop();

		// for each adjacent
		for(int i = 0; i < 4; i++)
		{
			int nx = xs[i] + curr.x;
			int ny = ys[i] + curr.y;
			// if is a valid cell
			if(valid(nx, ny) && !visited[nx][ny])
			{
				if(mt[nx][ny])
					answ++;
				else
				{
					q.push(pr(nx, ny));
					visited[nx][ny] = true;
				}
			}
		}
	}
	cout << answ << "\n";
}

int main()
{
	if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
		// freopen("d:\\lmo.out","w",stdout);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}

