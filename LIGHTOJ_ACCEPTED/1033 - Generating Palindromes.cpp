/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1033 - Generating Palindromes
	Online Judge: LightOJ
	Idea: Dynamic Programming
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
const int lim = 1e2 + 7;

int tc;
string str;

int dp[lim][lim];
int mark[lim][lim];

int DynamicProgramming(int le, int ri)
{
    if(mark[le][ri])
        return dp[le][ri];

    if(le >= ri)
        return 0;

    if(str[le] == str[ri])
    {
        int a1 = DynamicProgramming(le + 1, ri - 1);
        dp[le][ri] = a1;
        mark[le][ri] = true;
    }
    else
    {
        int a1 = DynamicProgramming(le + 1, ri) + 1;
        int a2 = DynamicProgramming(le, ri - 1) + 1;

        dp[le][ri] = min(a1, a2);
        mark[le][ri] = true;
    }
    return dp[le][ri];
}

void reset()
{
    for(int i = 0; i < lim; i++)
    {
        for(int j = 0; j < lim; j++)
            dp[i][j] = mark[i][j] = 0;
    }
}

void solve()
{
    cin >> tc;
    int cs = 1;
    while(tc-->0)
    {
        reset();
        cin >>str;

        int answ = DynamicProgramming(0, str.size() - 1);

        cout << "Case " << cs << ": " << answ << "\n";
        cs++;
    }
}

int main()
{

	solve();
}
