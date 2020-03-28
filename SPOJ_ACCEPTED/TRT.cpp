/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: TRT
	Online Judge: SPOJ
	Idea: DP1. dp[le][ri], the greatest earning after taking "le" elements from the left and "ri" elements from the right
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
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 2e3 + 7;

int N;

int vi[lim];

int dp[lim][lim];
bool mark[lim][lim];

int DynamicProgramming(int le, int ri)
{
    int age = le + (N - ri);

    if(age == N)
        return N * vi[le];

    if(mark[le][ri])
        return dp[le][ri];

    int a1 = DynamicProgramming(le + 1, ri) + (vi[le]*age);
    int a2 = DynamicProgramming(le, ri - 1) + (vi[ri]*age);

    dp[le][ri] = max(a1, a2);
    mark[le][ri] = true;

    return dp[le][ri];
}


void solve()
{
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> vi[i+1];

    int answ = DynamicProgramming(1, N);

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
