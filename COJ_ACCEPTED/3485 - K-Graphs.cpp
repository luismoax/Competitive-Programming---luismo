/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3485 - K-Graphs
	Online Judge: COJ
	Idea: My own problem. Nice.
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
const int lim = 2e5 + 7;


int N, K;

void solve()
{
    cin >> N >> K;
    if(K == 1)
    {
        if(N <= 3)
            cout << "NO\n";
        else
        {
            cout << "YES\n4\n";
            cout << "1 2\n";
            cout << "3 2\n";
            cout << "3 4\n";
            cout << "2 4\n";
        }
        return;
    }

    if(N - K < 2)
    {
        cout << "NO\n";
        return;
    }
	cout << "YES\n";
    cout << (K * (K - 1)) / 2 + K << "\n";
    // create Kk (every node adjacent to K-1)
    for(int i = 1; i <= K; i++)
    {
        for(int j = i + 1; j <= K; j++)
            cout << i << " " << j << "\n";
    }

    int mid = K / 2;

    for(int i = 1; i <= K/2; i++)
        cout << i << " " << K + 1 << "\n";

    for(int i = K/2 + 1; i <= K; i++)
        cout << i << " " << K + 2 << "\n";
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		// freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
