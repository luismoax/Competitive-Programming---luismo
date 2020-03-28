/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2762 - Cow Art
	Online Judge: COJ
	Idea: Two BFS over the matrix
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf

using namespace std;

typedef pair<int, int> pii;

const int lim = 1e3 + 7;

int N;
string str;


int mt[lim][lim];
bool visited[lim][lim];

int xs[] = {0, 0, 1, -1};
int ys[] = {1, -1, 0, 0};

bool validCell(int xx, int yy)
{
    return xx >= 0 && xx < N && yy >= 0 && yy < N;
}


void BFS(pair<int, int> iniPos)
{
    int tag = mt[iniPos.first][iniPos.second];
    visited[iniPos.first][iniPos.second] = true;

    queue<pii> q;
    //
    q.push(iniPos);

    // Perform BFS
    while(q.size() > 0)
    {
        pii curr = q.front(); q.pop();

        // for each adjacent cell
        for(int i = 0; i < 4; i++)
        {
            int xx = curr.first + xs[i];
            int yy = curr.second + ys[i];

            if(validCell(xx, yy) && !visited[xx][yy] && mt[xx][yy] == tag)
            {
                q.push(make_pair(xx, yy));
                visited[xx][yy] = true;
            }
        }
    }
}

int regions()
{
    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(!visited[i][j])
            {
                BFS(make_pair(i, j));
                cnt++;
            }
        }
    }
    return cnt;
}

void printMt()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++) cout << mt[i][j] << " ";
        cout << endl;
    }
}

void solve()
{
    cin >> N;
    // reading matrix
    for(int i = 0; i < N; i++)
    {
        cin >> str;
        for(int j = 0; j < N; j++)
        {
            mt[i][j] = str[j] - 'A';
        }
    }

    // calculate the human regions
    int regHuman = regions();

    // reset the matrix of visited and set an equal value for Red or Green cells
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            // reset the visited matrix
            visited[i][j] = false;
            // if red-green
            if(mt[i][j] > 1)
                mt[i][j] = 7;
        }

    // calculate the number of cow regions
    int regCow = regions();

    cout << regHuman << " " << regCow;
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
