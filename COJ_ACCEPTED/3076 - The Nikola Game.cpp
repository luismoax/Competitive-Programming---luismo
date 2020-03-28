/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3076 - The Nikola Game
	Online Judge: COJ
	Idea: DP.
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
const ll infinite = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 2e3 + 7;

int N;
int arr[lim];

int dp[lim][lim];
int mark[lim][lim];

int DynamicProgramming(int idx, int stpLen)
{
    if(idx < 1 || idx > N)
        return infinite;

    // if a calculated state
    if(mark[idx][stpLen])
        return dp[idx][stpLen];

    // if not the first cell (already calculated) and zero steps
    if(stpLen == 0)
        return infinite;

    int answ = infinite;
    // to the front
    int k = DynamicProgramming(idx + stpLen, stpLen);
    answ = min(answ, k);
    // to the rear
    k = DynamicProgramming(idx - stpLen, stpLen - 1);
    answ = min(answ, k);
	// update the state
    dp[idx][stpLen] = answ + arr[idx];
	// mark the state as calculated
    mark[idx][stpLen] = true;
    return dp[idx][stpLen];
}


void solve()
{
    cin >> N;
    // reading integers
    for(int i = 0; i < N; i++)
        cin >> arr[i + 1];

    // base
    dp[1][0] = arr[1];
    dp[2][1] = arr[2];
    mark[1][0] = mark[2][1] = true;

    int answ = infinite;
    for(int i = N; i > 0; i--)
    {
        int k = DynamicProgramming(N, i);
		// updating the answer
        if(k < answ)        
            answ = k;
        
    }
	// printing the answer
    cout << answ;
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
