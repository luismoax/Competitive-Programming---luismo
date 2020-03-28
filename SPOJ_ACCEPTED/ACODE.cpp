/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: ACODE
	Online Judge: https://www.spoj.com/problems/ACODE/
	Idea: DP
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
const ll inf = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 2e5 + 7;


ll dp[lim];
ll arr[lim];
string str;

ll DynamicProgramming()
{
    for(int i = 0; i < str.length(); i++)
    {
        arr[i + 1] = str[i] - '0';
        dp[i] = 0;
    }
    dp[str.length()] = 0;

    // perform DP
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= str.length(); i++)
    {
        int aux = 10 * (arr[i - 1]) + arr[i];

        if(aux == 10 || aux == 20)
            dp[i - 1] -= dp[i - 3];

        if(arr[i] != 0)
            dp[i] += dp[i - 1];

        if(aux <= 26 && aux >= 10)
            dp[i]+= dp[i - 2];
    }

    return dp[str.length()];
}

void solve()
{
    cin >> str;
    while(str != "0")
    {

        ll answ = DynamicProgramming();

        cout << answ << "\n";

        cin >> str;
    }
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
