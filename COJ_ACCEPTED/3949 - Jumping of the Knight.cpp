/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3949 - Jumping of the Knight
	Online Judge: COJ
	Idea: Easy BFS over the table.
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;

typedef pair<int, int> pii;

int xx1, yy1, xx2, yy2;

bool isValid(int x, int y)
{
    return x >= 1 && x <= 8 && y >=1 && y <= 8;
}

// moveing up arrays
int xs[] = {1, 1, 2, 2};
int ys[] = {-2, 2, 1, -1};

// matrix
bool mt[10][10];

void solve()
{
    cin >> xx1 >> yy1 >> xx2 >> yy2;

    // queue
    queue<pii> q;

    if(!isValid(xx1, yy1))
    {
        cout << "no\n"; return;
    }

    // push the initial position
    q.push(make_pair(xx1, yy1));
    mt[xx1][yy1] = true;

    while(q.size() > 0)
    {
        pii curr = q.front(); q.pop();
        // for each possible adjancet (in horse walk)
        for(int i = 0; i < 4; i++)
        {
            int xx = curr.first + ys[i];
            int yy = curr.second + xs[i];
            // if is a valid cell to move
            if(isValid(xx, yy) && !mt[xx][yy])
            {
                // push in the queue
                q.push(make_pair(xx, yy));
                // mark as taken
                mt[xx][yy] = true;
            }
        }
    }

    if(mt[xx2][yy2])
        cout << "yes\n";
    else cout << "no\n";
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
