/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3529 - Cómo Ver Más Juegos
	Online Judge: COJ
	Idea: DP + Sorting Searching
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 30000 + 5;

int N, b, f;

struct game
{
    int beg, fin;
    game(){}
    game(int b, int f){beg = b; fin = f;}
};
bool cmp(game a, game b)
{
    return a.fin < b.fin;
}
// to store games
vector<game> v;
//
int dp[lim];

void solve()
{
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> b >> f;
        v.push_back(game(b + 1, f + 1));
    }
    // sort em all
    sort(v.begin(), v.end(), cmp);

    int currentGame = 0;

    for(int i = 1; i < lim; i++)
    {
        dp[i] = dp[i - 1];

        while(currentGame < v.size() && v[currentGame].fin == i)
        {
			// watch it
            int wtch = dp[v[currentGame].beg - 1]; 
			// update DP
            if(wtch + 1 > dp[i])
                dp[i] = wtch + 1;
			// move to the next game
            currentGame++;
        }
    }
    cout << dp[lim - 1];
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
