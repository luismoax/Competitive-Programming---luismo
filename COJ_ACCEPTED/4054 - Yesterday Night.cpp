/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem:
	Online Judge:
	Idea:
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
#define ld long double
// IO
#define sf scanf
#define pf printf
#define endl "\n"
#define x first
#define y second
#define mkp make_pair

using namespace std;

typedef pair<int, int> pii;
const ll infinite = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 50 + 2;

string str;

int arr[lim], tc, N;

int dp[lim][lim];

int cumul[lim][lim];

int query(int a, int b, int c)
{
    if(a > b) return 0;
    if(a == 0) return cumul[b][c];
    return cumul[b][c] - cumul[a-1][c];
}


void reset()
{
    for(int i = 0; i < lim; i++)
        for(int j = 0; j < lim; j++)
            cumul[i][j] = 0;

    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= N; j++)
            dp[i][j] = mod;
    }

}
void solve()
{
    cin >> tc;
    while(tc--)
    {
        cin >> N >> str;

        reset();

        for(int i = 0; i < str.size(); i++)
        {
            arr[i] = (str[i]-'A') + 1;
            cumul[i][arr[i]]++;

            if(i > 0)
            {
                for(int j = 1; j <= 26; j++)
                    cumul[i][j] += cumul[i-1][j];
            }
        }

        int answ = 0;
        // base
        for(int i = 0; i < N; i++)
            dp[i][1] = 0;

        for(int sz = 2; sz <= N; sz++)
        {
            for(int i = 0; i + sz - 1 < N; i++)
            {
                int le = i, ri = i + sz - 1;

                for(int k = le; k <= ri; k++)
                {
                    // if removing k-th
                    int cc = arr[k];

                    int a1 = query(le, k - 1, cc);
                    int a2 = query(k + 1, ri, cc);
                    int a3 = 0;

                    if(k-le > 0)
                        a3 += dp[le][k-le];
                    if(ri-k > 0)
                        a3 += dp[k+1][ri-k];

                    dp[le][sz] = min(dp[le][sz], a1+a2+a3);
                }
            }
        }
        // print answer
        cout << dp[0][N] << endl;
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
