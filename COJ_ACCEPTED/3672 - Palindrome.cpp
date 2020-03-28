/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3672 - Palindrome
	Online Judge: COJ
	Idea: 
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 5e3 + 7;

int dp[lim][lim];
string str;

void buildDP()
{
    // lenght of the string
    int len = str.length();
    // for each possible size of a substring
    for(int sz = 2; sz <= len; sz++)
    {
        // for each possibe starting possition
        for(int i = 0; i + sz - 1 < len; i++)
        {
            // right bound
            int j = i + sz - 1;
			
			// best value
            int mn = INFINITY;
            // if both extremes match
			// dp[i][j] = min(dp[i + 1][j -1], min(dp[i][j - 1] + 1 , dp[i + 1][j]))
			// if they don't:
			// dp[i][j] = min(dp[i][j - 1] + 1 , dp[i + 1][j])
            if(str[i] == str[j])
            {
                if(i == j - 1)
                    mn = 0;
                else mn = dp[i + 1][j - 1];
            }
			
            // min(dp[i][j - 1] + 1 , dp[i + 1][j])
            int aux1 = dp[i][j - 1] + 1;
            int aux2 = dp[i + 1][j] + 1;
            // updating minnumun value
            mn = min(mn, min(aux1, aux2));

            dp[i][j] = mn;
        }
    }
}

int N;
void solve()
{
    cin >> N >> str;
    buildDP();
    cout << dp[0][str.length() - 1];
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
