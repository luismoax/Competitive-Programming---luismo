/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 4087 - Gorgeous Signs
	Online Judge: COJ
	Idea: DP. Top-Down
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
const int lim = 103;

int tc, N, M, K;

int mt[lim][lim];

// DP
ll dp[lim][lim][lim][2];
bool mark[lim][lim];

void DynamicProgramming(int r, int c)
{
    if(r < 1 || c < 1)
        return;

    if(mark[r][c])
        return;

    DynamicProgramming(r-1, c);
    DynamicProgramming(r, c-1);

	// border cases - treated as especial
    if(r == 1)
        dp[r][c][0][1] = dp[r][c-1][0][1] + mt[r][c];
    if(c == 1)
        dp[r][c][0][0] = dp[r-1][c][0][0] + mt[r][c];

	// current value in the matrix
    int aux = mt[r][c];

    if(r > 1 && c > 1)
    {
        for(int i = 1; i <= K; i++)
        {
            if(dp[r-1][c][i][0] != -1 || dp[r-1][c][i-1][1] != -1)
                dp[r][c][i][0] = max(dp[r-1][c][i][0], dp[r-1][c][i-1][1]) + aux;
            else dp[r][c][i][0] = -1;

            if(dp[r][c-1][i][1] != -1 || dp[r][c-1][i-1][0] != -1)
                dp[r][c][i][1] = max(dp[r][c-1][i][1], dp[r][c-1][i-1][0]) + aux;
            else dp[r][c][i][1] = -1;
        }
    }
    // mark the state as
    mark[r][c] = true;
}

void solve()
{
    cin >> tc;
    // reading test cases
    while(tc-- > 0)
    {
        cin >> N >> M >> K;
		
		// reseting it all
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= M; j++)
            {
                mark[i][j] = false;
                for(int k = 0; k <= K; k++)
                    dp[i][j][k][0] = dp[i][j][k][1] = -1;
            }
        }

        // reading matrix
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= M; j++)
                cin >> mt[i][j];
        }

		// dp base 
        dp[1][1][0][1] = dp[1][1][0][0] = mt[1][1];

        DynamicProgramming(N, M);

        int answ = -1;

        for(int i = 0; i <= K; i++)
        {
            int k0 = dp[N][M][i][0];
            int k1 = dp[N][M][i][1];

            answ = max(answ, max(k0, k1));
        }
        // print answer
        cout << answ << "\n";
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
