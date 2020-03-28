/*
	Author: Luis Manuel D?az Bar?n (LUISMO)
	Problem: https://www.spoj.com/problems/NFACTOR/
	Online Judge: SPOJ 
	Idea: Sieve + Cumulative Table
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1e9 + 7;
const int lim = 1e6 + 2;

int sieve[lim];

void buildSieve()
{
    for(int i = 2; i < lim; i+=2)
        sieve[i] = 2;

    for(int i = 3; i < lim; i+= 2)
    {
        if(sieve[i] == 0)
        {
            sieve[i] = i;
            for(int j = i + i; j < lim; j+= i)
                sieve[j] = i;
        }
    }

    // for(int i = 2; i < 60; i++) if(sieve[i]==i) cout << i << endl;
}

int toDecompose(int x)
{
    set<int> rbTree;
    while(x > 1)
    {
        rbTree.insert(sieve[x]);
        x/= sieve[x];
    }
    return rbTree.size();
}

int cumul[11][lim];

int tc, n, a, b;

void solve()
{
    buildSieve();


    cumul[0][1] = 1;
    for(int i = 2; i < lim; i++)
    {
        int k = toDecompose(i);

        cumul[k][i] = 1;
    }


    for(int i = 0; i <= 10; i++)
    {
        for(int j = 1; j < lim; j++)
            cumul[i][j] += cumul[i][j-1];
    }

    cin >> tc;
    while(tc-- > 0)
    {
        cin >> a >> b >> n;
        cout << cumul[n][b] - cumul[n][a-1] << endl;
    }
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/Beijing/lmo.in","r") != NULL)
	{
		freopen("/media/Beijing/lmo.in", "r", stdin);
	}
}

int main()
{
	IO();

	fastIO();

	solve();
}
