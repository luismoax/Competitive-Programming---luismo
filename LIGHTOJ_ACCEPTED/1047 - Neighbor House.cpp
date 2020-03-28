/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1047 - Neighbor House
	Online Judge: LightOJ
	Idea: Easy Dynamic Programming
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
const int lim = 100 + 7;

int tc, N;
int mt[lim][3];
int dp[lim][3];

void solve()
{
    cin >> tc;
    int cs = 1;
    while(cs <= tc)
    {

        cin >> N;
        // reading matrix
        for(int i = 0; i < N; i++)
        {
            cin >> mt[i][0] >> mt[i][1] >> mt[i][2];
            if(i == 0)
            {
                for(int j = 0; j < 3; j++)
                    dp[i][j] = mt[i][j];
            }
            else
            {
                dp[i][0] = mt[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
                dp[i][1] = mt[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
                dp[i][2] = mt[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
            }
        }

        int mn = mod;
        for(int i = 0; i < 3; i++)
            mn = min(mn, dp[N - 1][i]);


        cout << "Case " << cs << ": " << mn << "\n";
        cs++;
    }
}

int main()
{

	solve();
}
