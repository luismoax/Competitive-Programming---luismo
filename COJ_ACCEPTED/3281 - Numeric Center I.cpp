/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3281 - Numeric Center I
	Online Judge: COJ
	Idea: Arithmetic with Triangulars + Cumulative Table
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
#define px first
#define py second

using namespace std;

typedef pair<int, int> pii;
const ll infinite = 1e18 + 3;
const int mod = 1e9 + 7;
const int lim = 1e6  + 2;


int N;

set<ll> rbTree;
ll cumul[lim];

void preProcess()
{
    ll sum = 1;
    for(ll i = 2; i <= 1000000; i++)
    {
        ld k = sum+sum+i;

        ld x1 = (-1 + sqrt(1+8*k))/2;

        if(x1 == floor(x1))
        {
            int idx = x1;
            if(idx <= 1000000)
                cumul[idx]++;
        }
        sum+=i;
    }

    for(int i = 1; i <= 1000000; i++)
        cumul[i]+= cumul[i-1];
}

int query(int a, int b)
{
    return cumul[b] - cumul[a-1];
}


void solve()
{
    preProcess();
    while(cin >> N)
    {
        if(N == 0) return;
        cout << cumul[N] << endl;
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
