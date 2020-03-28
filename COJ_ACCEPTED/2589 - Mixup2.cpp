/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 2589 - Mixup2
	Online Judge: COJ
	Idea: DP + BitMask
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
const int lim = 17;

int N, K;

ll dp[lim][1<<lim];
int arr[lim];

ll DynamicProgramming(int idx, int mask)
{
    // if all taken
    if(mask == (1<<N)-1)
        return 1;

    if(dp[idx][mask] != -1)
        return dp[idx][mask];

    dp[idx][mask] = 0;

    for(int i = 0; i < N; i++)
    {
        // if not taken
        if(((1<<i)&mask) == 0 && abs(arr[i] - arr[idx]) > K)
        {
            ll k = DynamicProgramming(i, mask|(1<<i));
            dp[idx][mask]+= k;
        }
    }

    // return
    return dp[idx][mask];
}



void solve()
{
    cin >> N >> K;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i = 0; i < N; i++)
            for(int k = 0; k < (1<<N); k++)
                dp[i][k] = -1;

    ll answ = 0;
    for(int i = 0; i < N; i++)
    {
        ll k = DynamicProgramming(i, (1<<i));
        answ+= k;
    }

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
