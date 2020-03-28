/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1395 - Big Number II
	Online Judge: COJ
	Idea: Use a property of logs
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ld long double
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e7 + 1;

ll N, tc;

int dp[lim];

void preProcess()
{
    double sum = 0;
    int idx = 0;
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= lim; i++)
    {
        sum += log10(i);

        dp[i] = floor(sum) + 1;
    }
}

void solve()
{
    preProcess();

    cin >> tc;
    while(tc-- > 0)
    {
        cin >> N;
        cout << dp[N] << endl;
    }
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
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

	fastIO();

	solve();
}
