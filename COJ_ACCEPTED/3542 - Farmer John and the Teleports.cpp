/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3542 - Farmer John and the Teleports
	Online Judge: COJ
	Idea: DP2. 
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e2 + 7;

int N, K;

ll adj[lim][lim];

bool visited[lim];

ll dp[lim];

void solve()
{
	cin >> N >> K;
	// reading
	for(int i = 0; i < N - 1; i++)
	{
		ll x; cin >> x;
		adj[i][i + 1] = x;
		adj[i+1][i] = x;
	}

	// reading teles
	for(int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	dp[0] = 0;

	for(int i = 1; i < N; i++)
	{
		ll v = adj[i][i - 1] + dp[i - 1];

		ll aux = 1000000003;
		for(int j = 0; j < i - 1; j++)
		{
			if(adj[i][j] > 0)
			{
				aux = min(aux, dp[j] + 1);
			}
		}

		dp[i] = min(aux, v);
	}

	cout << dp[N - 1] << "\n";
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
		freopen("d:\\lmo.in","r",stdin);

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
