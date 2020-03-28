/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3194 - Containers at the Harbor
	Online Judge: COJ
	Idea: DP + Bitmask. Nice
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

typedef pair<int, int> pii;
const ll inf = 1e9 + 3;
const int mod = 1e9 + 7;
const int lim = 20 + 7;

int N, K;

int mt[lim][lim];
int cumul[lim][lim];

int dp[lim][lim][(1<<11)];
bool mark[lim][lim][(1<<11)];


int query(int rw, int i, int j)
{
    if(i == 0)
        return cumul[rw][j];
    return cumul[rw][j] - cumul[rw][i - 1];
}


int DynamicProgramming(int beg, int fin, int mask)
{
    if(mask == 0)
        return 0;

    int ab = 0; // active bits
    int lastAb = -1;
    for(int i = 0; i < K; i++)
        if(((1<<i)&mask) > 0)
        {
            ab++;
            lastAb = i;
        }
	// if there is only one crane active
    if(ab == 1)
    {
        dp[beg][fin][mask] = query(lastAb, beg, fin);
		mark[beg][fin][mask] = true;

		return dp[beg][fin][mask];
    }


    if(mark[beg][fin][mask])
        return dp[beg][fin][mask];

    dp[beg][fin][mask] = inf;

    // for each possible crane
    for(int i = 0; i < K; i++)
    {
        // if i-th crane is active
        if( (mask&(1<<i)) > 0)
        {
            //
            for(int j = fin - 1; j >= beg; j--)
            {
                int q = query(i , j + 1, fin);

                int dypr = DynamicProgramming(beg, j, (mask^(1<<i)));

                dp[beg][fin][mask] = min(q + dypr, dp[beg][fin][mask]);
            }
        }
    }

    mark[beg][fin][mask] = true;
    return dp[beg][fin][mask];
}



void solve()
{
    cin >> N >> K;
    // reading matrix
    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> mt[i][j];
            cumul[i][j] = mt[i][j];
            if(j > 0)
                cumul[i][j] += cumul[i][j-1];
        }
    }

    int answ = inf;
    for(int i = 1; i < (1<<K); i++)
        answ = min(answ, DynamicProgramming(0, N - 1, i));

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
