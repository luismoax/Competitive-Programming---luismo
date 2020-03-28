/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3979 - Checking valid sequences
	Online Judge: COJ
	Idea: DP. dp[i][j], claims if after setting symbols between the first i elements the 
	remainder j can be achieved
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e3 + 7;

int N, M;
int arr[lim];

bool dp[lim][lim];


void solve()
{
    cin >> N >> M;
    // reading integers
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        arr[i] = arr[i] % M;
    }

    dp[0][0] = true;

    // for each element
    for(int i = 1; i <= N; i++)
    {
        // for each possible remainder
        for(int rem = 0; rem < M; rem++)
        {
            if(dp[i - 1][rem])
            {
                int nRem = (rem + arr[i]) % M;
                dp[i][nRem] = true;

                nRem = (rem - arr[i] + M) % M;
                dp[i][nRem] = true;
            }
        }
    }


    // print answer
    if(dp[N][0])
        cout << "valid\n";
    else cout << "invalid\n";
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
