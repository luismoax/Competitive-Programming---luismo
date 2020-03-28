/*
	Author: Luis Manuel Diaz Baron (LUISMO)
	Problem: 3686 - Max of the K
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

const int lim = 1e6 + 3;

int N, K, tc;

int arr[lim];
int rmq[lim][20];

void buildTable()
{
    // base
    for(int i = 0; i < N; i++)
        rmq[i][0] = arr[i];
    // for each possible size
    for(int j = 1; (1 << j) <= N; j++)
    {
        for(int i = 0; i + (1 << j) - 1 < N; i++)
        {
            int k1 = rmq[i][j - 1];
            int k2 = rmq[i + (1 << (j-1))][j - 1];
            rmq[i][j] = max(k1, k2);
        }
    }
}

int query(int i, int j)
{
    if(j < i) swap(i, j);

    int len = log2(j - i + 1);

    int k1 = rmq[i][len];
    int k2 = rmq[j - (1 << len) + 1][len];

    return max(k1, k2);
}

void solve()
{
    cin >> tc;
    while(tc--)
    {
        cin >> N >> K;
        // reading integers
        for(int i = 0; i < N; i++)
            cin >> arr[i];

        // build Table
        buildTable();

        for(int i = 0; i <= N - K; i++)
            if(i == 0)
                cout << query(i, i + K - 1);
            else cout << " " << query(i, i + K - 1);
        if(tc > 0)
			cout << "\n";
    }
}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		//freopen("d:\\lmo.out","w",stdout);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}

	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}
